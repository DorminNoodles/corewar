/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:49:01 by lchety            #+#    #+#             */
/*   Updated: 2017/12/04 18:55:52 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_strargv(int argc, char **argv, char *str)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strstr(argv[i], str))
			return (i);
		i++;
	}
	return (0);
}

int		srch_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-d")))
	{
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			error("error : verbosity bad number\n");
	}
	return (-1);
}

int		srch_verbose(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-v")))
	{
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			error("error : dump bad number\n");
	}
	return (0);
}

int		srch_ncurses(int argc, char **argv)
{
	int ret;

	ret = 0;
	if ((ret = ft_strargv(argc, argv, "-ncurses")))
		return (1);
	return (0);
}

void usage(void)
{
	ft_printf("Usage: ./corewar [-d N -v N | -ncurses ] <[-n N] champion1.cor> <...>\n");
	ft_printf("  -d N\t\t: Dumps memory after N cycles then exits\n");
	ft_printf("  -v N\t\t: Verbosity levels, can be added together to enable several\n");
	ft_printf("\t\t\t- 0 : Show only essentials\n");
	ft_printf("\t\t\t- 1 : Show lives\n");
	ft_printf("\t\t\t- 2 : Show cycles\n");
	ft_printf("\t\t\t- 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t\t- 8 : Show deaths\n");
	ft_printf("\t\t\t- 16 : Show PC movements (Except for jumps)\n");
	ft_printf("  -ncurses\t: Ncurses output mode\n");
	ft_printf("\t-n N\t\t: Champion number (position at initalisation of memory)\n");
	exit(EXIT_FAILURE);
}

int		check_arg(t_vm *vm, int argc, char **argv)
{
	if (argc == 1)
		usage();
	vm->dump = srch_nb_dump(argc, argv);
	vm->ncurses = srch_ncurses(argc, argv);
	vm->verbosity = srch_verbose(argc, argv);
	if (srch_players(vm, argc, argv))
		return (1);
	return (0);
}
