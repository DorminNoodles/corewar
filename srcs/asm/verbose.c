/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:44 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/07 17:27:57 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_arg(t_asm_env *env, char *line, int add, int hex)
{
	int a;
	char *tmp;
	char *tmp2;

	a = 0;
	ft_printf("|");
	color(C_BLUE);
	if (add == 1)
		ft_printf("%c", DIRECT_CHAR);
	else if (add == 2)
		ft_printf("%c", REG_CHAR);
	while (line[a] && !is_space(line[a]) && line[a] != SEPARATOR_CHAR)
	{
		ft_printf("%c", line[a]);
		++a;
	}
	color(C_RESET);
	ft_printf("| ");
	tmp2 = ft_itoa(hex);
	tmp = ft_conv_hex(tmp2, HEX2);
	env->verbose_line = ft_strcat(env->verbose_line, "0");
	env->verbose_line = ft_strncat(env->verbose_line, ft_strrev(tmp), 8);
	env->verbose_line = ft_strcat(env->verbose_line, " ");
	ft_memdel((void*)&tmp);
}

void	verbose_inst(t_asm_env *env, char *ins, int hex)
{
	char *tmp;
	char *tmp2;

	ft_printf("Instruction:|");
	color(C_CYAN);
	ft_printf("%s", ins);
	color(C_RESET);
	ft_printf("| ");
	if (!(env->verbose_line = ft_strnew(30)))
			asm_error(MALLOC_ERR, NULL, 0, 0);
	if (!(tmp2 = ft_itoa(hex+1)))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	if (!(tmp = ft_convert_base(tmp2, DEC, HEX2)))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	env->verbose_line = ft_strcat(env->verbose_line, tmp);
	ft_memdel((void*)&tmp);
	ft_memdel((void*)&tmp2);
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
	char *tmp2;

	if (ocp)
	{
		ft_printf("Ocp: %hb (%#hhx) ", ocp, ocp);
		if (!(tmp2 = ft_itoa((unsigned char)ocp)))
			asm_error(MALLOC_ERR, NULL, 0, 0);
		tmp = ft_convert_base(tmp2, DEC, HEX2);
		env->verbose_line =  ft_strcat(env->verbose_line, tmp);
		ft_memdel((void*)&tmp);
		ft_memdel((void*)&tmp2);
		env->verbose_line = ft_strcat(env->verbose_line, " ");
	}
	else
		ft_printf("No ocp ");
}
