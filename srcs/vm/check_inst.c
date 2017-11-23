/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:43:50 by lchety            #+#    #+#             */
/*   Updated: 2017/11/23 14:30:56 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_reg(int nb)
{
	if (nb < 1 || nb > REG_NUMBER)
		return (0);
	return (1);
}

int		check_params(t_op *op)
{
	int i;

	i = 0;
	while (i < op_tab[op->code].nb_arg)
	{
		if (op->ar_typ[i] == REG_CODE)
		{
			if (!check_reg(op->ar[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
