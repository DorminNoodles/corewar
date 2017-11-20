/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/11/20 16:21:05 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	int		reg_nb;
	int		addr;

	addr = 0;
	reg_nb = proc->op->ar[1];

	if (!check_params(proc->op))
		return ;
	if (proc->op->ar_typ[0] == IND_CODE)
	{
		addr = proc->op->pos_opcode + proc->op->ar[0];
		proc->reg[reg_nb] = 0;
		proc->reg[reg_nb] = (unsigned char)vm->ram[modulo(addr % IDX_MOD, MEM_SIZE)].mem;
		// printf("%x     \n", vm->ram[modulo(addr % IDX_MOD, MEM_SIZE)].mem);
		// printf("%x     \n", proc->reg[reg_nb]);
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 1) % IDX_MOD, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 2) % IDX_MOD, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 3) % IDX_MOD, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);
	}
	else
		proc->reg[reg_nb] = proc->op->ar[0];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		printf("\n");
	}

}
