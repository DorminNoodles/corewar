/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 03:46:05 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	asm_error(int err, char *str)
{
	if (err == SOURCE_ERR)
		ft_printf("Can't read source file %s\n", str);
	else if (err == MALLOC_ERR)
		ft_printf("Error: malloc failed\n");
	exit (EXIT_FAILURE);
}

void	line_error(char *line, int nb)
{
	printf("line = %s\n", line);
}
