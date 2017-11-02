/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 15:03:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int is_reg_or_ind(char *str, int lin, int col)
{
	int reg;
	int ind;

	reg = is_reg(str);
	ind = is_ind(str);
	if (!reg && !ind)
		asm_error(BAD_ARG_REG_IND, str, lin, col);
	return (reg + ind);
}

int is_reg_or_dir(char *str, int lin, int col)
{
	int reg;
	int dir;

	reg = is_reg(str);
	dir = is_dir(str);
	if (!reg && !dir)
		asm_error(BAD_ARG_REG_DIR, str, lin, col);
	return (reg + dir);
}

int is_ind_or_dir(char *str, int lin, int col)
{
	int ind;
	int dir;

	ind = is_ind(str);
	dir = is_dir(str);
	if (!ind && !dir)
		asm_error(BAD_ARG_IND_DIR, str, lin, col);
	return (ind + dir);
}

int is_reg_or_ind_or_dir(char *str, int lin, int col)
{
	int reg;
	int ind;
	int dir;

	reg = is_reg(str);
	ind = is_ind(str);
	dir = is_dir(str);
	if (!ind && !dir && !reg)
		asm_error(BAD_ARG_REG_DIR_IND, str, lin, col);
	return (ind + dir + reg);
}
