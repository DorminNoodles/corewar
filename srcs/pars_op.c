/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:21:25 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 17:22:06 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	op->code = data;
	op->loadtime = op_tab[data - 1].loadtime;
	op->pos_opcode = proc->pc;
	return (op);
}
