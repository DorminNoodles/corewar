/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:54:19 by lchety            #+#    #+#             */
/*   Updated: 2017/11/30 17:44:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// static int	get_indirect(t_vm *vm, t_op *op, int nb_arg)
// {
// 	int	value;
// 	int	pos;
//
// 	value = 0x0;
// 	pos = op->pos_opcode + (op->ar[nb_arg] % IDX_MOD);
// 	value |= (unsigned char)vm->ram[modulo(pos, MEM_SIZE)].mem;
// 	value = value << 8;
// 	value |= (unsigned char)vm->ram[modulo(pos + 1, MEM_SIZE)].mem;
// 	value = value << 8;
// 	value |= (unsigned char)vm->ram[modulo(pos + 2, MEM_SIZE)].mem;
// 	value = value << 8;
// 	value |= (unsigned char)vm->ram[modulo(pos + 3, MEM_SIZE)].mem;
//
// 	return (value);
// }

void	sti(t_vm *vm, t_proc *proc)
{
	int addr;
	int reg;
	if (!check_params(&proc->op))
		return ;

	reg = proc->op.ar[0];

	if (proc->op.ar_typ[1] == REG_CODE)
	{
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
		proc->op.ar_typ[1] = DIR_CODE;
	}
	else if (proc->op.ar_typ[1] == IND_CODE)
		proc->op.ar[1] = get_indirect(vm, &proc->op, 1);

	if (proc->op.ar_typ[2] == REG_CODE)
	{
		proc->op.ar[2] = proc->reg[proc->op.ar[2]];
		proc->op.ar_typ[2] = DIR_CODE;
	}

	addr = (proc->op.ar[1] + proc->op.ar[2]) % IDX_MOD;
	addr = proc->op.pos_opcode + addr;


	vm->ram[modulo(addr, MEM_SIZE)].mem = proc->reg[reg] >>24;
	vm->ram[modulo(addr, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr, MEM_SIZE)].blingbling = BLING_DELAY;

	vm->ram[modulo(addr + 1, MEM_SIZE)].mem = proc->reg[reg] >>16;
	vm->ram[modulo(addr + 1, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 1, MEM_SIZE)].blingbling = BLING_DELAY;


	vm->ram[modulo(addr + 2, MEM_SIZE)].mem = proc->reg[reg] >>8;
	vm->ram[modulo(addr + 2, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 2, MEM_SIZE)].blingbling = BLING_DELAY;


	vm->ram[modulo(addr + 3, MEM_SIZE)].mem = proc->reg[reg];
	vm->ram[modulo(addr + 3, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 3, MEM_SIZE)].blingbling = BLING_DELAY;

	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n", proc->op.ar[1], proc->op.ar[2], proc->op.ar[1] + proc->op.ar[2], addr);
	}
}
