/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:57 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/28 11:05:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			dist_label(t_asm_env *env, char *label)
{
	t_tab_labs *tmp;

	tmp = env->labs;
	while (ft_strcmp(label, tmp->label))
		tmp = tmp->next;
	return (tmp->nb_oct - env->bytes);
}

t_tab_labs	*new_label(char *line, int bytes)
{
	int			a;
	int			len;
	char		*name;
	t_tab_labs	*new;

	len = 0;
	while (line[len] != ':')
		++len;
	if (!(name = ft_strnew(len)))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	a = 0;
	while (a != len)
	{
		name[a] = line[a];
		++a;
	}
	name[a] = '\0';
	if (!(new = (t_tab_labs*)malloc(sizeof(t_tab_labs))))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	new->label = ft_strdup(name);
	new->nb_oct = bytes;
	new->next = NULL;
	return (new);
}

void		create_label(t_tab_labs **labels, int bytes, char *line)
{
	t_tab_labs	*tmp;

	tmp = *labels;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label(line, bytes);
	}
	else
		*labels = new_label(line, bytes);
}
