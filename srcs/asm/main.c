/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/03 00:13:46 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_mode(t_asm_env *env, int fd)
{
  char *line;

  env->print = 0;
  env->name = 0;
  env->comment = 0;
  env->bytes = 1;
  env->labs = NULL;
  env->line = 1;
  line = NULL;
  while (get_next_line(fd, &line))
  {
    env->current_line = line;
    check_line(env, line);
    parse(env, line, CHECK_MODE);
    ft_memdel((void*)&line);
    ++env->line;
  }
  env->size = env->bytes - 1;
}

void print_mode(t_asm_env *env, char *file)
{
  int fd;
  char *line;

  fd = open(file, O_RDONLY);
  line = NULL;
  env->bytes = 1;
  env->print = 1;
  env->line = 1;
  while (get_next_line(fd, &line))
  {
    parse(env, line, PRINT_MODE);
    ft_memdel((void*)&line);
    if (env->verbose)
      ft_printf("\n");
    ++env->line;
  }
  if (env->verbose)
    ft_printf("\n\nFinal bytes number = %d\n\n", env->bytes - 1);
}

void print_help()
{
  ft_printf("Usage : ./asm [-[+]hvd] {*.cor}\n");
  ft_printf("Options : \n");
  ft_printf("h : Print help\n");
  ft_printf("v : Verbose Mode\n");
  ft_printf("d : Debug Mode\n");
}


int parse_args(t_asm_env *env, char **argv)
{
  int a;
  int b;

  a = 1;
  while (argv[a] && *argv[a] == '-')
  {
    b = 1;
    while(argv[a][b])
    {
      if (argv[a][b] == 'h')
        print_help();
      else if (argv[a][b] == 'v')
        env->verbose = 1;
      else if (argv[a][b] == 'd')
        env->debug = 1;
      else
      {
        ft_printf("Invalid argument\n");
        print_help();
        exit (0);
      }
      ++b;
    }
    if (b == 1)
    {
      ft_printf("Invalid argument\n");
      print_help();
      exit (0);
    }
    ++a;
  }
  return a;
}

void debug_mode(t_asm_env *env, int fd)
{
  char *line;

  ft_printf("**********");
  color(C_BLUE);
  ft_printf(" Debug Mode ");
  color(C_RESET);
  ft_printf("**********\n");
  line = NULL;
  env->fd = 0;
  env->line = 1;
  env->bytes = 1;
  env->name = 0;
  env->comment = 0;
  env->labs = NULL;
  while (get_next_line(fd, &line))
  {
    env->current_line = line;
    env->ko = 0;
    check_line(env, line);
    if (!env->ko)
    {
      ft_printf("This instruction is ");
      color(C_GREEN);
      ft_printf("OK.\n\n");
      color(C_RESET);
    }
    ft_memdel((void*)&line);
    ++env->line;
  }
}

int main (int argc, char **argv)
{
  int   fd;
  int arg;
  t_asm_env env;

  if (argc == 1)
  {
    print_help();
    asm_error(NO_FILE_ERR, NULL, 0, 0);
  }
  arg = parse_args(&env, argv);
  if (env.debug)
    debug_mode(&env, 0);
  if (argc == arg)
    asm_error(NO_FILE_ERR, NULL, 0, 0);
  if ((fd = open(argv[arg], O_RDONLY)) == -1)
    asm_error(SOURCE_ERR, argv[arg], 0, 0);
  if (!check_name(argv[arg]))
    asm_error(FILE_ERROR, argv[arg], 0, 0);
  check_mode(&env, fd);
  create_file(&env, argv[arg]);
  print_mode(&env, argv[arg]);
  argv[arg][ft_strlen(argv[arg]) - 2] = '\0';
  ft_printf("Writting output program to %s.cor\n", argv[arg]);
  return (0);
}
