/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:03:11 by lchety            #+#    #+#             */
/*   Updated: 2017/11/20 15:46:45 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	// printf(">>>>>ENTER_LIVE<<<<<\n");
	int		num;
	char	*name;
	vm->lives_in_cycle++;
	proc->last_live = vm->cycle + 1;

	num = 0;

	num = proc->op->ar[0] * -1;

	if (4 & vm->verbosity)
	{
		show_operations(vm, proc);
		printf("\n");
	}
	if (num >= 1 && num <= vm->nb_player)
	{
		vm->player[num].life_signal++;
		vm->player[num].last_live = vm->cycle;
		vm->ram[modulo(proc->op->pos_opcode, MEM_SIZE)].live = BLING_LIVE;
		if (5 & vm->verbosity)
			printf("Player %d (%s) is said to be alive\n", num, vm->files_name[num]);
	}
}
