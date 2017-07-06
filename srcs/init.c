/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:42:39 by lchety            #+#    #+#             */
/*   Updated: 2017/07/06 04:24:40 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_mem(t_vm *vm)
{//init la memoire 4096 * un octet
	if (!(vm->mem = (void*)ft_memalloc(MEM_SIZE)))
		error("error : malloc failed\n");
}

void	init_p_bag(t_vm *vm, int nb)
{//ca c est les donnes propre a un joueur son "sac"
	if(!(vm->p_bag = (t_bag*)ft_memalloc(sizeof(t_bag) * vm->p_nb)))
		error("error : malloc failed\n");

	vm->p_bag->id = nb;

}

void	init_p_nb(t_vm *vm)
{//init le nombre de players
	vm->p_nb = 2;

}

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
	while (i < ret)
	{
		printf("%02x ", (unsigned char)buff[i]);
		i++;
	}
	printf("\n EOF \n\n");
	ft_memcpy(data, buff, ret);
	return (data);
}

void	write_player(t_vm *vm)
{
	char *data;
	int i;

	i = 0;
	// i += 4; //magic
	// i += 128 + 1; //prog_name

	data = get_data("resources/corewar/champs/slider2.cor");

	while (i < 4096)
	{
		printf("%02x ", (unsigned char)data[i]);
		i++;
	}

	// while (i < 2048)
	// {
	// 	printf(" > %02x \n", (unsigned char)data[i]);
	// 	i++;
	// 	// printf("    \nfuck > %d    \n", (unsigned int)data[i + 1]);
	// }
}

void	init_each_players(t_vm *vm)
{
	int nb;

	nb = 0;
	init_p_nb(vm);
	while (nb < vm->p_nb)
	{
		init_p_bag(vm, nb);
		write_player(vm);
		nb++;
	}

}

void	init_vm(t_vm *vm)
{//appel de toutes les fonctions d init
	init_mem(vm);
	init_each_players(vm);
}
