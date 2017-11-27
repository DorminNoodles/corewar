/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:12:14 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/27 11:53:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_indirect(t_vm *vm, t_op *op, int nb_arg)
{
	int	value;
	int	pos;

	value = 0x0;
	pos = op->pos_opcode + (op->ar[nb_arg] % IDX_MOD);
	// printf("POS LDI %d\n", pos);
	value |= (unsigned char)vm->ram[modulo(pos, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 1, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 2, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 3, MEM_SIZE)].mem;

	return (value);
}

void	xor(t_vm *vm, t_proc *proc)
{
	// unsigned int	ar1;
	// unsigned int	ar2;

	if (!check_params(&proc->op))
		return ;
	// printf("fuck %d\n", proc->op.ar_typ[0]);
	if (proc->op.ar_typ[0] == REG_CODE)
	{
		proc->op.ar[0] = proc->reg[proc->op.ar[0]];
		proc->op.ar_typ[0] = DIR_CODE;
	}
	else if (proc->op.ar_typ[0] == IND_CODE)
		proc->op.ar[0] = get_indirect(vm, &proc->op, 0);

	if (proc->op.ar_typ[1] == REG_CODE)
	{
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
		proc->op.ar_typ[1] = DIR_CODE;
	}
	else if (proc->op.ar_typ[1] == IND_CODE)
		proc->op.ar[1] = get_indirect(vm, &proc->op, 1);

	proc->reg[proc->op.ar[2]] = proc->op.ar[0] ^ proc->op.ar[1];
	proc->carry = (proc->reg[proc->op.ar[2]] == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		ft_printf("\n");
	}
}
