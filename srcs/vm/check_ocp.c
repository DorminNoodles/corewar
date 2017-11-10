/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:45:10 by lchety            #+#    #+#             */
/*   Updated: 2017/11/10 13:05:18 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		convert_code(int ocp, int i)
{
	int value;

	return (0);
}

int		arg_available()
{
	return (1);
}

int		check_ocp(int ocp, int code)
{
	printf("CHECK _OCP\n");
	int i;
	int value[3];

	ft_bzero(value, 3);

	printf ("OCP %d\n", ocp);

	if ((ocp & 0xC0) && arg_available())
		printf("ta mere\n");
	// convert_code(0x70, 0);
	// while (i < op_tab[code].nb_arg)
	// {
		// if (op_tab[code].ocp[i] & convert_ocp(ocp, i))
		// i++;
	// }
}
