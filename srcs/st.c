/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/09/11 19:42:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	// printf(">>>>>>>ENTER ST<<<<<<<<<<\n");
	unsigned int	addr;

	if (proc->op->ar_typ[1] == REG_CODE)
		proc->reg[proc->op->ar[1] - 1] = proc->reg[proc->op->ar[0] - 1];
	else
	{
		// addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD)) % MEM_SIZE;

		// addr = proc->pc + (proc->op->ar[1]);
		addr = (proc->op->ar[1] + proc->op->pos_opcode) % MEM_SIZE;
		// addr = addr + proc->op->pos_opcode;

		vm->ram[addr].mem = proc->reg[proc->op->ar[0] - 1] >> 24;
		vm->ram[addr].num = proc->num;
		vm->ram[addr + 1].mem = proc->reg[proc->op->ar[0] - 1] >> 16;
		vm->ram[addr + 1].num = proc->num;
		vm->ram[addr + 2].mem = proc->reg[proc->op->ar[0] - 1] >> 8;
		vm->ram[addr + 2].num = proc->num;
		vm->ram[addr + 3].mem = proc->reg[proc->op->ar[0] - 1];
		vm->ram[addr + 3].num = proc->num;
	}
	proc->carry = (proc->op->ar[0] == 0) ? 1 : 0;
}


//(PC + (42 % IDX_MOD)
