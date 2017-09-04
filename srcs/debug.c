/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:13:38 by lchety            #+#    #+#             */
/*   Updated: 2017/09/04 22:36:14 by lchety           ###   ########.fr       */
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
		if (i % 65 == 0 && i > 0)
			printf("\n");
		i++;
	}
	printf("\n\n");
}

void	show_mem_2(t_vm *vm)
{
	int i;
	i = 0;

	while (i < MEM_SIZE)
	{
		printf("%02x ", (unsigned char)vm->mem_2[i]);
		if (i % 65 == 0 && i > 0)
			printf("\n");
		i++;
	}
	printf("\n\n");
}
