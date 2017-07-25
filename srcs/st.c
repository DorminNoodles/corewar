/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/25 19:31:40 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	printf(">>>>>>>ENTER ST<<<<<<<<<<\n");

	unsigned int	addr;

	// printf("ar1 = %d\n", proc->op->ar[1]);
	// printf("AR TYPE -> %d\n", proc->op->ar_typ[1]);
	if (proc->op->ar_typ[1] == REG_CODE)
	{
		printf("enter t_reg\n");
		// proc->op->ar[1] = proc->reg[proc->op->ar[1] - 1];
		proc->reg[proc->op->ar[1] - 1] = proc->reg[proc->op->ar[0] - 1]; 
	}

	printf("ar2 => %d\n", proc->op->ar[1]);

	addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD)) % MEM_SIZE;

	vm->mem[addr] = proc->reg[proc->op->ar[0] - 1];

	//vm->mem[addr] = proc->op->ar[0];

	printf("addresse = %d\n", addr);
	printf("addraddr  %x\n", vm->mem[addr]);
	//printf("value un Register %d\n", proc->reg[proc->op->ar[0] - 1]);

/*	vm->mem[addr] = proc->reg[proc->op->ar[0]] >> 24;
	vm->mem[addr + 1] = proc->reg[proc->op->ar[0]] >> 16;
	vm->mem[addr + 2] = proc->reg[proc->op->ar[0]] >> 8;
	vm->mem[addr + 3] = proc->reg[proc->op->ar[0]];*/
}


//(PC + (42 % IDX_MOD)
