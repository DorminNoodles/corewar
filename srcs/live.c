/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:03:11 by lchety            #+#    #+#             */
/*   Updated: 2017/09/04 14:28:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	printf(">>>>>ENTER_LIVE<<<<<\n");

	if (proc->op->ar[0] >= 1 && proc->op->ar[0] <= vm->nb_player)
		vm->life_signal[proc->op->ar[0] - 1] = 1;
	else
	{
		printf("Live for Unknown Player... \n");
	}
}
