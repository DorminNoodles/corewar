/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 09:43:12 by lchety            #+#    #+#             */
/*   Updated: 2017/12/02 20:15:35 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc)
{
  int reg;
  if (!check_params(&proc->op))
    return ;
  reg = proc->op.ar[0];
  ft_printf("Code = %d\n", reg, proc->reg[reg] % 256);
  if (0x04 & vm->verbosity)
  {
    show_operations(proc);
    ft_printf("\n");
  }
}
