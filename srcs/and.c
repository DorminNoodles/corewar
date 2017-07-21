/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:13:33 by lchety            #+#    #+#             */
/*   Updated: 2017/07/20 11:12:50 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and(t_vm *vm, t_inst *op, int player)
{
	printf(">>>>>>>ENTER_AND<<<<<<<\n");

	// t_bag *bag;
	//
	// bag = &vm->p_bag[player];
	//
	// printf("A = bag->cur_op->ar1 %d\n", bag->cur_op->ar1);
	// printf("A = bag->cur_op->ar2 %d\n", bag->cur_op->ar2);
	//
	// bag->reg[bag->cur_op->ar3] = bag->cur_op->ar1 & bag->cur_op->ar2;
	//
	// printf(">>>>>>>>>RET = %d\n", bag->reg[bag->cur_op->ar3]);
}
