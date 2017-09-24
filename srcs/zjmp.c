/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 21:03:43 by lchety            #+#    #+#             */
/*   Updated: 2017/09/24 15:18:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	printf(">>>>>>ENTER ZJMP<<<<<<\n");

	printf("zjmp pos op => %d\n", proc->op->pos_opcode);
	printf("ZJMP VALUE => %d\n", proc->op->ar[0]);
	if (proc->carry)
	{
		proc->pc = proc->op->pos_opcode + (proc->op->ar[0] % IDX_MOD);
	}


}
