/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/24 16:52:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	unsigned int	addr;

	if (!check_params(proc->op))
		return ;
	if (proc->op->ar_typ[1] == REG_CODE)
	{
		if (proc->op->ar[1] >= 1 && proc->op->ar[1] <= 16)
			proc->reg[proc->op->ar[1]] = proc->reg[proc->op->ar[0]];
	}
	else
	{
		addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD));

		addr = modulo(addr, MEM_SIZE);

		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 24;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 16;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;


		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 8;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;


		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]];
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;
	}

	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		ft_printf("\n");
	}
}

//(PC + (42 % IDX_MOD)
