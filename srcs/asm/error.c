/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by lchety            #+#    #+#             */
/*   Updated: 2017/10/28 14:25:53 by rfulop           ###   ########.fr       */
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

//int check_header()
//{

//}

int	len_is_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		++i;
	return i;
}

void check_parse_arg(char *str)
{
	ft_printf("check parse arg = %s\n", str);
}

void	line_error(char *line, int nb)
{
	int i;
	int len;
	char *word;
	int inst;

	i = 0;
	inst = 0;
	if (!line)
		return ;
	if (*line == '.')
	{
		// check_header();
	}
	else
	{
		while (line[i])
		{
			while (line[i] && is_space(line[i]))
					++i;
			word = take_word(line + i);
	//		ft_printf("LOOP word = '%s'\n", word);
			len = len_is_label(word);
			if (word[len] == LABEL_CHAR)
			{
				++i;
			}
			else if (!inst)
			{
				if (check_instr(word) == -1)
					asm_error(INST_ERROR, word, nb, 0);
				++inst;
			}
			else
			{
				check_parse_arg(line + i);
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
//	printf("line = %s\n", line);
}
