/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:21:25 by lchety            #+#    #+#             */
/*   Updated: 2017/11/30 17:50:20 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_op(t_op *op)
{
	op->active = 0;
	op->code = 0;
	op->ocp = 0;
	op->ar[0] = 0;
	op->ar[1] = 0;
	op->ar[2] = 0;
	op->ar_typ[0] = 0;
	op->ar_typ[1] = 0;
	op->ar_typ[2] = 0;
	op->loadtime = 0;
	op->pos_opcode = 0;
}

int		find_args(t_vm *vm, t_proc *proc, int num, int pos)
{
	unsigned char	type;
	unsigned char	mask;

	type = proc->op.ocp;
	mask = 0xC0;
	mask = mask >> (2 * num);
	type = type & mask;
	type = type >> (6 - 2 * num);
	proc->op.ar_typ[num] = type;

	// if (proc->op->code == 1)
	// 	printf("LIVE OP CODE\n");

	if (type == REG_CODE)
	{
		get_reg(vm, proc, num, pos);
		return(REG_SIZE);
	}
	if (type == DIR_CODE)
	{
		get_dir(vm, proc, num, pos);
		return((op_tab[proc->op.code - 1].direct_size) ? 2 : 4);
	}
	if (type == IND_CODE)
	{
		get_ind(vm, proc, num, pos);
		return (IND_SIZE);
	}
	return (0);
}

void		create_op(t_proc *proc, char data)
{
	int		i;

	i = 0;
	if (!is_opcode(data))
		return ;
	init_op(&proc->op);
	proc->op.active = 1;
	proc->op.code = data;
	proc->op.loadtime = op_tab[data - 1].loadtime - 1;
	proc->op.pos_opcode = proc->pc;
}

int		fill_cur_op(t_vm *vm, t_proc *proc)
{
	int			i;
	int			pos;
	t_optab		*optab_ref;

	i = 0;
	pos = proc->pc;
	optab_ref = &op_tab[proc->op.code - 1];
	if (optab_ref->need_ocp)
	{
		pos++;
		proc->op.ocp = (unsigned char)vm->ram[pos % MEM_SIZE].mem;
		if (check_ocp(proc->op.ocp, proc->op.code))
		{
			while (i < op_tab[proc->op.code - 1].nb_arg)
			{
				pos += find_args(vm, proc, i, pos);
				i++;
			}
		}
		else
			return (0);
	}
	else
		get_dir(vm, proc, 0, pos);
	return (1);
}
