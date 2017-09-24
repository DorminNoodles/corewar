/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:03:11 by lchety            #+#    #+#             */
/*   Updated: 2017/09/24 22:42:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	printf(">>>>>ENTER_LIVE<<<<<\n");
	int		num;

	num = 0;
	// printf("NUM player => %d\n", proc->op->ar[0]);

	printf("fuck num %d\n", proc->op->ar[0]);
	num = proc->op->ar[0] * -1;

	printf("fuck num %d\n", num);

	if (num >= 1 && num <= vm->nb_player)
	{
		// printf("LIVE HERE ##################################\n");
		vm->player[num].life_signal++;
		proc->live = 1;
		vm->ram[proc->op->pos_opcode].live = 30;
	}
	else
	{
		// printf("Live for Unknown Player... \n");
	}
}
