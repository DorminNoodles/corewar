/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:09:42 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/17 22:54:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_ind(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] == LABEL_CHAR)
	{
		++i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' &&
		str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
		{
			++check;
			if (!is_label_char(str[i]))
				return (0);
			++i;
		}
		return (check ? i : 0);
	}
	if (str[i] == '-')
		++i;
	while (str[i] && str[i] != ' ' && str[i] != '\t' &&
	str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
	{
		++check;
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (check ? i : 0);
}

int	is_dir(char *str)
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

int	is_reg(char *str)
{
	int i;
	int tmp;

	i = 0;
	if (str[i] != 'r')
		return (0);
	++i;
	tmp = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t' &&
	str[i] != SEPARATOR_CHAR && str[i] != COMMENT_CHAR)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	if (ft_atoi(str + tmp) < 1 || ft_atoi(str + tmp) > 16)
		return (0);
	return (i);
}
