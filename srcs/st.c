/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/24 17:48:32 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{

	if (proc->op->ar[1] == T_REG)
		proc->op->ar[1] = proc->reg[proc->op->ar[1]];

		// printf("ST MEM %d \n", proc->op->ar[0]);
		// printf("ST POS %d \n", (proc->op->pos_opcode + proc->op->ar[1]));

		vm->mem[(proc->op->pos_opcode + proc->op->ar[1]) % MEM_SIZE] = proc->op->ar[0];



}
