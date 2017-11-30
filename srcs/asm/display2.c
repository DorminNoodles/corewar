/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/30 18:00:34 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_ocp(t_asm_env *env, char *ocp)
{
	char	*str;
	char	res;

	while (ft_strlen(ocp) != 8)
		ft_strcat(ocp, "00");
	str = ft_convert_base(ocp, "01", "0123456789");
	res = ft_atoi(str);
	if (env->verbose)
		verbose_ocp(env, res);
	ft_memdel((void*)&str);
	ft_putchar_fd(res, env->fd);
}

void	write_args(t_asm_env *env, char *line, int i)
{
	int	a;
	int	res;

	res = 0;
	a = 0;
	while (line[a] && line[a] != COMMENT_CHAR)
	{
		res = detect_arg(line + a);
		if (res == REG_CODE)
			write_reg(env, line + a);
		else if (res == DIR_CODE)
			write_dir(env, line + a, i);
		else if (res == IND_CODE)
			write_ind(env, line + a);
		a += goto_nextarg(line + a);
	}
}
