/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:13:38 by lchety            #+#    #+#             */
/*   Updated: 2017/09/07 16:29:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_mem(t_vm *vm)
{
	int i;
	i = 0;

	while (i < MEM_SIZE)
	{
		printf("%02x ", *((unsigned char*)vm->mem + i));
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
	printf("NB_PROC => %d\n", i);
}
