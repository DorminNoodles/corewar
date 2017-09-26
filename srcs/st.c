/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/09/27 00:00:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	// printf(">>>>>>>ENTER ST<<<<<<<<<<\n");
	unsigned int	addr;

	if (proc->op->ar_typ[1] == REG_CODE)
	{
		proc->reg[proc->op->ar[1] - 1] = proc->reg[proc->op->ar[0] - 1];
	}
	else
	{
		// addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD)) % MEM_SIZE;

		// addr = proc->pc + (proc->op->ar[1]);
		// printf("fuck > %d\n", proc->op->pos_opcode);
		// printf("fuck > %d\n", (int)proc->op->ar[1]);
		addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD));

		addr = modulo(addr, MEM_SIZE);

		// addr = addr + proc->op->pos_opcode;

		// printf("ADDR %d\n", addr);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0] - 1] >> 24;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0] - 1] >> 16;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0] - 1] >> 8;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0] - 1];
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;
		// proc->carry = (proc->op->ar[0] == 0) ? 1 : 0;
	}
	proc->carry = (proc->reg[proc->op->ar[0] - 1] == 0) ? 1 : 0;



	if (proc->num == -1)
	{
		// printf("SEGV_1\n");
		// printf(" FFFFFFFFFFFFFF %d\n", proc->carry);
		// move(20, 200);
		// printw("Cycles : %d", vm->countdown);
		// printw("CARRY       au bal du diable %d", proc->carry);
		// printf("SEGV_2\n");
	}
}


//(PC + (42 % IDX_MOD)
