/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:54:19 by lchety            #+#    #+#             */
/*   Updated: 2017/07/17 20:59:30 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_inst *op, int player)
{
	printf(">>>>>>ENTER STI<<<<<<\n");
	int addr;
	int reg;
	t_bag *bag;

	bag = &vm->p_bag[player];
	addr = op->ar2 + op->ar3;
	reg = op->ar1;

	printf("ADDR = %d = %d + %d\n", addr, op->ar2, op->ar3);
	printf("ADDR = %d\n", addr % MEM_SIZE);
	printf("Player = %d\n", player);
	printf("Registre Number = %d\n", op->ar1);
	printf("Reg = %x\n", bag->reg[reg]);

	vm->mem[addr % MEM_SIZE] = bag->reg[reg];
	vm->mem[(addr + 1) % MEM_SIZE] = bag->reg[reg] >>8;
	vm->mem[(addr + 2) % MEM_SIZE] = bag->reg[reg] >>16;
	vm->mem[(addr + 3) % MEM_SIZE] = bag->reg[reg] >>24;
}
