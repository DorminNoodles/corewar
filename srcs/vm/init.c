/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:42:39 by lchety            #+#    #+#             */
/*   Updated: 2017/11/23 20:13:41 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_mem(t_vm *vm)
{//init la memoire 4096 * un octet

	ft_bzero(&vm->ram, sizeof(t_mem) * MEM_SIZE);

}

// void	init_nb_player(t_vm *vm)
// {//init le nombre de players
// 	vm->nb_player = 1;
//
// 	vm->life_signal[0] = 0;
//
// 	// ugly, i know.
//
// 	vm->life_signal[1] = -1;
// 	vm->life_signal[2] = -1;
// 	vm->life_signal[3] = -1;
// 	// vm->life_signal initialisation based on it.
//
// }

char	*get_data(char *filename)
{
	int		fd;
	char	buff[4096];
	char	*data;
	int		ret;

	fd = 0;
	ret = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("error : file\n");
	ret = read(fd, buff, 4096);
	data = ft_memalloc(ret + 1);

	int i = 0;

	ft_memcpy(data, buff, ret);
	return (data);
}

int		get_prog_size(char *data)
{
	int ret;

	data += 4; //magic
	data += 128 + 4; //prog_name
	ret = 0x0;
	ret = ret | (unsigned char)*data;
	ret = ret << 8;
	ret = ret | (unsigned char)data[1];
	ret = ret << 8;
	ret = ret | (unsigned char)data[2];
	ret = ret << 8;
	ret = ret | (unsigned char)data[3];
	return (ret);
}

void	init_vm(t_vm *vm)
{
	vm->nb_player = 0;
	vm->lives_in_cycle = 0;
	vm->ctd = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->cycle = 0;
	vm->proc = NULL;
	vm->last_one = NULL;
	vm->pause = 1;
	vm->ncurses = 0;
	vm->delay = NCURSES_DELAY;
	vm->ctd_check = 0;
	vm->next_ctd = CYCLE_TO_DIE;
	vm->dump = -1;
	vm->debug = 0;
	ft_bzero(vm->player, sizeof(t_player) * 5);
}

void	write_player(t_vm *vm, int nb, int num)
{
	int		i;
	char	*data;
	char	*data_tmp;
	int		prog_size;

	i = (MEM_SIZE / vm->nb_player) * num;

	// printf("File Name %s\n", vm->player[nb].file_name);
	data = get_data(vm->player[nb].file_name);
 // 	printf("data = '%s'\n", data + MAGIC_NB);
	ft_memcpy(vm->player[nb].name, data + MAGIC_NB, PROG_NAME);
	// vm->player[nb].name[ft_strlen(data + MAGIC_NB)] = '\0';
	vm->player[nb].name[PROG_NAME_LENGTH] = '\0';
	ft_memcpy(vm->player[nb].comments, data + MAGIC_NB + PROG_NAME + PROG_SIZE, PROG_COMS);
	vm->player[nb].comments[COMMENT_LENGTH] = '\0';
	prog_size = get_prog_size(data);
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", nb, prog_size,
	vm->player[nb].name, vm->player[nb].comments);
	data_tmp = data + SRC_BEGIN;

	// printf("I => %d\n", i);
	prog_size += i;
	while (i < prog_size)
	{
		//vm->mem[i % MEM_SIZE] = (unsigned char)*data_tmp;
		vm->ram[i % MEM_SIZE].mem = (unsigned char)*data_tmp;
		// printf(">__&>>> %d\n", (num + 1) * -1);
		vm->ram[i % MEM_SIZE].num = (num + 1) * -1;
		data_tmp++;
		i++;
	}
	// show_mem(vm);
}

// int		*init_registre(int id)
// {
// 	int i;
// 	int	*reg;
//
// 	i = 0;
//
// 	if (!(reg = (int*)ft_memalloc(sizeof(int) * REG_NUMBER)))
// 		error("error : MALLOC\n");
// 	reg[0] = id;
// 	return (reg);
// }

void	add_process(t_vm *vm, t_proc *proc)
{
	t_proc	*tmp;

	// tmp = vm->proc;
	if (vm->proc)
	{
		proc->next = vm->proc;
		vm->proc = proc;
	}
	else
	{
		vm->proc = proc;
	}
}

void	init_process(t_vm *vm)
{
	int i;

	i = 0;
	while (i <= MAX_PLAYERS)
	{
		// printf("loop init process i = %d | vm->player[i].active = %d\n", i, vm->player[i].active);
		if (vm->player[i].active)
			add_process(vm, create_process(vm, i * (-1)));
		i++;
	}
}

// void	init_each_players(t_vm *vm)
// {
// 	int nb;
//
// 	nb = 0;
// 	init_nb_player(vm);
// 	init_process(vm);
// }

void	create_players(t_vm *vm)
{//appel de toutes les fonctions d init
	int i;
	int j;

	i = 1;
	j = 0;
	// printf("Debug : init_vm nb_player %d\n", vm->nb_player);
	init_mem(vm);
	ft_printf("Introducing contestants...\n");
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			write_player(vm, i, j);
			j++;
		}
		i++;
	}
	init_process(vm);
	// init_each_players(vm);
	// init_optab(vm);
	// vm->cycle = 0;
	// vm->ctd = CYCLE_TO_DIE;
	// printf("SEGV\n");
}
