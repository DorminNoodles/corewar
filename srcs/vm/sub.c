/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:08:30 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/19 12:27:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_vm *vm, t_proc *proc)
{
	int	n;

	if (!check_params(proc->op))
		return ;

	// printf("WHY > %d\n", proc->op->ar[1]);

	n = proc->reg[proc->op->ar[0]] - proc->reg[proc->op->ar[1]];
	proc->reg[proc->op->ar[2]] = n;
	proc->carry = (n == 0) ? 1 : 0;
}
