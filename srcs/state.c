/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:41:41 by lchety            #+#    #+#             */
/*   Updated: 2017/09/26 23:47:52 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	idle_state(t_vm *vm, t_proc *proc)
{
	// printf("IDLE %d\n", vm->countdown);

	// printf("------------IDLE_STATE------------\n");
	// printf("SEGV_1\n");
	// printf("proc->pc = %d\n", proc->pc);

	if ((proc->op = create_op(vm, proc, vm->ram[proc->pc % MEM_SIZE].mem)))
	{
		proc->state = WAIT;
	}
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;

}

void	wait_state(t_vm *vm, t_proc *proc)
{
	// printf("------------WAIT_STATE------------\n");
	proc->op->loadtime--;

	if (proc->op->loadtime <= 0)
	{
		fill_cur_op(vm, proc);
		if (op_tab[proc->op->code - 1].func != NULL)
			op_tab[proc->op->code - 1].func(vm, proc);
		proc->state = IDLE;
	}
}
