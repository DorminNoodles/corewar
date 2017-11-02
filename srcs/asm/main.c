/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 01:42:45 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
  int   fd;
  int   fd2;
  char  *line;
  int nLine;
  t_asm_env env;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    asm_error(SOURCE_ERR, argv[1], 0, 0);
  if (!check_name(argv[1]))
    asm_error(FILE_ERROR, argv[1], 0, 0);
  line = NULL;
  env.bytes = 1;
  env.labs = NULL;
  nLine = 0;
  while (get_next_line(fd, &line))
  {
    check_line(line, nLine);
    parse(&env, line, 0);
    ft_memdel((void*)&line);
    ++nLine;
  }
//  printf("\n\nFinal bytes number = %d\n\n", env.bytes - 1);
  env.size = env.bytes - 1;
  create_file(&env, argv[1]);
  fd2 = open(argv[1], O_RDONLY);
  line = NULL;
  env.bytes = 1;
  while (get_next_line(fd2, &line))
  {
    parse(&env, line, 1);
    ft_memdel((void*)&line);
  }
  argv[1][ft_strlen(argv[1]) - 2] = '\0';
  ft_printf("Writting output program to %s.cor\n", argv[1]);
  return (0);
}
