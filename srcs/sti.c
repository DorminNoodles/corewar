/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:54:19 by lchety            #+#    #+#             */
/*   Updated: 2017/07/23 19:28:36 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_proc *proc)
{
	printf(">>>>>>ENTER STI<<<<<<\n");

	int addr;
	int reg;

	printf("valeur au registre 1 %d\n", proc->reg[0]);

	addr = proc->op->ar[1] + proc->op->ar[2];
	reg = proc->op->ar[0] - 1;

	printf("CECI EST REG %d\n", reg);

	printf("addr -> %d\n", proc->op->ar[1]);

	//int reg;
	// t_bag *bag;
	//
	// bag = &vm->p_bag[player];
	// addr = op->ar2 + op->ar3;
	// reg = op->ar1;
	//
	// printf("ADDR = %d = %d + %d\n", addr, op->ar2, op->ar3);
	// printf("ADDR = %d\n", addr % MEM_SIZE);
	// printf("Player = %d\n", player);
	// printf("Registre Number = %d\n", op->ar1);
	// printf("Reg = %x\n", bag->reg[reg]);
	//

	vm->mem[(proc->op->pos_opcode + addr) % MEM_SIZE] = proc->reg[reg] >>24;
	vm->mem[(proc->op->pos_opcode + addr + 1) % MEM_SIZE] = proc->reg[reg] >>16;
	vm->mem[(proc->op->pos_opcode + addr + 2) % MEM_SIZE] = proc->reg[reg] >>8;
	vm->mem[(proc->op->pos_opcode + addr + 3) % MEM_SIZE] = proc->reg[reg];


}
