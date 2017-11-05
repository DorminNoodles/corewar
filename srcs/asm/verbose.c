/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:44 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/04 19:22:07 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_arg(char *line, int add)
{
	int a;

	a = 0;
	ft_printf("|");
	color(C_BLUE);
	if (add)
		ft_printf("%c", DIRECT_CHAR);
	while (line[a] && !is_space(line[a]) && line[a] != SEPARATOR_CHAR)
	{
		ft_printf("%c", line[a]);
		++a;
	}
	color(C_RESET);
	ft_printf("| ");
}

void	verbose_inst(char *ins)
{
	ft_printf("Instruction:|");
	color(C_CYAN);
	ft_printf("%s", ins);
	color(C_RESET);
	ft_printf("| ");
}

void	verbose_dist_lab(int dist)
{
	ft_printf("(dist is %d bytes)", dist);
}

void	verbose_lab(char *lab, int pos)
{
	ft_printf("label:|");
	color(C_RED);
	write(1, lab, ft_strlen(lab) - 1);
	color(C_RESET);
	ft_printf("| ");
}

void	verbose_ocp(char ocp)
{
	if (ocp)
		ft_printf("Ocp: %hb (%#hhx) ", ocp, ocp);
	else
		ft_printf("No ocp ");
}
