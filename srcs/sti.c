/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:54:19 by lchety            #+#    #+#             */
/*   Updated: 2017/10/11 17:13:08 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_proc *proc)
{
	if (!vm->ncurses && vm->debug)
		printf(">>>>>>>ENTER STI<<<<<<<<<<\n  : Cycle > %d\n", vm->cycle);
	int addr;
	int reg;

	addr = (proc->op->ar[1] + proc->op->ar[2]) % IDX_MOD;
	addr = proc->op->pos_opcode + addr;

	if (!vm->ncurses && vm->debug)
		printf(">> %d\n", vm->cycle);



	// addr += proc->op->pos_opcode;
	reg = proc->op->ar[0];

	// printf("Registre %d index %d\n", proc->op->ar[0], reg);

	// printf("addr -> %d\n", proc->op->ar[1]);

	//int reg;
	// t_bag *bag;
	// show_mem(vm);

	// printf("sti > %x\n", proc->reg[reg]);

	vm->ram[modulo(addr, MEM_SIZE)].mem = proc->reg[reg] >>24;
	// printf("%x     \n", proc->reg[reg] >> 24);
	vm->ram[modulo(addr, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr, MEM_SIZE)].blingbling = BLING_DELAY;

	vm->ram[modulo(addr + 1, MEM_SIZE)].mem = proc->reg[reg] >>16;
	// printf("%x     \n", proc->reg[reg] >> 16);
	vm->ram[modulo(addr + 1, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 1, MEM_SIZE)].blingbling = BLING_DELAY;


	vm->ram[modulo(addr + 2, MEM_SIZE)].mem = proc->reg[reg] >>8;
	vm->ram[modulo(addr + 2, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 2, MEM_SIZE)].blingbling = BLING_DELAY;


	vm->ram[modulo(addr + 3, MEM_SIZE)].mem = proc->reg[reg];
	vm->ram[modulo(addr + 3, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 3, MEM_SIZE)].blingbling = BLING_DELAY;

	// show_mem(vm);
}
