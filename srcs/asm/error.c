/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/11/02 15:17:08 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	asm_error(int err, char *str, int line, int column)
{
	++column;
	if (err == SOURCE_ERR)
		ft_printf("Error: Can't read source file '%s'.\n", str);
	else if (err == MALLOC_ERR)
		ft_printf("Error: Malloc failed.\n");
	else if (err == FILE_ERROR)
		ft_printf("Error: '%s' is not a .s file.\n", str);
	else if (err == INST_ERROR)
		ft_printf("Error: At [%d:%d], instruction '%s' does not exist.\n", line, column, str);
	else if (err == LEX_ERROR)
		ft_printf("Error: Lexical error at [%d:%d]. Waiting for a ',' between instructions.\n", line, column - 1);
	else if (err == BAD_ARG_DIR)
		ft_printf("Error: At [%d:%d], instruction waiting a direct number.\n", line, column);
	else if (err == BAD_ARG_REG)
		ft_printf("Error: At [%d:%d], instruction waiting a register.\n", line, column, str);
	else if (err == BAD_ARG_IND)
		ft_printf("Error: At [%d:%d], instruction waiting an index.\n", line, column);
	else if (err == BAD_ARG_REG_DIR)
		ft_printf("Error: At [%d:%d], instruction waiting a direct number or a register.\n", line, column);
	else if (err == BAD_ARG_REG_IND)
		ft_printf("Error: At [%d:%d], instruction waiting a register or an index.\n", line, column);
	else if (err == BAD_ARG_IND_DIR)
		ft_printf("Error: At [%d:%d], instruction waiting an index or a direct number.\n", line, column);
	else if (err == BAD_ARG_REG_DIR_IND)
		ft_printf("Error: At [%d:%d], instruction waiting a register, a direct number or an index.\n", line, column);
	else if (err == LABEL_ERROR)
		ft_printf("Error: Label '%s' is not find.\n", str);
	else if (err == TOO_MUCH_ARG_ERR)
		ft_printf("Error: Too much arguments at [%d:%d] : '%s'.\n", line, column, str);
	exit (EXIT_FAILURE);
}
