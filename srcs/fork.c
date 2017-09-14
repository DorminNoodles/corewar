/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:54:42 by lchety            #+#    #+#             */
/*   Updated: 2017/09/14 12:00:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_fork(t_vm *vm, t_proc *proc)
{
	// printf(">>>>>>ENTER FORK<<<<<<\n");

	t_proc	*new;

	new = create_process(vm, proc->num);

	// printf("create_process id => %x\n", proc->num);

	new->pc = proc->pc + (proc->op->ar[0] % IDX_MOD);
	new->active = 1;

	add_process(vm, new);



}
