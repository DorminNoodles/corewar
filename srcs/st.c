/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/24 21:09:35 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	printf("ENTER ST\n");

	int	addr;

	if (proc->op->ar[1] == T_REG)
		proc->op->ar[1] = proc->reg[proc->op->ar[1]];
	addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD)) % MEM_SIZE;
	vm->mem[addr] = proc->reg[proc->op->ar[0] - 1];


	vm->mem[addr] = proc->op->ar[0];

	printf("addraddr  %d\n", vm->mem[addr]);
	printf("value un Register %d\n", proc->reg[proc->op->ar[0] - 1]);

/*	vm->mem[addr] = proc->reg[proc->op->ar[0]] >> 24;
	vm->mem[addr + 1] = proc->reg[proc->op->ar[0]] >> 16;
	vm->mem[addr + 2] = proc->reg[proc->op->ar[0]] >> 8;
	vm->mem[addr + 3] = proc->reg[proc->op->ar[0]];*/
}


//(PC + (42 % IDX_MOD)
