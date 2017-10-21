/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:25 by lchety            #+#    #+#             */
/*   Updated: 2017/10/21 12:54:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reset_life_signal(t_vm *vm)
{
	int		i;
	t_proc	*tmp;

	i = 1;
	tmp = vm->proc;
	while (i <= MAX_PLAYERS)
	{
		vm->player[i].life_signal = 0;
		i++;
	}
	while (tmp)
	{
		tmp->last_live = 0;
		tmp = tmp->next;
	}
}

int		total_lives(t_vm *vm)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i <= vm->nb_player)
	{
		sum += vm->player[i].life_signal;
		i++;
	}
	return (sum);
}

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

// int		process_living(t_vm *vm)
// {
// 	int i;
// 	int cnt;
//
// 	i = 0;
// 	cnt = 0;
// 	if (vm->cycle == vm->next_ctd)
// 	{
// 		reduce_ctd(vm);
// 		vm->next_ctd += vm->ctd;
// 		undertaker(vm);
// 		vm->last_one = get_survivor(vm);
// 		reset_life_signal(vm);
//
// 	}
// 	return (0);
// }

int		process_living(t_vm *vm)
{
	int		i;
	t_proc	*tmp;

	i = 0;

	if (vm->cycle != vm->next_ctd)
		return (1);
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			tmp = vm->player[i].proc;
			while (tmp)
			{
				printf("One proc\n");
				tmp = tmp->next;
			}
		}
	}

}
