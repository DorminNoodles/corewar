/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:25 by lchety            #+#    #+#             */
/*   Updated: 2017/09/23 17:41:46 by lchety           ###   ########.fr       */
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

int		all_died(t_vm *vm)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;

	if (cycle_to_die(vm))
	{
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
