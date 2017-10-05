/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:25 by lchety            #+#    #+#             */
/*   Updated: 2017/10/05 14:45:08 by lchety           ###   ########.fr       */
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
		tmp->live = 0;
		tmp = tmp->next;
	}
}

int		total_lives(t_vm *vm)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < vm->nb_player)
	{
		sum += vm->player[i].life_signal;
		i++;
	}
	return (sum);
}

void	reduce_ctd(t_vm *vm)
{

	if (total_lives(vm) >= NBR_LIVE || vm->ctd_check == MAX_CHECKS)
	{
		vm->ctd -= CYCLE_DELTA;
		vm->ctd_check = 0;
	}
	else
		vm->ctd_check++;
}

int		all_died(t_vm *vm)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;

	if (cycle_to_die(vm))
	{
		reduce_ctd(vm);
		// vm->ctd -= CYCLE_DELTA;
		undertaker(vm);
		vm->last_one = get_survivor(vm);
		reset_life_signal(vm);
		while (i <= MAX_PLAYERS && cnt == 0)
		{
			if (vm->player[i].active)
				cnt++;
			i++;
		}
		if (!cnt)
			return (1);
	}
	return (0);
}
