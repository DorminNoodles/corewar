/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:20:16 by mlambert          #+#    #+#             */
/*   Updated: 2017/10/11 17:26:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ldi(t_vm *vm, t_proc *proc)
{
	if (!vm->ncurses)
		printf(">>>>>>ENTER LDI<<<<<<\n");
	unsigned int		addr;
	unsigned int		reg_nb;
	int ar1;
	int ar2;


	printf("here ->%d\n", proc->reg[1]);
	printf(">>>  %d\n", proc->op->ar_typ[0]);

	if (proc->op->ar_typ[0])
	{
		printf("reg %d\n", proc->op->ar_typ[0]);
		ar1 = proc->reg[proc->op->ar[0]];
		printf("reg %d\n", proc->reg[0]);

	}
	else
	{

	}












	//
	//
	// addr = proc->op->ar[0];
	// reg_nb = proc->op->ar[2] - 1;
	// if (proc->op->ar_typ[0] == REG_CODE)
	// 	addr = proc->reg[proc->op->ar[0] - 1];
	// if (proc->op->ar_typ[1] == REG_CODE)
	// 	addr += proc->reg[proc->op->ar[1] - 1];
	// else
	// 	addr += proc->op->ar[1];
	// proc->reg[reg_nb] = 0;
	// proc->reg[reg_nb] |= vm->mem[addr];
	// proc->reg[reg_nb] <<= 8;
	// proc->reg[reg_nb] |= vm->mem[addr + 1];
	// proc->reg[reg_nb] <<= 8;
	// proc->reg[reg_nb] |= vm->mem[addr + 2];
	// proc->reg[reg_nb] <<= 8;
	// proc->reg[reg_nb] |= vm->mem[addr + 3];
	// proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;
	/*proc->carry = 0;
	if (proc->reg[reg_nb] == 0)
		proc->carry = 1;*/
}
