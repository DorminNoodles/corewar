/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 00:00:52 by lchety            #+#    #+#             */
/*   Updated: 2017/10/20 00:04:28 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reduce_ctd(t_vm *vm)
{
	// printf("BORDEL  %d\n", total_lives(vm));
	if (total_lives(vm) >= NBR_LIVE || vm->ctd_check == MAX_CHECKS)
	{
		// printf("BORDEL\n");
		vm->ctd -= CYCLE_DELTA;
		vm->ctd_check = 0;
		if (2 & vm->verbosity)
			printf("Cycle to die is now %d\n", vm->ctd);
	}
	else
		vm->ctd_check++;
}
