/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:03:11 by lchety            #+#    #+#             */
/*   Updated: 2017/11/17 17:27:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	printf(">>>>>ENTER_LIVE<<<<<\n");
	int		num;

	vm->lives_in_cycle++;
	proc->last_live = vm->cycle + 1;

	num = 0;
	// printf("NUM player => %d\n", proc->op->ar[0]);

	printf("fichtre 1\n");
	if (!vm->ncurses && vm->debug)
	{
		printf("opcode pos : %d\n", proc->op->pos_opcode);
		printf("fuck num %d\n", (int)proc->op->ar[0]);
		printf("fuck num %x\n", (int)proc->op->ar[0]);
	}
	num = proc->op->ar[0] * -1;

	// printf("fuck num %d\n", num);
	if (4 & vm->verbosity)
	{
		show_operations(vm, proc);
		printf("\n");
	}

	printf("fichtre 2\n");
	if (num >= 1 && num <= vm->nb_player)
	{
		printf("printf > %d\n", proc->op->pos_opcode);
		// printf("LIVE HERE ##################################\n");
		vm->player[num].life_signal++;
		vm->player[num].last_live = vm->cycle;
		vm->ram[modulo(proc->op->pos_opcode, MEM_SIZE)].live = BLING_LIVE;
		if (5 & vm->verbosity)
			printf("Player %d (helltrain) is said to be alive\n", num);
	}
	printf("fichtre 3\n");
}
