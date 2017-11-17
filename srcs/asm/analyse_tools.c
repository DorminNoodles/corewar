/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/17 22:53:33 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*moove_on_line(char *line)
{
	int a;

	a = 0;
	while (ft_isalpha(line[a]) || ft_isdigit(line[a]))
		++a;
	while (is_space(line[a]))
		++a;
	return (line + a);
}

int		detect_arg(t_asm_env *env, char *line)
{
	int a;

	a = 0;
	a = 0;
	if (line[a] == 'r')
		return (REG_CODE);
	if (line[a] == LABEL_CHAR || ft_isdigit(line[a]))
		return (IND_CODE);
	if (line[a] == '-' && ft_isdigit(line[a + 1]))
		return (IND_CODE);
	if (line[a] == DIRECT_CHAR)
		return (DIR_CODE);
	return (0);
}

char	*concat_opcode(char *ocp, int arg)
{
	if (!ocp)
	{
		if (!(ocp = ft_strnew(8)))
			asm_error(MALLOC_ERR, NULL, 0, 0);
	}
	if (arg == REG_CODE)
		ft_strcat(ocp, "01");
	else if (arg == DIR_CODE)
		ft_strcat(ocp, "10");
	else if (arg == IND_CODE)
		ft_strcat(ocp, "11");
	return (ocp);
}
