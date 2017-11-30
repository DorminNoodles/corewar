/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/30 18:08:21 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_label(t_asm_env *env, char *line, char *label, int printmode)
{
	int a;

	a = 0;
	if (!printmode)
		create_label(&env->labs, env->bytes, line);
	if (env->verbose && printmode == PRINT_MODE)
		verbose_lab(label);
	while (line[a] && (is_label_char(line[a])))
		++a;
	while (line[a] && (is_space(line[a]) || line[a] == LABEL_CHAR))
		++a;
	label = take_word(line + a);
	if (*label)
		env->bytes += find_op(env, label, line + a);
	ft_memdel((void*)&label);
}

void	parse_verbose(t_asm_env *env, char *line)
{
	color(C_GREEN);
	ft_printf("- Line %d ", env->line);
	color(C_YELLOW);
	ft_printf("(Actual byte: %d)", env->bytes - 1);
	color(C_RESET);
	ft_printf(" : '%s'\n", line);
}

void	parse(t_asm_env *env, char *line)
{
	int			a;
	size_t	len;
	char		*w;

	if (line && line[0] != COMMENT_CHAR)
	{
		if (env->verbose && env->print == PRINT_MODE)
			parse_verbose(env, line);
		a = until_is_not_space(line);
		if (!line[a] || line[a] == COMMENT_CHAR)
			return ;
		w = take_word(line + a);
		len = len_is_label(w);
		if (w[len] == LABEL_CHAR && len + 1 != ft_strlen(w))
			w = red_label_name(w, len);
		if (!ft_strcmp(w, NAME_CMD_STRING) || !ft_strcmp(w, COMMENT_CMD_STRING))
			write_header(env, line, env->print);
		else if (w[ft_strlen(w) - 1] == LABEL_CHAR)
			parse_label(env, line + a, w, env->print);
		else
			env->bytes += find_op(env, w, line + a);
		ft_memdel((void*)&w);
		if (env->verbose && env->print == PRINT_MODE)
			ft_printf("\n");
	}
}
