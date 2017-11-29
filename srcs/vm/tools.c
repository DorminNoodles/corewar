/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:38:24 by lchety            #+#    #+#             */
/*   Updated: 2017/11/29 10:12:14 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_indirect(t_vm *vm, t_op *op, int nb_arg)
{
	int	value;
	int	pos;

	value = 0x0;
	pos = op->pos_opcode + (op->ar[nb_arg] % IDX_MOD);
	value |= (unsigned char)vm->ram[modulo(pos, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 1, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 2, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 3, MEM_SIZE)].mem;
	return (value);
}

int		modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}
