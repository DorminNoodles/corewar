/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:13:29 by rfulop            #+#    #+#             */
/*   Updated: 2017/08/03 07:35:54 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void  write_comment(t_asm_env *env, char *line)
{
  int a;
  int tmp;
  int c;

  a = 0;
  c = 0;
  tmp = 0;
  printf("line comment = '%s'\n", line);
  while (line[a] != '\"')
    ++a;
  a++;
  printf("between quotes = '%s'\n", line + a);
  tmp = a;
  a = 0;
  while (line[tmp + a] != '\"')
  {
    ft_putchar_fd(line[tmp + a], env->fd);
    ++a;
  }
  while (a != COMMENT_LENGTH)
  {
    ft_putchar_fd(c, env->fd);
    a++;
  }
}

void  write_name(t_asm_env *env, char *line)
{
  int a;
  int tmp;
  int c;
  int magic;

  tmp = 0;
  c = 0;
  magic = reverse_int(COREWAR_EXEC_MAGIC);
  write(env->fd, &magic, 4);
  a = 4;
  while(line[a] != '\"')
    ++a;
  ++a;
  tmp = a;
  a = 0;
  while(line[tmp + a] != '\"')
  {
    ft_putchar_fd(line[tmp + a], env->fd);
    ++a;
  }
  while(a != PROG_NAME_LENGTH)
  {
    ft_putchar_fd(c, env->fd);
    a++;
  }
}

void  write_header(t_asm_env *env, char *line, int printmode)
{
  int a;
  int tmp;

  a = 0;
  tmp = 0;
  if (!printmode)
    ;
  else
  {
    if (line[1] == 'n' && line[2] == 'a' && line[3] == 'm' && line[4] == 'e')
      write_name(env, line);
    else
      write_comment(env, line);
  }
}