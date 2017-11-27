/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/11/27 20:27:46 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void	get_dir(t_vm *vm, t_proc *proc, int num, int pos)
{
	unsigned int value;
	value = 0x0;
	value = (unsigned char)vm->ram[(pos + 1) % MEM_SIZE].mem;
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 2) % MEM_SIZE].mem;
	if (op_tab[proc->op.code - 1].direct_size)
	{
		if ((value & 0x8000) == 0x8000)
			value = (value - USHRT_MAX) - 1;
		proc->op.ar[num] = value;
		return ;
	}
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 3) % MEM_SIZE].mem;
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 4) % MEM_SIZE].mem;
	proc->op.ar[num] = value;
}

void	get_reg(t_vm *vm, t_proc *proc, int num, int pos)
{
	unsigned char value;

	value = (unsigned char)vm->ram[(pos + REG_SIZE) % MEM_SIZE].mem;
	proc->op.ar[num] = value;
}

void	get_ind(t_vm *vm, t_proc *proc, int num, int pos)
{

	unsigned int value;
	int i;

	i = 0;
	value = 0;

	i++;
	value = value | (unsigned char)vm->ram[(pos + 1) % MEM_SIZE].mem;
	i++;
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 2) % MEM_SIZE].mem;
	proc->op.ar[num] = value;
	if ((value & 0x8000) == 0x8000)
	 	proc->op.ar[num] = (value - USHRT_MAX) - 1;
}

int		is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (1);
	return (0);
}

t_player	*get_survivor(t_vm *vm)
{
	int i;

	i  = 1;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
			return (&vm->player[i]);
		i++;
	}
	return (vm->last_one);
}

int		count_octet(int octet, t_optab *ref)
{
	if (octet == 1)
		return (REG_SIZE);
	else if (octet == 2)
		return ((ref->direct_size) ? 2 : 4);
	else if (octet == 3)
		return (IND_SIZE);
	return (0);
}

int		move_pc(t_proc *proc)
{
	int		i;
	int		move;
	t_optab	*ref;

	i = 0;
	move = 1;
	ref = &op_tab[proc->op.code - 1];
	if (!ref->need_ocp)
		return ((ref->direct_size) ? move + 2 : move + 4);
	else
		move++;
	if (ref->nb_arg >= 1)
		move += count_octet((0xC0 & proc->op.ocp) >> 6, ref);
	if (ref->nb_arg >= 2)
		move += count_octet((0x30 & proc->op.ocp) >> 4, ref);
	if (ref->nb_arg >= 3)
		move += count_octet((0xC & proc->op.ocp) >> 2, ref);
	return (move);
}

void		delete_op(t_proc *proc)
{
	proc->op.code = 0;
	proc->op.ocp = 0;
	ft_bzero(proc->op.ar, 3);
	ft_bzero(proc->op.ar_typ, 3);
	proc->op.loadtime = 0;
	proc->op.pos_opcode = 0;
	proc->op.active = 0;
}

void	animate_proc(t_vm *vm, t_proc *proc)
{
	if (!proc->op.active)
	{
		if (is_opcode(vm->ram[proc->pc % MEM_SIZE].mem))
			create_op(vm, proc, vm->ram[proc->pc % MEM_SIZE].mem);
		else
			proc->pc = (proc->pc + 1) % MEM_SIZE;
	}
	else
	{
		proc->op.loadtime--;
		if (proc->op.loadtime <= 0)
		{
			if(fill_cur_op(vm, proc))
				op_tab[proc->op.code - 1].func(vm, proc);
			if (proc->op.code != 9 ||
				(proc->op.code == 9 && !proc->carry))
				proc->pc += move_pc(proc);

			if (16 & vm->verbosity)
				show_pc_move(vm, proc);
			delete_op(proc);
		}
	}
}

int		count_proc(t_vm *vm)
{
	int i;
	t_proc	*proc;

	i = 0;
	proc = vm->proc;
	while (proc)
	{
		if (proc->active)
			i++;
		proc = proc->next;
	}
	return (i);
}

void	dump(t_vm *vm)
{
	if (!(vm->cycle % vm->dump))
		show_mem(vm);
}

void reset_live(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= vm->nb_player)
	{
		ft_printf("tot = %d\n", vm->player[i].tot);
		vm->player[i].last_period = vm->player[i].tot;
		vm->player[i].life_signal = 0;
		++i;
	}
}

void	run(t_vm *vm)
{
	t_proc	*proc;
	while (process_living(vm))
	{
		if (!(vm->cycle % CYCLE_TO_DIE))
			reset_live(vm);
		if (2 & vm->verbosity)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		if (vm->ncurses)
		{
			call_ncurses(vm);
			controller(vm);
			usleep(vm->delay);
		}
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->active)
			{
				animate_proc(vm, proc);
			}
			proc->last_pc = proc->pc;
			proc = proc->next;
		}
		vm->cycle++;
		if (vm->dump != -1 && !vm->ncurses)
			dump(vm);
	}
	if (vm->last_one)
		ft_printf("Last_one => %s\n", vm->last_one->file_name);
}

int		modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}

void	get_winner(t_vm *vm)
{
	int i;
	int best;


	i = 1;
	best = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			if (vm->player[i].last_live > vm->player[best].last_live)
				best = i;
		}
		i++;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", best, vm->player[best].name);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	WINDOW *w;//ncurses

	init_vm(&vm);
	if(check_arg(&vm, argc, argv))//check des parametres
		error("Error\n");
	if (vm.ncurses)
		init_ncurses(&w);
	create_players(&vm);//initialisation de la machine virtuelle

	run(&vm);//lancement du combat
	if (vm.ncurses)
		endwin();
	get_winner(&vm);
	free_everything(&vm);
	return (0);
}
