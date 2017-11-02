/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 15:13:38 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int until_is_not_space(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	return (i);
}

int until_next_arg(char *str, int lin, int col)
{
	int i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	if (str[i] != SEPARATOR_CHAR)
		asm_error(LEX_ERROR, str, lin, col + i);
	++i;
	while (str[i] && is_space(str[i]))
		++i;
	return (i);
}

int	len_is_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		++i;
	return i;
}
