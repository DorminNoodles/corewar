/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/05 01:21:13 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_op(char *instr, t_asm_env *env, int col)
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
			break ;
		}
		++i;
	}
	if (ret == -1)
		asm_error(INST_ERROR, instr, env, col);
	return (ret);
}

int check_header_form(t_asm_env *env, char *line)
{
	int i;
	int len;

	i = 0;
	while (line[i] && !is_space(line[i]))
		++i;
	i += until_is_not_space(line + i);
	if (line[i] != '\"')
		asm_error(WRONG_FORM_COM, NULL, env, i);
	len = 0;
	++i;
	while (line[i + len] && line[i + len] != '\"')
	{
		if (line[i + len] == '\"')
			break ;
		++len;
	}
	if (line[i + len] == '\"')
		return (len);
		asm_error(WRONG_FORM_COM, NULL, env, i);
	return (0);
}

void	check_header(t_asm_env *env, char *line)
{
	char	*word;
	int		len;

	word = take_word(line);
	len = ft_strlen(line);
	check_header_form(env, line);
	if (!ft_strcmp(word, NAME_CMD_STRING))
	{
		if (env->name)
			asm_error(NAME_EXISTS, NULL, env, 0);
		else if (len - ft_strlen(NAME_CMD_STRING) > PROG_NAME_LENGTH)
			asm_error(NAME_SIZE_ERR, NULL, env, 0);
		++env->name;
	}
	else if (!ft_strcmp(word, COMMENT_CMD_STRING))
	{
		if (env->comment)
			asm_error(COM_EXISTS, NULL, env, 0);
		else if (len - ft_strlen(COMMENT_CMD_STRING) > COMMENT_LENGTH)
			asm_error(COM_SIZE_ERR, NULL, env, 0);
		++env->comment;
	}
	else
		asm_error(COMMAND_ERR, word, env, 0);
//	check_header_form(env, line);
	ft_memdel((void*)&word);
}

void	check_parse_arg(char *str, int instr, t_asm_env *env, int col)
{
	if (instr == 1 || instr == 9 || instr == 12 || instr == 15)
		check_instr_1_9_12_15(str, env, col);
	else if (instr == 2 || instr == 13)
		check_instr_2_13(str, env, col);
	else if (instr == 3)
		check_instr_3(str, env, col);
	else if (instr == 4 || instr == 5)
		check_instr_4_5(str, env, col);
	else if (instr == 6 || instr == 7 || instr == 8)
		check_instr_6_7_8(str, env, col);
	else if (instr == 10)
		check_instr_10(str, env, col);
	else if (instr == 11)
		check_instr_11(str, env, col);
	else if (instr == 14)
		check_instr_14(str, env, col);
	else if (instr == 16)
		check_instr_16(str, env, col);
}

void	check_instr(char *line, t_asm_env *env)
{
	int		i;
	int		inst;
	int		label;
	int 	args;
	char	*word;

	i = 0;
	args = 0;
	inst = -1;
	label = 0;
	while (line[i])
	{
		i += until_is_not_space(line + i);
		word = take_word(line + i);
		if (!label && inst == -1 && is_label_str(word))
			++label;
		else if (inst == -1)
			inst = check_op(word, env, i);
		else
		{
			check_parse_arg(line + i, inst + 1, env, i);
			ft_memdel((void*)&word);
			++args;
			break ;
		}
		i += ft_strlen(word);
		ft_memdel((void*)&word);
	}
	if (inst != -1 && !args)
		asm_error(NO_ARGUMENTS, line, env, i);
}

void	check_line(t_asm_env *env, char *line)
{
	if (!line)
		return ;
	if (*line == '.')
		check_header(env, line);
	else
	{
		if (env->name && env->comment)
			check_instr(line, env);
		else if (!env->debug)
		{
			if (!env->name)
				asm_error(NO_NAME, NULL, env, 0);
			else
				asm_error(NO_COMMENT, NULL, env, 0);
		}
	}
}
