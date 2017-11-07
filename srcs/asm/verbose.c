/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:44 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/07 15:44:36 by rfulop           ###   ########.fr       */
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
	char *tmp2;

	// printf("add = %d\n", add);
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
//	tmp = ft_convert_base(ft_itoa(hex), DEC, HEX2);
	tmp2 = ft_itoa(hex);
	tmp = ft_conv_hex(tmp2, HEX2);
	env->verbose_line = ft_strcat(env->verbose_line, "0");
//	tmp[7] = '\0';
	env->verbose_line = ft_strncat(env->verbose_line, ft_strrev(tmp), 8);
	env->verbose_line = ft_strcat(env->verbose_line, " ");
	ft_memdel((void*)&tmp);
	// free(tmp2);
	// ft_memdel((void*)&tmp2);
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
//	env->verbose_line = ft_strnew(30);
	// if (!(env->verbose_line = (char*)malloc(sizeof(char) * 30 + 1)))
	if (!(env->verbose_line = ft_strnew(30)))
			asm_error(MALLOC_ERR, NULL, 0, 0);
	// env->current_line[30] = '\0';
	if (!(tmp2 = ft_itoa(hex+1)))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	if (!(tmp = ft_convert_base(tmp2, DEC, HEX2)))
		asm_error(MALLOC_ERR, NULL, 0, 0);
	// tmp = ft_conv_hex(ft_itoa(hex+1), HEX2);
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
		// tmp = ft_conv_hex(ft_itoa((unsigned char)ocp), HEX2);
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
