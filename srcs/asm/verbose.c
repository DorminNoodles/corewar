/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:44 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/05 19:04:06 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}

void	verbose_arg(t_asm_env *env, char *line, int add, int hex)
{
	int a;
	char *tmp;

	a = 0;
	ft_printf("|");
	color(C_BLUE);
	if (add)
		ft_printf("%c", DIRECT_CHAR);
	while (line[a] && !is_space(line[a]) && line[a] != SEPARATOR_CHAR)
	{
		ft_printf("%c", line[a]);
		++a;
	}
	color(C_RESET);
	ft_printf("| ");
	tmp = ft_conv_hex(ft_itoa(hex), HEX2);
	env->verbose_line = ft_strcat(env->verbose_line, "0");
	tmp[7] = '\0';
	env->verbose_line = ft_strcat(env->verbose_line, ft_strrev(tmp));
	env->verbose_line = ft_strcat(env->verbose_line, " ");
	ft_memdel((void*)&tmp);
}

void	verbose_inst(t_asm_env *env, char *ins, int hex)
{
	char *tmp;

	ft_printf("Instruction:|");
	color(C_CYAN);
	ft_printf("%s", ins);
	color(C_RESET);
	ft_printf("| ");
	env->verbose_line = ft_strnew(30);
	tmp = ft_conv_hex(ft_itoa(hex+1), HEX2);
	env->verbose_line = ft_strcat(env->verbose_line, tmp);
	ft_memdel((void*)&tmp);
	env->verbose_line = ft_strcat(env->verbose_line, " ");
}

void	verbose_dist_lab(int dist)
{
	ft_printf("(Jump dist: %d) ", dist);
}

void	verbose_lab(char *lab, int pos)
{
	ft_printf("label:|");
	color(C_RED);
	write(1, lab, ft_strlen(lab) - 1);
	color(C_RESET);
	ft_printf("| ");
}

void	verbose_ocp(t_asm_env *env, char ocp)
{
	char *tmp;
	if (ocp)
	{
		ft_printf("Ocp: %hb (%#hhx) ", ocp, ocp);
		tmp = ft_conv_hex(ft_itoa((unsigned char)ocp), HEX2);
		env->verbose_line =  ft_strcat(env->verbose_line, tmp);
		ft_memdel((void*)&tmp);
		env->verbose_line = ft_strcat(env->verbose_line, " ");
	}
	else
		ft_printf("No ocp ");
}
