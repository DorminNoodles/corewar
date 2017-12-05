/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:42:39 by lchety            #+#    #+#             */
/*   Updated: 2017/12/05 22:32:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*get_data(char *filename, char *buff)
{
	int		fd;
	// char	buff[sizeof(t_header) + CHAMP_MAX_SIZE];
	// char	*data;
	int		ret;

	fd = 0;
	ret = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("File\n");
	ret = read(fd, buff, sizeof(t_header) + CHAMP_MAX_SIZE);
	if (ret < (int)sizeof(t_header))
		error("File size error\n");
	// if (!(data = ft_memalloc(ret + 1)))
	// 	error("Malloc\n");
	// ft_memcpy(data, buff, ret);
	return (buff);
}

int		get_prog_size(char *data)
{
	int ret;

	data += MAGIC_NB;
	data += PROG_NAME;
	ret = 0x0;
	ret = ret | (unsigned char)*data;
	ret = ret << 8;
	ret = ret | (unsigned char)data[1];
	ret = ret << 8;
	ret = ret | (unsigned char)data[2];
	ret = ret << 8;
	ret = ret | (unsigned char)data[3];
	if (ret > CHAMP_MAX_SIZE)
		error("Champ is too big\n");
	return (ret);
}

void	init_vm(t_vm *vm)
{
	vm->nb_player = 0;
	vm->lives_in_cycle = 0;
	vm->ctd = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->cycle = 0;
	vm->boost = 0;
	vm->proc = NULL;
	vm->last_one = NULL;
	vm->pause = 1;
	vm->ncurses = 0;
	vm->delay = NCURSES_DELAY;
	vm->ctd_check = 0;
	vm->next_ctd = CYCLE_TO_DIE;
	vm->dump = -1;
	vm->debug = 0;
	vm->winner = 0;
	ft_bzero(vm->player, sizeof(t_player) * 5);
	ft_bzero(vm->ram, sizeof(t_mem) * MEM_SIZE);
}

void	write_player(t_vm *vm, int nb, int num)
{
	int		i;
	char	*data;
	int		prog_size;
	char	buff[sizeof(t_header) + CHAMP_MAX_SIZE];


	i = (MEM_SIZE / vm->nb_player) * num;
	data = get_data(vm->player[nb].file_name, buff);
	ft_memcpy(vm->player[nb].name, data + MAGIC_NB, PROG_NAME);
	vm->player[nb].name[PROG_NAME_LENGTH] = '\0';
	if (!ft_strlen(vm->player[nb].name))
		error("Empty name\n");
	ft_memcpy(vm->player[nb].comments, data + MAGIC_NB
			+ PROG_NAME + PROG_SIZE, PROG_COMS);
	vm->player[nb].comments[COMMENT_LENGTH] = '\0';
	if (!ft_strlen(vm->player[nb].comments))
		error("Empty comments\n");
	prog_size = get_prog_size(data);
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		nb, prog_size, vm->player[nb].name, vm->player[nb].comments);
	data = data + SRC_BEGIN;
	prog_size += i;
	while (i < prog_size)
	{
		vm->ram[i % MEM_SIZE].mem = (unsigned char)*data;
		vm->ram[i % MEM_SIZE].num = (num + 1) * -1;
		data++;
		i++;
	}
}

void	init_process(t_vm *vm)
{
	int i;

	i = 0;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
			add_process(vm, create_process(vm, i * (-1)));
		i++;
	}
}
