/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/09/09 12:01:03 by lchety           ###   ########.fr       */
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
		addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD)) % MEM_SIZE;
		vm->mem[addr] = proc->reg[proc->op->ar[0] - 1] >> 24;
		vm->mem[addr + 1] = proc->reg[proc->op->ar[0] - 1] >> 16;
		vm->mem[addr + 2] = proc->reg[proc->op->ar[0] - 1] >> 8;
		vm->mem[addr + 3] = proc->reg[proc->op->ar[0] - 1];
	}
	proc->carry = (proc->op->ar[0] == 0) ? 1 : 0;
}


//(PC + (42 % IDX_MOD)
