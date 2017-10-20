/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/20 11:08:14 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void dasm_error(int err, char *str)
{
  printf("error\n");
}

void parse_cor(t_dasm_env *env)
{
}

int ft_bin_len(unsigned char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

unsigned char *open_bin(t_dasm_env *env, int fd)
{
  int len;
  int binSize;
  unsigned char *ret;

  len = 0;
  ret = malloc(MEM_SIZE + 1);
  len = read(fd, ret, MEM_SIZE);

  binSize = ft_bin_len(ret + 4);
  if (binSize > PROG_NAME_LENGTH)
    dasm_error(0, NULL);
  char *name = ft_strnew(binSize + 1);
  name[binSize] = '\0';
  ft_memcpy(name, ret + 4, binSize);
  write(env->fd, ".name \"", 7);
  write(env->fd, name, binSize);
  write(env->fd, "\"\n", 2);

  binSize = ft_bin_len(ret + PROG_NAME_LENGTH + 12);
  if (binSize > COMMENT_LENGTH)
    dasm_error(0, NULL);
  char *comments = ft_strnew(binSize + 1);
  name[binSize] = '\0';
  ft_memcpy(comments, ret + PROG_NAME_LENGTH + 12, binSize);
  write(env->fd, ".comment \"", 10);
  write(env->fd, comments, binSize);
  write(env->fd, "\"\n\n", 3);

  return ret;
}

void create_file_cor(t_dasm_env *env, char *str)
{
  int fd;
  int len;
  char *tmp;
  char *name;

  len = ft_strlen(str) - 4;
  tmp = ft_strndup(str, len);
  name = ft_strnew(len + 2);
  name = ft_strcpy(name, tmp);
  name = ft_strcat(name, ".s");
  fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
  env->fd = fd;
}

int main(int argc, char **argv)
{
  int fd;
  char *line;
  t_dasm_env env;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    dasm_error(SOURCE_ERR, argv[1]);
  line = NULL;
  create_file_cor(&env, argv[1]);
  env.file = open_bin(&env, fd);
  parse_cor(&env);
  // while (get_next_line(fd, &line))
  // {
  //   parse_cor(&env, line);
  //   ft_memdel((void*)&line);
  // }
  argv[1][ft_strlen(argv[1]) - 4] = '\0';
  ft_printf("Writting output file to %s.s\n", argv[1]);
  return (0);
}
