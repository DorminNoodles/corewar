/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/11/01 16:54:29 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int is_space(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

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

int	check_instr(char *instr)
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
	return (ret);
}

int until_is_not_space(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	return (i);
}

int until_next_arg(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	if (str[i] != SEPARATOR_CHAR)
		asm_error(0, NULL, 0, 0);
	++i;
	while (str[i] && is_space(str[i]))
		++i;
	return (i);
}

int check_header()
{
	return 0;
}

int	len_is_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		++i;
	return i;
}

int is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		++i;
	}
	return (0);
}

int is_label_str(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (!is_label_char(str[i]))
			return 0;
		++i;
	}
	return (str[i] == LABEL_CHAR ? 1 : 0);
}

int is_ind(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] == LABEL_CHAR)
	{
		++i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
		{
			if (!is_label_char(str[i]))
				return (0);
			++i;
		}
		return (i);
	}
	if (str[i] == '-')
		++i;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
	{
		++check;
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (check ? i : 0);
}

int is_dir(char *str)
{
	int i;
	int check;

	i = 0;
	if (str[i] != DIRECT_CHAR)
			return (0);
	++i;
	check = is_ind(str + i);
	return (check ? check + 1 : 0);
}

int is_reg(char *str)
{
	int i;
	int tmp;

	i = 0;
	if (str[i] != 'r')
		return (0);
	++i;
	tmp = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
	{
		if (!ft_isdigit(str[i]))
				return (0);
		++i;
	}
	if (ft_atoi(str + tmp) < 1 || ft_atoi(str + tmp) > 16)
		return (0);
	return (i);
}

void check_instr_1_9_12_15(char *str)
{
	// printf("check live, zjump, fork, lfork\n");
	int i;
	int a;

	i = until_is_not_space(str);
	a = is_dir(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}

void check_instr_2_13(char *str)
{
	// printf("check ld, lld str = %s\n", str);
	int i;
	int a;
	int b;

	i = until_is_not_space(str);
	a = is_dir(str + i);
	b = is_ind(str + i);
	if (!a && !b)
		asm_error(0, NULL, 0, 0);
	i += a + b;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}

void check_instr_3(char *str)
{
	// printf("check st\n");
	int i;
	int a;
	int b;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_next_arg(str + i);
	a = is_ind(str +  i);
	b = is_reg(str + i);
	if (!a && !b)
		asm_error(0, NULL, 0, 0);
	i += a + b;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_4_5(char *str)
{
	// printf("check add sub\n");
	int i;
	int a;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_6_7_8(char *str)
{
	// printf("check and or xor\n");
	int i;
	int a;
	int b;
	int c;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	b = is_dir(str + i);
	c = is_ind(str + i);
	if (!a && !b && !c)
		asm_error(0, NULL, 0, 0);
	i += a + b + c;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	b = is_dir(str + i);
	c = is_ind(str + i);
	if (!a && !b && !c)
		asm_error(0, NULL, 0, 0);
	i += a + b + c;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_10(char *str)
{
	// printf("check ldi\n");
	int i;
	int a;
	int b;
	int c;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	b = is_dir(str + i);
	c = is_ind(str + i);
	if (!a && !b && !c)
		asm_error(0, NULL, 0, 0);
	i += a + b + c;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	b = is_dir(str + i);
	if (!a && !b)
		asm_error(0, NULL, 0, 0);
	i += a + b;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_11(char *str)
{
	// printf("check sti\n");
	int i;
	int a;
	int b;
	int c;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	b = is_dir(str + i);
	c = is_ind(str + i);
	if (!a && !b && !c)
		asm_error(0, NULL, 0, 0);
	i += a + b + c;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	b = is_dir(str + i);
	if (!a && !b)
		asm_error(0, NULL, 0, 0);
	i += a + b;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_14(char *str)
{
	// printf("check lldi\n");
	int i;
	int a;
	int b;
	int c;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	b = is_dir(str + i);
	c = is_ind(str + i);
	if (!a && !b && !c)
		asm_error(0, NULL, 0, 0);
	i += a + b + c;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	b = is_dir(str + i);
	if (!a && !b)
		asm_error(0, NULL, 0, 0);
	i += a + b;
	i += until_next_arg(str + i);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}
void check_instr_16(char *str)
{
	// printf("check aff\n");
	int i;
	int a;

	i = until_is_not_space(str);
	a = is_reg(str + i);
	if (!a)
		asm_error(0, NULL, 0, 0);
	i += a;
	i += until_is_not_space(str + i);
	if (str[i] != '#' && str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}

void check_parse_arg(char *str, int instr)
{
//	ft_printf("check parse arg = %s instr = %d\n", str, instr);
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

void	line_error(char *line, int nb)
{
	int i;
	char *word;
	int inst;
	int label;

//	printf("line = %s\n", line);
	i = 0;
	label = 0;
	inst = -1;
	if (!line)
		return ;
	if (*line == '.')
	;
		// check_header();
	else
	{
		while (line[i])
		{
			i += until_is_not_space(line + i);
			word = take_word(line + i);
			if (!label && is_label_str(word))
				++label;
			else if (inst == -1)
			{
				if ((inst = check_instr(word)) == -1)
					asm_error(INST_ERROR, word, nb, 0);
			}
			else
			{
				check_parse_arg(line + i, inst + 1);
				break;
			}
			i += ft_strlen(word);
			free(word);
		}
	}
}
