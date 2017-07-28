/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/07/28 04:04:02 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	printf(">>>>ENTER LD<<<<\n");
	int		reg_nb;

	reg_nb = proc->op->ar[1] - 1;
	if (proc->op->ar_typ[0] == IND_CODE)
	{
		proc->reg[reg_nb] = 0;
		proc->reg[reg_nb] = vm->mem[proc->op->ar[0]];
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->mem[proc->op->ar[0] + 1];
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->mem[proc->op->ar[0] + 2];
		proc->reg[reg_nb] <<= 8;
		proc->reg[reg_nb] |= vm->mem[proc->op->ar[0] + 3];
	//	printf("REG ==> %x\n", proc->reg[reg_nb]);
	//	printf("REG => %d\n", proc->reg[reg_nb]);
	//	printf("REGISTRE DE MERDE %d\n", reg_nb);
	}
	else
		proc->reg[reg_nb] = proc->op->ar[0];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;
	/*proc->carry = 0;
	if (proc->reg[reg_nb] == 0)
		proc->carry = 1*/
}
