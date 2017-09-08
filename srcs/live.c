/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:03:11 by lchety            #+#    #+#             */
/*   Updated: 2017/09/08 14:41:56 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	// printf(">>>>>ENTER_LIVE<<<<<\n");
	int		num;

	num = 0;
	// printf("NUM player => %d\n", proc->op->ar[0]);

	num = proc->op->ar[0] * -1;

	if (num >= 1 && num <= vm->nb_player)
		vm->player[num].life_signal++;
	else
	{
		// printf("Live for Unknown Player... \n");
	}
}
