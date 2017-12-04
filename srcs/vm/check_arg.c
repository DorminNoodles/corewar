/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:49:01 by lchety            #+#    #+#             */
/*   Updated: 2017/12/04 12:36:42 by lchety           ###   ########.fr       */
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

int		srch_nb_player(char **argv, int arg_num)
{
	if (arg_num - 2 > 0)
		if (ft_strstr(argv[arg_num - 2], "-n"))
			return (1);
	return (0);
}

int		is_free_nb_player(t_vm *vm, int nb)
{
	if (!vm->nb_player)
		return (1);
	if (vm->player[nb].active)
		return (0);
	return (1);
}

int		first_free_nb_player(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!vm->player[i].active)
			return (i);
		i++;
	}
	return (0);
}

int		get_nb_player(t_vm *vm, char **argv, int arg_num)
{
	int ret;

	ret = 0;
	if (srch_nb_player(argv, arg_num))
	{
		ret = ft_atoi(argv[arg_num - 1]);
		if (ret > 0 && ret < 5 && is_free_nb_player(vm, ret))
			return (ret);
		else
			return (first_free_nb_player(vm));
	}
	else
		return (first_free_nb_player(vm));
	return (0);
}

int		srch_players(t_vm *vm, int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 1;
	vm->nb_player = 0;
	while (i < argc)
	{
		if ((tmp = ft_strstr(argv[i], ".cor")) && !tmp[4])
		{
			vm->nb_player++;
			if (vm->nb_player > MAX_PLAYERS)
				error("Too many champs\n");
			new_player(vm, get_nb_player(vm, argv, i), argv[i]);
		}
		i++;
	}
	if (vm->nb_player)
		return (0);
	else
		return (1);
}

int		check_arg(t_vm *vm, int argc, char **argv)
{
	vm->dump = srch_nb_dump(argc, argv);
	vm->ncurses = srch_ncurses(argc, argv);
	vm->verbosity = srch_verbose(argc, argv);
	if (srch_players(vm, argc, argv))
		return (1);
	return (0);
}
