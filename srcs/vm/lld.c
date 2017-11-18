/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 01:19:08 by lchety            #+#    #+#             */
/*   Updated: 2017/11/18 22:30:12 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld(t_vm *vm, t_proc *proc)
{
	// printf(">>>>ENTER LD<<<<  : Cycle > %d\n", vm->cycle);
	int		reg_nb;
	int		addr;

	addr = 0;
	if (!check_params(proc->op))
		return ;
	reg_nb = proc->op->ar[1];
	if (proc->op->ar_typ[0] == IND_CODE)
	{
		addr = proc->op->pos_opcode + proc->op->ar[0];
		proc->reg[reg_nb] = 0;
		proc->reg[reg_nb] = (unsigned char)vm->ram[modulo(addr, MEM_SIZE)].mem;
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 1), MEM_SIZE)].mem;


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 2), MEM_SIZE)].mem;


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo((addr + 3), MEM_SIZE)].mem;
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
