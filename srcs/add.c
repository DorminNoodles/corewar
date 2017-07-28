/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:57:54 by lchety            #+#    #+#             */
/*   Updated: 2017/07/28 04:11:06 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_vm *vm, t_proc *proc)
{
	printf(">>>>ENTER_ADD<<<<\n");
	int		sum;

	sum = proc->reg[proc->op->ar[0] -1] + proc->reg[proc->op->ar[1] -1];
	proc->reg[proc->op->ar[2] -1] = sum;
	proc->carry = (sum == 0) ? 1 : 0;
}
