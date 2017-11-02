/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 02:36:16 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_op(char *instr, int line)
{
	int i;
	int ret;

	i = 0;
	ret = -1;
	while (i < 16)
	{
		if (!(ft_strcmp(instr, op_tab[i].inst)))
		{
			ret = i;
			break;
		}
		++i;
	}
	if (ret == -1)
		asm_error(INST_ERROR, instr, line, 0);
	return (ret);
}

void check_header()
{
}

void check_parse_arg(char *str, int instr)
{
//	printf("check parse arg = %s instr = %d\n", str, instr);
	if (instr == 1 || instr == 9 || instr == 12 || instr == 15)
		check_instr_1_9_12_15(str);
	else if (instr == 2 || instr == 13)
		check_instr_2_13(str);
	else if (instr == 3)
		check_instr_3(str);
	else if (instr == 4 || instr == 5)
		check_instr_4_5(str);
	else if (instr == 6 || instr == 7 || instr == 8)
		check_instr_6_7_8(str);
	else if (instr == 10)
		check_instr_10(str);
	else if (instr == 11)
		check_instr_11(str);
	else if (instr == 14)
		check_instr_14(str);
	else if (instr == 16)
		check_instr_16(str);
}

void check_instr(char *line, int nb)
{
	int i;
	int inst;
	int label;
	char *word;

	i = 0;
	inst = -1;
	label = 0;
	while (line[i])
	{
		i += until_is_not_space(line + i);
		word = take_word(line + i);
		if (!label && inst == -1 && is_label_str(word))
			++label;
		else if (inst == -1)
			inst = check_op(word, nb);
		else
		{
			check_parse_arg(line + i, inst + 1);
			ft_memdel((void*)&word);
			break;
		}
		i += ft_strlen(word);
		ft_memdel((void*)&word);
	}
}

void	check_line(char *line, int nb)
{
	if (!line)
		return ;
	if (*line == '.')
		 check_header();
	else
		check_instr(line, nb);
}
