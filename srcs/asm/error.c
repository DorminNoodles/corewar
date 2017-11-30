/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/30 17:58:42 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_error(int err)
{
	if (err >= ERROR_MIN && err <= ERROR_MAX)
	{
		color(C_RED);
		ft_printf("Error: ");
		color(C_RESET);
	}
}

void	display_current_line(t_asm_env *env, int err, int column)
{
	int i;

	if (!env || !env->current_line)
		exit(EXIT_FAILURE);
	if (err == TOO_MUCH_ARG_ERR || err == LEX_ERROR)
		--column;
	if (err >= ERROR_MIN && err <= ERROR_MAX)
	{
		i = 0;
		ft_printf("%s\n", env->current_line);
		while (i < column)
		{
			if (env->current_line[i] == TAB)
				write(1, "\t", 1);
			else
				write(1, " ", 1);
			++i;
		}
		color(C_GREEN);
		ft_printf("^\n");
		color(C_RESET);
	}
}

void	put_line_col(int err, int line, int column)
{
	if (err == INST_ERROR || err == LEX_ERROR || err == BAD_ARG_DIR ||
	err == BAD_ARG_REG || err == BAD_ARG_IND || err == BAD_ARG_REG_DIR ||
	err == BAD_ARG_REG_IND || err == BAD_ARG_IND_DIR || err == NO_ARGUMENTS ||
	err == BAD_ARG_REG_DIR_IND || err == WRONG_FORM_COM)
		ft_printf("At [%d:%d], ", line, column);
}

void	asm_error(int err, char *str, t_asm_env *env, int column)
{
	int line;

	if (env && env->debug && env->ko)
		return ;
	display_error(err);
	if (err == NO_FILE_ERR || err == SOURCE_ERR || err == FILE_ERROR ||
	err == SIZE_MAX_ERR)
		asm_error1(err, str, env);
	else if (env)
		line = env->line;
	free_labels(env);
	if (env && env->ko)
		return ;
	if (env && env->debug)
		++env->ko;
	put_line_col(err, line, column);
	asm_error2(err, str, env, column);
	display_current_line(env, err, column);
	if (!env->debug)
		exit(EXIT_FAILURE);
}

void	asm_error1(int err, char *str, t_asm_env *env)
{
	if (err == NO_FILE_ERR)
		ft_printf("Missing filename.\n");
	else if (err == SOURCE_ERR)
		ft_printf("Can't read source file '%s'.\n", str);
	else if (err == FILE_ERROR)
		ft_printf("'%s' is not a .s file.\n", str);
	else if (err == SIZE_MAX_ERR)
	{
		ft_printf("File '%s' as too large a code (%d bytes > %d bytes)\n",
		str, env->size, CHAMP_MAX_SIZE);
	}
	exit(EXIT_FAILURE);
}

void	asm_error2(int err, char *str, t_asm_env *env, int column)
{
	if (err == MALLOC_ERR)
		ft_printf("Malloc failed.\n");
	else if (err == INST_ERROR)
		ft_printf("instruction '%s' does not exist.\n", str);
	else if (err == LEX_ERROR)
		ft_printf("lexical error. Waiting for a ',' between arguments.\n");
	else if (err == BAD_ARG_DIR)
		ft_printf("this instruction expected a direct number.\n");
	else if (err == BAD_ARG_REG)
		ft_printf("this instruction expected a register.\n");
	else if (err == BAD_ARG_IND)
		ft_printf(", this instruction expected an index.\n");
	else if (err == BAD_ARG_REG_DIR)
		ft_printf("this instruction expected a direct number or a register.\n");
	else
		asm_error3(err, str, env, column);
}

void	asm_error3(int err, char *str, t_asm_env *env, int column)
{
	int line;

	if (env)
		line = env->line;
	if (err == BAD_ARG_REG_IND)
		ft_printf("this instruction expected a register or an index.\n");
	else if (err == BAD_ARG_IND_DIR)
		ft_printf("this instruction expected an index or a direct number.\n");
	else if (err == BAD_ARG_REG_DIR_IND)
		ft_printf("this instruction expected a reg, a direct or an index.\n");
	else if (err == NO_ARGUMENTS)
		ft_printf("instruction has no arguments\n");
	else if (err == LABEL_ERROR)
		ft_printf("Label '%s' is not find.\n", str);
	else if (err == TOO_MUCH_ARG_ERR)
		ft_printf("Too much arguments at [%d:%d] : '%s'.\n", line, column, str);
	else
		asm_error4(err, str, env);
}

void	asm_error4(int err, char *str, t_asm_env *env)
{
	int line;

	if (env)
		line = env->line;
	if (err == NAME_SIZE_ERR)
	{
		ft_printf("Line %d, name size is too big. Must be < %d.\n",
		line, PROG_NAME_LENGTH);
	}
	else if (err == COM_SIZE_ERR)
	{
		ft_printf("Line %d, comment is size too big. Must be < %d.\n",
		line, COMMENT_LENGTH);
	}
	else if (err == NAME_EXISTS)
		ft_printf("Line %d, name is already defined.\n", line);
	else
		asm_error5(err, str, env);
}

void	asm_error5(int err, char *str, t_asm_env *env)
{
	int line;

	if (env)
		line = env->line;
	if (err == COM_SIZE_ERR)
	{
		ft_printf("Line %d, comment is size too big. Must be < %d.\n",
		line, COMMENT_LENGTH);
	}
	else if (err == NAME_EXISTS)
		ft_printf("Line %d, name is already defined.\n", line);
	else if (err == COM_EXISTS)
		ft_printf("Line %d, comments are already defined.\n", line);
	else if (err == COMMAND_ERR)
		ft_printf("Line %d, command '%s' not found.\n", line, str);
	else
		asm_error6(err, env);
}

void	asm_error6(int err, t_asm_env *env)
{
	int line;

	if (env)
		line = env->line;
	if (err == NO_NAME)
	{
		ft_printf("Line %d, Your champion needs a name before instructions\n",
		line);
	}
	else if (err == NO_COMMENT)
	{
		ft_printf("Line %d, Your champ needs a comment before instructions\n",
		line);
	}
	else if (err == NO_INSTRUCTIONS)
		ft_printf("You need, at least, one instruction !\n");
	else if (err == WRONG_FORM_COM)
		ft_printf("wrong format. Name and com need to begin and end by \"\n");
}
