/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:09:37 by lchety            #+#    #+#             */
/*   Updated: 2017/11/29 10:18:40 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_winner(t_vm *vm)
{
	int i;
	int best;

	i = 1;
	best = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			if (vm->player[i].last_live > vm->player[best].last_live)
				best = i;
		}
		i++;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", best, vm->player[best].name);
}
