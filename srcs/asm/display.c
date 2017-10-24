/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/24 15:03:56 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void  write_reg(t_asm_env *env, char *line)
{
  int a;
  char reg;
  char *str;

  a = 0;
  line++;
  while (line[a] && ft_isdigit(line[a]))
    ++a;
  str = ft_strndup(line, a);
  reg = ft_atoi(str);
  ft_putchar_fd(reg, env->fd);
}

void  write_dir(t_asm_env *env, char *line, int i)
{
  int a;
  int dir4o;
  short dir2o;
  char  *str;
  char *label;
  int nb;

  a = 0;
  line++;
  nb = ft_atoi(line);
   if (line[a] != LABEL_CHAR)
   {
     while (line[a] && ft_isdigit(line[a]))
       ++a;
     str = ft_strndup(line, a);
   }

  if (i == 1 || i == 2 || i == 6 || i == 7 || i == 8 || i == 14)
  {
    if (line[a] == LABEL_CHAR)
    {
      label = take_word(line + 1);
      dir4o = dist_label(env, label);
    }
    else
      dir4o = nb;
    dir4o = reverse_int(dir4o);
    write(env->fd, &dir4o, 4);
  }
  else
  {
    if (line[a] == LABEL_CHAR)
    {
      label = take_word(line + 1);
      dir2o = dist_label(env, label);
    }
    else
      dir2o = nb;
    dir2o = reverse_short(dir2o);
    write(env->fd, &dir2o, 2);
  }
}

void  write_ind(t_asm_env *env, char *line)
{
  int a;
  short ind;
  char *str;

  a = 0;
  if (ft_isdigit(*line))
  {
    while (line[a] && ft_isdigit(line[a]))
      ++a;
    str = ft_strndup(line, a);
    ind = ft_atoi(str);
  }
  else
  {
    str = take_word(line + 1);
    ind = dist_label(env, str);
  }
  ind = reverse_short(ind);
  write(env->fd, &ind, 2);
//  print_labs_lst(env->labs);
}

void  write_args(t_asm_env *env, char *line, int i)
{
  int a;
  int res;

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
