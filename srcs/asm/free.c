/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:44 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/03 18:24:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void free_labels(t_asm_env *env)
{
	t_tab_labs *labels;
	t_tab_labs *tmp;
//	print_labs_lst(env->labs);
	labels = env->labs;
	while (labels)
	{
		tmp = labels;
		labels = labels->next;
		free(tmp->label);
		free(tmp);
	}
//	print_labs_lst(env->labs);
 }
