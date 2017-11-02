/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 01:59:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_mode(t_asm_env *env, int fd)
{
  int nLine;
  char *line;

  env->bytes = 1;
  env->labs = NULL;
  nLine = 0;
  line = NULL;
  while (get_next_line(fd, &line))
  {
    check_line(line, nLine);
    parse(env, line, CHECK_MODE);
    ft_memdel((void*)&line);
    ++nLine;
  }
  env->size = env->bytes - 1;
//  printf("\n\nFinal bytes number = %d\n\n", env.bytes - 1);
}

void print_mode(t_asm_env *env, char *file)
{
  int fd;
  char *line;

  fd = open(file, O_RDONLY);
  line = NULL;
  env->bytes = 1;
  while (get_next_line(fd, &line))
  {
    parse(env, line, PRINT_MODE);
    ft_memdel((void*)&line);
  }
}

int main (int argc, char **argv)
{
  int   fd;
  t_asm_env env;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    asm_error(SOURCE_ERR, argv[1], 0, 0);
  if (!check_name(argv[1]))
    asm_error(FILE_ERROR, argv[1], 0, 0);
  check_mode(&env, fd);

  create_file(&env, argv[1]);
  print_mode(&env, argv[1]);
  argv[1][ft_strlen(argv[1]) - 2] = '\0';
  ft_printf("Writting output program to %s.cor\n", argv[1]);
  return (0);
}
