/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_ins1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 01:06:29 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_instr_endline(char *str)
{
	int i;

	i = until_is_not_space(str);
	if (str[i] != COMMENT_CHAR && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}

void check_instr_1_9_12_15(char *str)
//	 printf("check live, zjump, fork, lfork\n");
{
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_dir(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	check_instr_endline(str + i);
}

void check_instr_2_13(char *str)
{
	// printf("check ld, lld str = %s\n", str);
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_ind_or_dir(str + i);
	i += arg;
	i += until_next_arg(str + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	check_instr_endline(str + i);
}

void check_instr_3(char *str)
{
	// printf("check st\n");
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	i += until_next_arg(str + i);
	arg = is_reg_or_ind(str +  i);
	i += arg;
	check_instr_endline(str + i);
}
void check_instr_4_5(char *str)
{
	// printf("check add sub\n");
	int i;
	int arg;

	i = until_is_not_space(str);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	i += until_next_arg(str + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	i += until_next_arg(str + i);
	arg = is_reg(str + i);
	if (!arg)
		asm_error(0, NULL, 0, 0);
	i += arg;
	check_instr_endline(str + i);
}
