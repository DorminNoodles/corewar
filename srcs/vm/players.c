/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:25 by lchety            #+#    #+#             */
/*   Updated: 2017/12/01 12:01:10 by lchety           ###   ########.fr       */
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

void	new_player(t_vm *vm, int nb, char *str)
{
	vm->player[nb].active = 1;
	vm->player[nb].last_live = 0;
	vm->player[nb].life_signal = 0;
	vm->player[nb].last_period = 0;
	vm->player[nb].tot = 0;
	vm->player[nb].file_name = str;
}
