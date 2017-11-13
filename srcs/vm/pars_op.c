/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:21:25 by lchety            #+#    #+#             */
/*   Updated: 2017/11/13 11:18:17 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_op(t_op *op)
{
	op->ar[0] = 0;
	op->ar[1] = 0;
	op->ar[2] = 0;
	op->ar_typ[0] = 0;
	op->ar_typ[1] = 0;
	op->ar_typ[2] = 0;
}

t_op		*create_op(t_vm *vm, t_proc *proc, char data)
{
	int		i;
	t_op	*op;

	i = 0;
	op = NULL;
	if (!is_opcode(data))
		return (NULL);
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		error("error : malloc\n");
	init_op(op);
	op->code = data;
	op->loadtime = op_tab[data - 1].loadtime - 1;
	op->pos_opcode = proc->pc;
	// printf("create_op  name : %s   delay : %d\n", op_tab[data - 1].name, op_tab[data - 1].loadtime);
	return (op);
}

int		fill_cur_op(t_vm *vm, t_proc *proc)
{
	int i;
	t_optab *optab_ref;

	i = 0;
	optab_ref = &op_tab[proc->op->code - 1];
	if (optab_ref->need_ocp)
	{
		get_ocp(vm, proc);
		if (check_ocp(proc->op->ocp, proc->op->code))
		{
			while (i < op_tab[proc->op->code - 1].nb_arg)
			{
				find_args(vm, proc, i);
				i++;
			}
		}
		else
			return (0);
	}
	else
		get_dir(vm, proc, 0);
	proc->pc++;
	return (1);
}
