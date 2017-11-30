/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:45:10 by lchety            #+#    #+#             */
/*   Updated: 2017/11/30 17:41:57 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		arg_available(int ocp_chunk, int opcode, int num_arg)
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1;

	// int ret = ocp_chunk & op_tab[opcode - 1].ocp[num_arg];
	// printf(">>>>>> %d\n", ret);

	if (ocp_chunk & op_tab[opcode - 1].ocp[num_arg])
		return (1);
	return (0);
}

int		check_ocp(int ocp, int opcode)
{
	// printf("CHECK _OCP\n");
	int		nb_arg;

	nb_arg = op_tab[opcode - 1].nb_arg;

	if (nb_arg >= 1 && !arg_available((ocp & 0xC0) >> 6, opcode, 0))
		return (0);
	if (nb_arg >= 2 && !arg_available((ocp & 0x30) >> 4, opcode, 1))
		return (0);
	if (nb_arg >= 3 && !arg_available((ocp & 0xC) >> 2, opcode, 2))
		return (0);

	return (1);
}
