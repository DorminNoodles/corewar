/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/24 16:12:48 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{

	if (proc->op->ar[1] == T_REG)
		proc->op->ar[1] = proc->reg[proc->op->ar[1]];

	vm->mem[(proc->pos_opcode + proc->op->ar[1]) % 8] = proc->op->ar[0];



	// 	proc->reg[proc->op->ar[1]] = proc->reg[proc->op->ar[0];
	// else
	// 	vm->mem[proc->pos_opcode + (proc->op->ar[1] % MEM_S)]
	//


}
