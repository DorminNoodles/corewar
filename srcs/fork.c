/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:54:42 by lchety            #+#    #+#             */
/*   Updated: 2017/10/14 20:43:40 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void registre_cpy(t_proc *proc, t_proc *new)
{
	int i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}

}

static void	clone_proc(t_proc *proc, t_proc *new)
{
	registre_cpy(proc, new);
	new->carry = proc->carry;
	new->live = proc->live;
}

void	ft_fork(t_vm *vm, t_proc *proc)
{
	if (!vm->ncurses && vm->debug)
		printf(">>>>>>>ENTER FORK<<<<<<<<<<  : Cycle > %d  : Pos > %d  : Proc > %d\n", vm->cycle, proc->op->pos_opcode, proc->id);

	t_proc	*new;
	new = create_process(vm, proc->num);

	new->pc = modulo(proc->op->pos_opcode + (proc->op->ar[0] % IDX_MOD), MEM_SIZE);
	clone_proc(proc, new);
	add_process(vm, new);
}
