/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:20:16 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/28 04:04:33 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ldi(t_vm *vm, t_proc *proc)
{
	unsigned int		addr;
	unsigned int		reg_nb;

	addr = proc->op->ar[0];
	reg_nb = proc->op->ar[2] - 1;
	if (proc->op->ar_typ[0] == REG_CODE)
		addr = proc->reg[proc->op->ar[0] - 1];
	if (proc->op->ar_typ[1] == REG_CODE)
		addr += proc->reg[proc->op->ar[1] - 1];
	else
		addr += proc->op->ar[1];
	proc->reg[reg_nb] = 0;
	proc->reg[reg_nb] |= vm->mem[addr];
	proc->reg[reg_nb] <<= 8;
	proc->reg[reg_nb] |= vm->mem[addr + 1];
	proc->reg[reg_nb] <<= 8;
	proc->reg[reg_nb] |= vm->mem[addr + 2];
	proc->reg[reg_nb] <<= 8;
	proc->reg[reg_nb] |= vm->mem[addr + 3];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;	
	/*proc->carry = 0;
	if (proc->reg[reg_nb] == 0)
		proc->carry = 1;*/
}
