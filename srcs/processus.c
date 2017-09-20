/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:57:25 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 17:03:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_proc(t_vm *vm)
{
	t_proc *tmp;

	tmp = vm->proc;
	while (tmp)
	{
		if (!tmp->live)
			tmp->active = 0;
		tmp = tmp->next;
	}

}

void	undertaker(t_vm *vm)
{
	int i;
	t_proc	*tmp;

	i = 1;
	tmp = vm->proc;
	while (i <= MAX_PLAYERS)
	{
		if (!vm->player[i].life_signal && vm->player[i].active)
		{
			// printf("Player %d died !\n", i);
			vm->player[i].active = 0;
		}
		i++;
	}
	kill_proc(vm);
}

int		is_pc(t_vm *vm, int nb)
{
	t_proc *tmp;

	tmp = vm->proc;

	while (tmp)
	{
		if (tmp->pc == nb && tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
