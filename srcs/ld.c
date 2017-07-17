/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/07/17 21:30:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_inst *op, int player)
{
	printf(">>>>ENTER LD<<<<\n");

	t_bag *bag;

	bag = &vm->p_bag[player];
	printf("reg => %d\n", op->ar2);
	bag->reg[op->ar2] = op->ar1;
}
