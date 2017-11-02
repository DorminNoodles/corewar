/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/11/02 00:58:46 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	asm_error(int err, char *str, int line, int column)
{
	if (err == SOURCE_ERR)
		ft_printf("Can't read source file %s\n", str);
	else if (err == MALLOC_ERR)
		ft_printf("Error: malloc failed\n");
	else if (err == FILE_ERROR)
		ft_printf("Error: '%s' is not a .s file\n", str);
	else if (err == INST_ERROR)
		ft_printf("Error: line %d, instruction '%s' does not exist\n", line, str);
	else if (err == LEX_ERROR)
		ft_printf("Error: Lexical error at [%d:%d]\n", line, column);
	else if (err == 0)
		ft_printf("ERREUR : todo\n");
	exit (EXIT_FAILURE);
}
