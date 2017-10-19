/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:25 by lchety            #+#    #+#             */
/*   Updated: 2017/10/20 00:01:56 by lchety           ###   ########.fr       */
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

int		all_died(t_vm *vm)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	if (vm->cycle == vm->next_ctd)
	{
		reduce_ctd(vm);
		vm->next_ctd += vm->ctd;
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
