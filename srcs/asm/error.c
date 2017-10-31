/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/10/31 17:02:06 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int is_space(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

void	asm_error(int err, char *str, int line, int column)
{
	printf("str = %s\n", str);
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
		ft_printf("TODO\n");
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

int is_dir(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] != DIRECT_CHAR)
			return (0);
	++i;
	if (str[i] == '-')
		++i;
	else if (str[i] == LABEL_CHAR)
		++i;
	while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != SEPARATOR_CHAR))
	{
		++check;
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	if (!check)
			return (0);
	return (i);
}

int is_ind(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] == '-')
		++i;
	while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != SEPARATOR_CHAR))
	{
		++check;
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	if (!check)
			return (0);
	return (i);

}

int is_reg(char *str)
{
	int i;
	int tmp;
	int check;

	i = 0;
	if (str[i] != 'r')
			return (0);
		asm_error(0, NULL, 0, 0);
	++i;
	tmp = i;
	while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != SEPARATOR_CHAR))
	{
		++check;
		if (!ft_isdigit(str[i]))
			return (0);
			asm_error(0, NULL, 0, 0);
		++i;
	}
	if (!check || check > 2)
		return (0);
	if (check == 2 && (str[tmp] != '1' || str[tmp] < '0' || str[tmp] > '9'))
		return (0);
	if (check == 1 && str[tmp] >= '0' && str[tmp] <= '9')
		return (0);
	return (i);
}

void check_instr_1_9_12_15(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	i = is_reg(str + i);
	if (!i)
		asm_error(0, NULL, 0, 0);
	while (str[i] && is_space(str[i]))
		++i;
	if (str[i] != '\n' || str[i] != '\0')
		asm_error(0, NULL, 0, 0);
}

void check_instr_2_14(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	i
}
void check_instr_3(char *str) {}
void check_instr_4_5(char *str) {}
void check_instr_6_7_8(char *str) {}
void check_instr_10(char *str) {}
void check_instr_11(char *str) {}
void check_instr_13(char *str) {}
void check_instr_16(char *str) {}

void check_parse_arg(char *str, int instr)
{
	ft_printf("check parse arg = %s instr = %d\n", str, instr);
	if (instr == 1 || instr == 9 || instr == 12 || instr == 15)
		check_instr_1_9_12_15(str);
	else if (instr == 2 || instr == 14)
		check_instr_2_14(str);
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
	else if (instr == 13)
		check_instr_13(str);
	else if (instr == 16)
		check_instr_16(str);
}

void	line_error(char *line, int nb)
{
	int i;
	int len;
	char *word;
	int inst;

	printf("line = %s\n", line);
	i = 0;
	inst = -1;
	if (!line)
		return ;
	int test = ft_strlen(line);
	if (*line == '.')
	{
		// check_header();
	}
	else
	{
		while (i < test && line[i])
		{
			while (line[i] && is_space(line[i]))
					++i;
			word = take_word(line + i);
			len = len_is_label(word);
			if (word[len] == LABEL_CHAR)
			{
				++i;
			}
			else if (inst == -1)
			{
				if ((inst = check_instr(word)) == -1)
					asm_error(INST_ERROR, word, nb, 0);
			}
			else
			{
				check_parse_arg(line + i, inst);
				while (line[i] && is_space(line[i]))
					++i;
				if (line[i] == SEPARATOR_CHAR)
					++i;
			}
			free(word);
		i += len;
	//	ft_printf("i = %d line = %s word = %s\n", i, line + i, word);
		}
	}
}
