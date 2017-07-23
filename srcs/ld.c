/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:55:40 by lchety            #+#    #+#             */
/*   Updated: 2017/07/23 12:07:09 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	printf(">>>>ENTER LD<<<<\n");

	proc->reg[proc->op->ar[1]] = proc->op->ar[0];


	// bag->reg[op->ar2] = op->ar1;
	// printf("FUCKING RES DE CETTE PUTE DE FONCTION DE LDreg => %d\n", bag->reg[op->ar2]);
	// printf("HHHHHHHHHHHHHHHHHHHHHH\n");
}
