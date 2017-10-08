/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:13:38 by lchety            #+#    #+#             */
/*   Updated: 2017/10/08 01:48:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_mem(t_vm *vm)
{
	printf(">>>>>>>>SHOW MEM<<<<<<<<\n");
	printf("Cycle : %d\n", vm->cycle);
	int i;
	i = 0;

	while (i < MEM_SIZE)
	{
		printf("%02x ", (unsigned char)vm->ram[i].mem);
		if (i / 64 != (i + 1) / 64)
			printf("\n");
		i++;
	}
	printf("\n\n");
}

void	show_proc_nb(t_vm *vm)
{
	t_proc *tmp;
	int i;

	i = 0;
	tmp = vm->proc;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	// printf("NB_PROC => %d\n", i);
}

void	debug_display_proc(t_vm *vm)
{
	t_proc *tmp;
	int i;

	i = 0;
	tmp = vm->proc;
	while (tmp)
	{
		move (24 + i, 198);
		printw("Proc n:%d on:%d num:%d pc:%d live:%d", i, tmp->active, tmp->num, tmp->pc, tmp->live);
		tmp = tmp->next;
		i++;
	}


}
