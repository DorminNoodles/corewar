/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:20:16 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/30 17:47:12 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ldi(t_vm *vm, t_proc *proc)
{
	unsigned int		addr;
	unsigned int value;

	value = 0x0;
	addr = 0;

	if (!check_params(&proc->op))
		return ;

	if (proc->op.ar_typ[0] == REG_CODE)
	{
		proc->op.ar[0] = proc->reg[proc->op.ar[0]];
		proc->op.ar_typ[0] = DIR_CODE;
	}
	// if (proc->op->ar_typ[1] == REG_CODE && !check_reg(proc->op->ar[1]))
	// 	return ;
	if (proc->op.ar_typ[1] == REG_CODE)
	{
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
		proc->op.ar_typ[1] = DIR_CODE;
	}

	// ft_printf("addr %d\n", proc->op->ar[0] + proc->op->ar[1]);

	addr = (proc->op.ar[0] + proc->op.ar[1]) % IDX_MOD;
	// ft_printf("addr > %d\n", addr);
	addr = addr + proc->op.pos_opcode;

	value |= (unsigned char)vm->ram[modulo(addr, MEM_SIZE)].mem;
	value = value << 8;
	// ft_printf(">>> %x\n", (unsigned char)vm->ram[modulo(addr, MEM_SIZE)].mem);
	value |= (unsigned char)vm->ram[modulo(addr + 1, MEM_SIZE)].mem;
	value = value << 8;
	// ft_printf(">>> %x\n", (unsigned char)vm->ram[modulo(addr + 1, MEM_SIZE)].mem);
	value |= (unsigned char)vm->ram[modulo(addr + 2, MEM_SIZE)].mem;
	value = value << 8;
	// ft_printf(">>> %x\n", (unsigned char)vm->ram[modulo(addr + 2, MEM_SIZE)].mem);
	value |= (unsigned char)vm->ram[modulo(addr + 3, MEM_SIZE)].mem;
	// ft_printf(">>> %x\n", (unsigned char)vm->ram[modulo(addr + 3, MEM_SIZE)].mem);

	if (proc->op.ar_typ[2] == REG_CODE && !check_reg(proc->op.ar[2]))
		return ;
	proc->reg[proc->op.ar[2]] = value;

	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n| -> load from %d + %d = %d (with pc and mod %d)", proc->op.ar[0], proc->op.ar[1], proc->op.ar[0] + proc->op.ar[1], addr);
		ft_printf("\n");
	}
}
