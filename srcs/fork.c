/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:54:42 by lchety            #+#    #+#             */
/*   Updated: 2017/10/01 13:09:06 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void registre_cpy(t_proc *proc, t_proc *new)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = proc->reg[i];
		// printf("%d", proc->reg[i]);
		i++;
	}

}

void	ft_fork(t_vm *vm, t_proc *proc)
{
	if (!vm->ncurses)
		printf(">>>>>>>ENTER FORK<<<<<<<<<<  : Cycle > %d  : Pos > %d  : Proc > %d\n", vm->cycle, proc->op->pos_opcode, proc->id);

	t_proc	*new;
	new = create_process(vm, proc->num);
	// printf("create_process id => %x\n", proc->num);

	// printf("pos opcode -> %d\n", proc->op->pos_opcode);
	new->pc = proc->op->pos_opcode + (proc->op->ar[0] % IDX_MOD);

	// if (!proc->op->ar[0])
	// 	new->pc = proc->op->pos_opcode;
	// new->pc -= 26;
	new->active = 1;
	registre_cpy(proc, new);
	add_process(vm, new);
}
