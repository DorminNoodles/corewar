/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:57:54 by lchety            #+#    #+#             */
/*   Updated: 2017/11/23 11:59:16 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_vm *vm, t_proc *proc)
{
	int		sum;

	if (!check_params(proc->op))
		return ;

	if (proc->op->ar[0] < 1 || proc->op->ar[0] > 16)
		return ;
	if (proc->op->ar[1] < 1 || proc->op->ar[1] > 16)
		return ;
	if (proc->op->ar[2] < 1 || proc->op->ar[2] > 16)
		return ;

	sum = proc->reg[proc->op->ar[0]] + proc->reg[proc->op->ar[1]];
	proc->reg[proc->op->ar[2]] = sum;
	proc->carry = (sum == 0) ? 1 : 0;

	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		ft_printf("\n");
	}
}
