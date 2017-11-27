/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/11/27 11:39:09 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	int		reg_nb;
	int		addr;

	addr = 0;
	reg_nb = proc->op.ar[1];

	if (!check_params(&proc->op))
		return ;
	if (proc->op.ar_typ[0] == IND_CODE)
	{
		addr = proc->op.ar[0] % IDX_MOD;

		proc->reg[reg_nb] = 0;
		proc->reg[reg_nb] = (unsigned char)vm->ram[modulo(proc->op.pos_opcode + addr, MEM_SIZE)].mem;
		// printf("%x     \n", vm->ram[modulo(addr % IDX_MOD, MEM_SIZE)].mem);
		// printf("%x     \n", proc->reg[reg_nb]);
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode + addr + 1, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode + addr + 2, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);


		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode + addr + 3, MEM_SIZE)].mem;
		// printf("%x     \n", proc->reg[reg_nb]);
	}
	else
		proc->reg[reg_nb] = proc->op.ar[0];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;

	proc->op.ar[0] = proc->reg[reg_nb];
	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		ft_printf("\n");
	}

	// printf ("proc->reg[1] : %d\n", proc->reg[1]);

}
