/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_ins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 15:15:55 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_instr_6_7_8(char *str, int lin, int col)
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg_or_ind_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg_or_ind_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(BAD_ARG_REG, str + i, lin, col + i);
	i += arg;
	check_instr_endline(str + i, lin, col + i);
}

void check_instr_10(char *str, int lin, int col)
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg_or_ind_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(BAD_ARG_REG, str + i, lin, col + i);
	i += arg;
	check_instr_endline(str + i, lin, col + i);
}
void check_instr_11(char *str, int lin, int col)
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(BAD_ARG_REG, str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg_or_ind_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg_or_dir(str + i, lin, col + i);
	i += arg;
	check_instr_endline(str + i, lin, col + i);
}
void check_instr_14(char *str, int lin, int col)
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg_or_ind_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg_or_dir(str + i, lin, col + i);
	i += arg;
	i += until_next_arg(str + i, lin, col + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(BAD_ARG_REG, str + i, lin, col + i);
	i += arg;
	check_instr_endline(str + i, lin, col + i);
}
void check_instr_16(char *str, int lin, int col)
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(BAD_ARG_REG, str + i, lin, col + i);
	i += arg;
	check_instr_endline(str + i, lin, col + i);
}
