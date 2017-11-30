/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:20:16 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/30 17:47:23 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lldi(t_vm *vm, t_proc *proc)
{
	unsigned int		addr;
	int value;

	value = 0x0;
	addr = 0;

	if (!check_params(&proc->op))
		return ;

	if (proc->op.ar_typ[0] == REG_CODE)
	{
		proc->op.ar[0] = proc->reg[proc->op.ar[0]];
	}
	else if (proc->op.ar_typ[0] == IND_CODE)// IND CODE
	{
		proc->op.ar[0] = get_indirect(vm, &proc->op, 0);
	}

	if (proc->op.ar_typ[1] == REG_CODE && !check_reg(proc->op.ar[1]))
		return ;
	if (proc->op.ar_typ[1] == REG_CODE)
	{
		// printf("reg %d\n", proc->op->ar[1]);
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
	}

	addr = (proc->op.ar[0] + proc->op.ar[1]);
	addr = addr + proc->op.pos_opcode;

	value |= (unsigned char)vm->ram[modulo(addr, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 1, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 2, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(addr + 3, MEM_SIZE)].mem;

	if (proc->op.ar_typ[2] == REG_CODE && !check_reg(proc->op.ar[2]))
		return ;
	if (check_reg(proc->op.ar[2]))
		proc->reg[proc->op.ar[2]] = value;

	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n| -> load from %d + %d = %d (with pc and mod %d)", proc->op.ar[0], proc->op.ar[1], value, addr);
		ft_printf("\n");
	}
}
