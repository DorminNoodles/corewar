/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:57:25 by lchety            #+#    #+#             */
/*   Updated: 2017/09/27 01:40:58 by lchety           ###   ########.fr       */
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

t_proc	*create_process(t_vm *vm, int num)
{
	t_proc	*tmp;

	if(!(tmp = (t_proc*)ft_memalloc(sizeof(t_proc))))
		error("error : malloc\n");
	tmp->id = (num * -1) + (-1);
	// printf("NOMBRE => %d\n", num * (-1));
	// printf("NUM > %d\n", num);
	tmp->num = num;
	tmp->pc = (MEM_SIZE / vm->nb_player) * ((num * (-1) -1));
	// printf(">>>> %d   num %d\n", tmp->pc, num);
	tmp->op = NULL;
	tmp->reg = init_registre(num);
	// printf("INIT REG 1 >>> %x\n", num * -1);
	tmp->state = IDLE;
	tmp->carry = 0;
	tmp->live = 1;
	tmp->active = 1;
	return (tmp);
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

	//return (1);
	tmp = vm->proc;
	while (tmp)
	{
		if (tmp->pc == nb && tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
