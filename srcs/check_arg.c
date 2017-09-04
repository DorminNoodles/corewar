/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:49:01 by lchety            #+#    #+#             */
/*   Updated: 2017/09/03 12:32:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_strargv(int argc, char **argv, char *str)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strstr(argv[i], "-dump"))
			return (i);
		i++;
	}
	return (0);
}

void	srch_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-dump")))
	{
		if (ret + 1 < argc)
			nb = ft_atoi(argv[ret + 1]);
		printf("dump => %d\n", nb);
	}
}

int		srch_nb_player(int argc, char **argv, int arg_num)
{
	if (arg_num - 2 > 0)
		if (ft_strstr(argv[arg_num - 2], "-n"))
			return (1);
	return (0);
	//si "pouet-npouet" a corriger
}

int		get_nb_player(int argc, char **argv, int arg_num)
{
	int ret;

	ret = 0;
	if (srch_nb_player(argc, argv, arg_num))
	{
		// printf("here\n");
		ret = ft_atoi(argv[arg_num - 1]);
		if (ret > 0 && ret < 5)//add if num already takes
			return (ret);
	}
	//return le premier num disponible
	return (0);
}

int		srch_players(t_vm *vm, int argc, char **argv)
{
	int i;
	int nb_p;
	char *tmp;

	i = 1;
	nb_p = 0;
	while (i < argc && nb_p < 4)
	{
		if ((tmp = ft_strstr(argv[i], ".cor")) && !tmp[4])
		{
			nb_p++;
			printf("Find Player %d !\n", get_nb_player(argc, argv, i));
			vm->files_name[get_nb_player(argc, argv, i)] = argv[i];
		}
		i++;
	}
	if (nb_p)
		return (0);
	else
		return (1);
}

int		check_arg(t_vm *vm, int argc, char **argv)
{
	srch_nb_dump(argc, argv);
	if(srch_players(vm, argc, argv))
		return(1);

	return (0);
}
