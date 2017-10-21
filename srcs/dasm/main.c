/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/21 06:07:15 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void dasm_error(int err, char *str)
{
  switch (err)
  {
    case SOURCE_ERR:
      ft_printf("Can't read source file %s\n", str);
      break;
    case MALLOC_ERR:
      ft_printf("Error: malloc failed\n");
      break;
    case OPEN_ERROR:
      ft_printf("Error: Open error\n");
      break;
    case SIZE_ERROR:
      ft_printf("Error: Size too big\n");
      break;
  }
  exit (EXIT_FAILURE);
}

int ft_bin_len(unsigned char *str)
{
  int i;

  i  = 0;
  while (str[i])
    ++i;
  return (i);
}

int					get_uint32(unsigned char *buff)
{
	return ((*(buff) << 24) | (*(buff + 1) << 16) |
	(*(buff + 2) << 8) | (*(buff + 3)));
}

short				get_uint16(unsigned char *buff)
{
	return ((*(buff) << 8) | (*(buff + 1)));
}

void print_instr(int fd, int c)
{
  char *inst;

  inst = op_tab[c - 1].inst;
  write(fd, "\t", 1);
  write(fd, inst, ft_strlen(inst));
  write(fd, "\t", 1);
}

int print_dir4(int fd, unsigned char *str)
{
  int dir;

  dir = get_uint32(str);
  write(fd, "%", 1);
  ft_putnbr_fd(dir, fd);
  return (DIR_SIZE);
}

int print_dir2(int fd, unsigned char *str)
{
  int dir;

  dir = get_uint16(str);
  write(fd, "%", 1);
  ft_putnbr_fd(dir, fd);
  return (IND_SIZE);
}

int print_reg(int fd, int reg)
{
  write(fd, "r", 1);
  ft_putnbr_fd(reg, fd);
  return (REG_SIZE);
}

int print_ind(int fd, unsigned char *str)
{
  int ind;

  ind = get_uint16(str);
  write(fd, " ", 1);
  ft_putnbr_fd(ind, fd);
  return (IND_SIZE);
}

int print_args(t_dasm_env *env, int inst, int i)
{
  printf("enter i = %d\n", i);
  int j;
  char args[3];

  args[0] = env->file[i] >> 6;
  args[1] = env->file[i] >> 4 & 3;
  args[2] = env->file[i] >> 2 & 3;
  ++i;
  j = 0;
  while (args[j])
  {
    if (args[j] == REG_CODE)
      i += print_reg(env->fd, env->file[i]);
    else if (args[j] == DIR_CODE && (inst == 10 || inst == 11 || inst == 14))
      i += print_dir2(env->fd, env->file + i);
    else if (args[j] == DIR_CODE)
      i += print_dir4(env->fd, env->file + i);
    else if (args[j] == IND_CODE)
      i += print_ind(env->fd, env->file + i);
    ++j;
    if (j < 3 && args[j])
      write(env->fd, ", ", 2);
  }
  printf("i = %d\n", i);
  return (i);
}

void parse_cor(t_dasm_env *env)
{
  int i;
  int inst;
  char args[3];
  int j;

  i = SRC_BEGIN;
  printf("sizeFile = %d\n", env->sizeFile);
  while (i < env->sizeFile)
  {
    printf("loop\n");
    inst = env->file[i];
    print_instr(env->fd, inst);
    ++i;
    if (!op_tab[inst - 1].need_ocp)
    {
      if (inst == 1)
        i += print_dir4(env->fd, env->file + i);
      else
        i += print_dir2(env->fd, env->file + i);
    }
    else
    {

       i = print_args(env, inst, i);

//      print_args(env, i);
/*
**       args[0] = env->file[i] >> 6;
**       args[1] = env->file[i] >> 4 & 3;
**       args[2] = env->file[i] >> 2 & 3;
**       ++i;
**       j = 0;
**       while (args[j])
**       {
**         if (args[j] == REG_CODE)
**           i += print_reg(env->fd, env->file[i]);
**         else if (args[j] == DIR_CODE && (inst == 10 || inst == 11 || inst == 14))
**           i += print_dir2(env->fd, env->file + i);
**         else if (args[j] == DIR_CODE)
**           i += print_dir4(env->fd, env->file + i);
**         else if (args[j] == IND_CODE)
**           i += print_ind(env->fd, env->file + i);
**         ++j;
**         if (j < 3 && args[j])
**           write(env->fd, ", ", 2);
**       }
*/
    }
//    ++i;
    write(env->fd, "\n", 1);
  }
}

void print_head(t_dasm_env *env)
{
  int binSize;
  char *name;
  char *comments;

  binSize = ft_bin_len(env->file + MAGIC_NB);
  if (binSize > PROG_NAME_LENGTH)
    dasm_error(0, NULL);
  name = ft_strnew(binSize + 1);
  name[binSize] = '\0';
  ft_memcpy(name, env->file + MAGIC_NB, binSize);
  write(env->fd, ".name \"", 7);
  write(env->fd, name, binSize);
  write(env->fd, "\"\n", 2);
  binSize = ft_bin_len(env->file + PROG_NAME + PROG_SIZE + MAGIC_NB);
  if (binSize > COMMENT_LENGTH)
    dasm_error(0, NULL);
  comments = ft_strnew(binSize + 1);
  name[binSize] = '\0';
  ft_memcpy(comments, env->file + (PROG_NAME + PROG_SIZE + MAGIC_NB), binSize);
  write(env->fd, ".comment \"", 10);
  write(env->fd, comments, binSize);
  write(env->fd, "\"\n\n", 3);
}

unsigned char *open_bin(t_dasm_env *env, int fd)
{
  unsigned char *ret;

  if (!(ret = malloc(MEM_SIZE + 1)))
    dasm_error(MALLOC_ERR, NULL);
  env->sizeFile = read(fd, ret, MEM_SIZE);
  if (env->sizeFile > MEM_SIZE)
    dasm_error(SIZE_ERROR, NULL);
  return (ret);
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
  if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
    dasm_error(OPEN_ERROR, str);
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
  print_head(&env);
  parse_cor(&env);
  argv[1][ft_strlen(argv[1]) - 4] = '\0';
  ft_printf("Writting output file to %s.s\n", argv[1]);
  return (0);
}
