/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:45:10 by lchety            #+#    #+#             */
/*   Updated: 2017/11/13 14:57:06 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		convert_code(int ocp)
{
	return (0);
}

int		arg_available(int ocp_chunk, int opcode, int num_arg)
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1;

	int ret = ocp_chunk & op_tab[opcode - 1].ocp[num_arg];

	// printf(">>>>>> %d\n", ret);

	if (ocp_chunk & op_tab[opcode - 1].ocp[num_arg])
		return (1);

	// printf("return 0\n");
	return (0);
}

int		check_ocp(int ocp, int opcode)
{
	// printf("CHECK _OCP\n");
	int		i;
	int		nb_arg;

	nb_arg = op_tab[opcode - 1].nb_arg;


	// ft_bzero(value, 3);

	// printf ("OCP %d\n", ocp);
	// printf ("nb_arg > %d\n", nb_arg);

	// int		ocp_chunk = (ocp & 0xC0) >> 6;

	// ocp_chunk = ocp_chunk >> 6;

	// printf ("ocp_chunk   %d\n", ocp_chunk);

	// printf("opcode => %d\n", opcode);
	// printf ("nb_arg %d\n", nb_arg);
	if (nb_arg >= 1 && !arg_available((ocp & 0xC0) >> 6, opcode, 0))
		return (0);
		// printf("BAD OCP\n");

	// if (nb_arg >= 2 && !arg_available((ocp & 0x30) >> 4, opcode))
	// 	return (0);
	// if (nb_arg >= 3 && !arg_available((ocp & 0xC) >> 2, opcode))
	// 	return (0);

	return (1);
}
