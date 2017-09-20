/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 23:05:12 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_ocp(t_vm *vm, t_proc *proc)
{
	// printf("MEM BEFORE   %x\n", (unsigned char)vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].need_ocp)
	{
		proc->pc++;
		proc->op->ocp = vm->mem[proc->pc];
	}
}

void	get_dir(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_DIR<<<<<<<<<<<\n");
	unsigned int value;

	value = 0;

	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf(" hexa dans mem %x\n", vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].direct_size)
	{
		proc->op->ar[num] = value;
		// printf("deux octets value %x\n", value);
		return ;
	}
	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->op->ar[num] = value;
}

void	get_reg(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_REG<<<<<<<<<<<\n");
	unsigned char value;

	proc->pc++;
	value = (unsigned char)vm->mem[proc->pc];

	// printf("reg value %d\n", value);

	proc->op->ar[num] = value;
}

void	get_ind(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_IND<<<<<<<<<<<\n");

	unsigned int value;

	value = 0;

	// printf("FUCK >>>>> %d\n", vm->mem[proc->pc]);
	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf("deux octets value %x\n", value);

	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	proc->op->ar[num] = value;
}

void	find_args(t_vm *vm, t_proc *proc, int num)
{
	// printf("ENTER FUNC : FIND_ARGS\n");
	unsigned char	type;
	unsigned char	mask;

	type = proc->op->ocp;
	// printf("OCP => %d\n", type);
	mask = 0xC0;
	mask = mask >> (2 * num);
	type = type & mask;
	type = type >> (6 - 2 * num);
	proc->op->ar_typ[num] = type;

	if (type == REG_CODE)
		get_reg(vm, proc, num);
	if (type == DIR_CODE)
		get_dir(vm, proc, num);
	if (type == IND_CODE)
		get_ind(vm, proc, num);

	// if (mask )

	// printf("EXIT FUNC : FIND_ARGS\n");
}

t_optab		*get_optab_entry(int code)
{
	return (&op_tab[code - 1]);
}

void	fill_cur_op(t_vm *vm, t_proc *proc)
{
	int i;
	t_optab *optab_ref;

	i = 0;
	// printf("OCP CODE >>>> %d\n", proc->op->code);
	optab_ref = get_optab_entry(proc->op->code);
	if (optab_ref->need_ocp)
	{
		get_ocp(vm, proc);
		while (i < op_tab[proc->op->code - 1].nb_arg)
		{
			find_args(vm, proc, i);
			i++;
		}
	}
	else
	{
		get_dir(vm, proc, 0);
	}

	proc->pc++;
}

int		is_opcode(char data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if ((char)op_tab[i].code == data)
			return (data);
		i++;
	}
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

int		cycle_to_die(t_vm *vm)
{
	if (vm->countdown % vm->ctd == 0 && vm->countdown / vm->ctd > 0)
		return (1);
	return (0);
}

void	animate_proc(t_vm *vm, t_proc *proc)
{
	if (proc->state == IDLE)
		idle_state(vm, proc);
	else if (proc->state == WAIT)
		wait_state(vm, proc);
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

void	run(t_vm *vm)
{
	t_proc	*proc;

	while (!all_died(vm))
	{
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->active)
			{
				animate_proc(vm, proc);
			}
			proc = proc->next;
		}
		vm->countdown++;
//-------------------------Debug

//-------------------------Debug
//-------------------NCURSES
		if (vm->ncurses)
		{
			call_ncurses(vm);
			controller(vm);
			usleep(vm->delay);
		}
//-------------------NCURSES
	}

	printf("END\n");
	if (vm->last_one)
		printf("Last_one => %s\n", vm->last_one->file_name);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	WINDOW *w;//ncurses

	init_vm(&vm);
	if(check_arg(&vm, argc, argv))//check des parametres
		error("Error\n");

	show_mem(&vm);

	if (vm.ncurses)
		init_ncurses(&w);

//-------------Debug
	// printf("Debug : active -> %d\n", vm.player[1].active);
//-------------Debug
	create_players(&vm);//initialisation de la machine virtuelle

	// printf("SEGV\n");
	run(&vm);//lancement du combat

	if (vm.ncurses)
		endwin();
	return (0);
}
