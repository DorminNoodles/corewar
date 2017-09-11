/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/09/11 18:14:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	// printf(">>>>ENTER LD<<<<\n");
	int		reg_nb;

	reg_nb = proc->op->ar[1] - 1;
	if (proc->op->ar_typ[0] == IND_CODE)
	{
		proc->reg[reg_nb] = 0;
		proc->reg[reg_nb] = vm->ram[proc->op->ar[0]].mem;
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->ram[proc->op->ar[0]+ 1].mem;
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->ram[proc->op->ar[0]+ 2].mem;
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->ram[proc->op->ar[0]+ 3].mem;
	//	printf("REG ==> %x\n", proc->reg[reg_nb]);
	//	printf("REG => %d\n", proc->reg[reg_nb]);
	//	printf("REGISTRE DE MERDE %d\n", reg_nb);
	}
	else
		proc->reg[reg_nb] = proc->op->ar[0];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;

	// printf("##LD registre %d == %d\n", proc->op->ar[1], proc->op->ar[0]);
	/*proc->carry = 0;
	if (proc->reg[reg_nb] == 0)
		proc->carry = 1*/
}
