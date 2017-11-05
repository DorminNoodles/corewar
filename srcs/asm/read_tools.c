/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/04 19:20:48 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		goto_nextarg(char *line)
{
	int a;

	a = 0;
	while (line[a] && line[a] != SEPARATOR_CHAR)
		++a;
	if (line[a] == SEPARATOR_CHAR)
		++a;
	while (line[a] && is_space(line[a]))
		++a;
	return (a);
}

char	*red_label_name(char *word, int len)
{
	int		i;
	char	*label;

	if (!(label = (char*)malloc(sizeof(char) * len + 1 + 1)))
		exit(0);
	label[len] = '\0';
	i = 0;
	while (i < len + 1)
	{
		label[i] = word[i];
		++i;
	}
	ft_memdel((void*)&word);
	return (label);
}
