/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/12/04 18:01:10 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					move_pc(t_proc *proc)
{
	int				i;
	int				move;
	t_optab			*ref;

	i = 0;
	move = 1;
	ref = &g_op_tab[proc->op.code - 1];
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

void				animate_proc(t_vm *vm, t_proc *proc)
{
	vm->ram[proc->pc % MEM_SIZE].pc = 0;
	if (!proc->op.active)
	{
		if (is_opcode(vm->ram[proc->pc % MEM_SIZE].mem))
			create_op(proc, vm->ram[proc->pc % MEM_SIZE].mem);
		else
			proc->pc = (proc->pc + 1) % MEM_SIZE;
	}
	else
	{
		proc->op.loadtime--;
		if (proc->op.loadtime <= 0)
		{
			if (fill_cur_op(vm, proc))
				g_op_tab[proc->op.code - 1].func(vm, proc);
			if (proc->op.code != 9 ||
				(proc->op.code == 9 && !proc->carry))
				proc->pc += move_pc(proc);
			if (16 & vm->verbosity)
				show_pc_move(vm, proc);
			delete_op(proc);
		}
	}
	vm->ram[proc->pc % MEM_SIZE].pc = proc->num;
}

int					count_proc(t_vm *vm)
{
	int				i;
	t_proc			*proc;

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

void				run(t_vm *vm)
{
	t_proc			*proc;

	while (process_living(vm))
	{
		if (!((vm->cycle + 1) % vm->ctd))
			reset_live(vm);
		if (2 & vm->verbosity)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		call_ncurses(vm);
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->active)
				animate_proc(vm, proc);
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

int					main(int argc, char **argv)
{
	t_vm			vm;
	t_WINDOW		*w;

	init_vm(&vm);
	if (check_arg(&vm, argc, argv))
		error("Error\n");
	create_players(&vm);
	if (vm.ncurses)
		init_ncurses(&w);
	run(&vm);
	get_winner(&vm);
	if (vm.ncurses)
	{
		vm.pause = 1;
		call_ncurses(&vm);
	}
	if (vm.ncurses)
		endwin();
	ft_printf("Contestant %d, \"%s\", has won !\n", vm.winner,
		vm.player[vm.winner].name);
	free_everything(&vm);
	return (0);
}
