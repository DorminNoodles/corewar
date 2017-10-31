/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/31 14:05:02 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char  *moove_on_line(char *line)
{
  int a;

  a = 0;
  while (ft_isalpha(line[a]) || ft_isdigit(line[a]))
    ++a;
  while(line[a] == ' ' || line[a] == '\t')
    ++a;
  return (line + a);
}

void  op_ocp(t_asm_env *env, int i, char *line)
{
  int  a;
  int res;
  char *ocp;

  a = 0;
  res = 0;
  ocp = NULL;
  ft_putchar_fd(i + 1, env->fd);
  line = moove_on_line(line);
  while (line[a])
  {
    res = detect_arg(line + a);
    ocp = concat_opcode(ocp, res);
    a += goto_nextarg(line + a);
  }
  write_ocp(env, ocp);
  write_args(env, line, i + 1);
}

void  op_no_ocp(t_asm_env *env, int i, char *line)
{
  int  a;
  int res;

  a = 0;
  res = 0;
  ft_putchar_fd(i + 1, env->fd);
  line = moove_on_line(line);
  while (line[a])
  {
    res = detect_arg(line + a);
    a += goto_nextarg(line + a);
  }
  write_args(env, line, i + 1);
}

int analyse_args(int oct, char *line, int i)
{
  if (*line == 'r')
    oct += 1;
  else if (*line == '%')
  {
    if ((i == 0 || i == 1 || i == 5 || i == 6 || i == 7 || i == 13))
      oct += 4;
    else
      oct += 2;
  }
  else if (*line == ':' || ft_isdigit(*line))
    oct += 2;
  return (oct);
}

void	write_args(t_asm_env *env, char *line, int i)
{
	int	a;
	int	res;

	res = 0;
	a = 0;
	while (line[a])
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

int  analyse(int oct, char *line, int i)
{
  int a;

  a = 0;
  while (line[a] && line[a] != '\n')
  {
    while (line[a] == LABEL_CHAR)
      ++a;
    while (line[a] && (line[a] == '-' || ft_isalpha(line[a]) || ft_isdigit(line[a])))
      ++a;
    while (line[a] && (line[a] == ' ' || line[a] == '\t'))
      ++a;
    if (line[a] == SEPARATOR_CHAR)
      ++a;
    oct = analyse_args(oct, line + a, i);
    if (line[a] == SEPARATOR_CHAR)
      a++; // pour la vrigule tmts
    if (line[a] == DIRECT_CHAR)
      a++;
    if (line[a] == COMMENT_CHAR)
      return (oct);
  }
    return (oct);
}
