/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/06 21:37:27 by rfulop           ###   ########.fr       */
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
		exit (EXIT_FAILURE);
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

void	asm_error(int err, char *str, t_asm_env *env, int column)
{
	int line;

	display_error(err);
	if (err == NO_FILE_ERR)
	{
		ft_printf("Missing filename.\n");
		exit(EXIT_FAILURE);
	}
	else if (err == SOURCE_ERR)
	{
		ft_printf("Can't read source file '%s'.\n", str);
		exit(EXIT_FAILURE);
	}
	else if (err == FILE_ERROR)
	{
		ft_printf("'%s' is not a .s file.\n", str);
		exit(EXIT_FAILURE);
	}
	else if (err == SIZE_MAX_ERR)
	{
		ft_printf("Has too large a code (%d bytes > %d bytes)\n", env->size, CHAMP_MAX_SIZE);
		exit(EXIT_FAILURE);
	}
	else if (env)
		line = env->line;
	free_labels(env);
	if (env && env->ko)
		return ;
	if (env && env->debug)
		++env->ko;
	if (err == MALLOC_ERR)
		ft_printf("Malloc failed.\n");
	else if (err == INST_ERROR)
		ft_printf("At [%d:%d], instruction '%s' does not exist.\n", line, column, str);
	else if (err == LEX_ERROR)
		ft_printf("Lexical error at [%d:%d]. Waiting for a ',' between arguments.\n", line, column - 1);
	else if (err == BAD_ARG_DIR)
		ft_printf("At [%d:%d], this instruction expected a direct number.\n", line, column);
	else if (err == BAD_ARG_REG)
		ft_printf("At [%d:%d], this instruction expected a register.\n", line, column, str);
	else if (err == BAD_ARG_IND)
		ft_printf("At [%d:%d], this instruction expected an index.\n", line, column);
	else if (err == BAD_ARG_REG_DIR)
		ft_printf("At [%d:%d], this instruction expected a direct number or a register.\n", line, column);
	else
		asm_error2(err, str, env, column);
	display_current_line(env, err, column);
	if (!env->debug)
		exit(EXIT_FAILURE);
}

void	asm_error2(int err, char *str, t_asm_env *env, int column)
{
	int line;

	if (env)
		line = env->line;
	if (err == BAD_ARG_REG_DIR)
		ft_printf("At [%d:%d], this instruction expected a direct number or a register.\n", line, column);
	else if (err == BAD_ARG_REG_IND)
		ft_printf("At [%d:%d], this instruction expected a register or an index.\n", line, column);
	else if (err == BAD_ARG_IND_DIR)
		ft_printf("At [%d:%d], this instruction expected an index or a direct number.\n", line, column);
	else if (err == BAD_ARG_REG_DIR_IND)
		ft_printf("At [%d:%d], this instruction expected a register, a direct number or an index.\n", line, column);
	else if (err == NO_ARGUMENTS)
		ft_printf("At [%d:%d], instruction has no arguments\n", line, column);
	else if (err == LABEL_ERROR)
		ft_printf("Label '%s' is not find.\n", str);
	else if (err == TOO_MUCH_ARG_ERR)
		ft_printf("Too much arguments at [%d:%d] : '%s'.\n", line, column, str);
	else if (err == NAME_SIZE_ERR)
		ft_printf("Line %d, name size is too big. Must be < %d.\n", line, PROG_NAME_LENGTH);
	else if (err == COM_SIZE_ERR)
		ft_printf("Line %d, comment is size too big. Must be < %d.\n", line, COMMENT_LENGTH);
	else if (err == NAME_EXISTS)
		ft_printf("Line %d, name is already defined.\n", line);
	else if (err == COM_EXISTS)
		ft_printf("Line %d, comments are already defined.\n", line);
	else if (err == COMMAND_ERR)
		ft_printf("Line %d, command '%s' not found.\n", line, str);
	else if (err == NO_NAME)
		ft_printf("Line %d, Your champion needs a name before instructions\n", line);
	else if (err == NO_COMMENT)
		ft_printf("Line %d, Your champion needs a comment before instructions\n", line);
	else if (err == NO_INSTRUCTIONS)
		ft_printf("You need, at least, one instruction !\n");
	else if (err == WRONG_FORM_COM)
		ft_printf("At [%d:%d], wrong format. Name and comment need to begin and end by \"\n", line, column);
}
