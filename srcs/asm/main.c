/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/30 17:52:40 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_env(t_asm_env *env)
{
	env->name = 0;
	env->comment = 0;
	env->bytes = 1;
	env->line = 1;
	env->ko = 0;
	env->current_line = NULL;
	env->verbose_line = NULL;
}

void	check_mode(t_asm_env *env, char *name, int fd)
{
	char	*line;

	init_env(env);
	line = NULL;
	env->print = 0;
	env->labs = NULL;
	while (get_next_line(fd, &line))
	{
		env->current_line = line;
		check_line(env, line);
		parse(env, line);
		ft_memdel((void*)&line);
		++env->line;
	}
	env->current_line = line;
	if (!env->name)
		asm_error(NO_NAME, NULL, env, 0);
	if (!env->comment)
		asm_error(NO_COMMENT, NULL, env, 0);
	if (env->bytes == 1)
		asm_error(NO_INSTRUCTIONS, NULL, env, 0);
	env->size = env->bytes - 1;
	if (env->size > CHAMP_MAX_SIZE)
		asm_error(SIZE_MAX_ERR, name, env, 0);
}

void	print_mode_verbose(t_asm_env *env)
{
	color(C_GREEN);
	ft_printf("Total bytes: ");
	color(C_RESET);
	ft_printf("%d\n\n", env->bytes - 1);
}

void	print_mode(t_asm_env *env, char *file)
{
	int		fd;
	char	*line;

	init_env(env);
	line = NULL;
	env->print = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		parse(env, line);
		ft_memdel((void*)&line);
		if (env->verbose && env->verbose_line)
		{
			color(C_GREEN);
			ft_printf("-> ");
			color(C_RESET);
			ft_printf("0%s\n\n", env->verbose_line);
			ft_memdel((void*)&env->verbose_line);
		}
		++env->line;
	}
	if (env->verbose)
		print_mode_verbose(env);
}

void	print_help(void)
{
	ft_printf("Usage : ./asm [-[+]hvd] {*.cor}\n");
	ft_printf("Options : \n");
	ft_printf("h : Print help\n");
	ft_printf("v : Verbose Mode\n");
	ft_printf("d : Debug Mode\n");
}

void	check_args_letter(t_asm_env *env, char let)
{
	if (let == 'h')
		print_help();
	else if (let == 'v')
		env->verbose = 1;
	else if (let == 'd')
		env->debug = 1;
	else
	{
		ft_printf("Invalid argument\n");
		print_help();
		exit(0);
	}
}

int		parse_args(t_asm_env *env, char **argv)
{
	int a;
	int b;

	a = 1;
	while (argv[a] && *argv[a] == '-')
	{
		b = 1;
		while (argv[a][b])
		{
			check_args_letter(env, argv[a][b]);
			++b;
		}
		if (b == 1)
		{
			ft_printf("Invalid argument\n");
			print_help();
			exit(0);
		}
		++a;
	}
	return (a);
}

void	debug_mode(t_asm_env *env, int fd)
{
	char	*line;

	init_env(env);
	line = NULL;
	env->fd = 0;
	env->print = 0;
	env->labs = NULL;
	ft_printf("********** DEBUG MODE **********\n");
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

void	loop_args(t_asm_env *env, char **argv, int arg)
{
	int fd;

	if ((fd = open(argv[arg], O_RDONLY)) == -1)
		asm_error(SOURCE_ERR, argv[arg], 0, 0);
	if (!check_name(argv[arg]))
		asm_error(FILE_ERROR, argv[arg], 0, 0);
	check_mode(env, argv[arg], fd);
	create_file(env, argv[arg]);
	print_mode(env, argv[arg]);
	argv[arg][ft_strlen(argv[arg]) - 2] = '\0';
	ft_printf("Writting output program to %s.cor\n", argv[arg]);
	free_labels(env);
}

int		main(int argc, char **argv)
{
	int			arg;
	t_asm_env	env;

	if (argc == 1)
	{
		print_help();
		asm_error(NO_FILE_ERR, NULL, 0, 0);
	}
	env.debug = 0;
	env.verbose = 0;
	arg = parse_args(&env, argv);
	if (env.debug)
		debug_mode(&env, 0);
	if (argc == arg)
		asm_error(NO_FILE_ERR, NULL, 0, 0);
	while (arg < argc)
	{
		loop_args(&env, argv, arg);
		++arg;
	}
	return (0);
}
