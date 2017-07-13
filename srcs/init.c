/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:42:39 by lchety            #+#    #+#             */
/*   Updated: 2017/07/13 12:22:54 by lchety           ###   ########.fr       */
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
	vm->p_bag->pc = 0;
}

void	init_p_nb(t_vm *vm)
{//init le nombre de players
	vm->p_nb = 1;
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

	ft_memcpy(data, buff, ret);
	return (data);
}

int		get_prog_size(char *data)
{
	int ret;

	ret = 0x0;

	ret = ret | *data;
	ret = ret << 8;
	ret = ret | data[1];
	ret = ret << 8;
	ret = ret | data[2];
	ret = ret << 8;
	ret = ret | data[3];

	return (ret);
}

//c est un fill_mem, on remplit la memoire du code du player
void	write_player(t_vm *vm)
{
	char *data;
	int i;
	int j;
	int prog_size;

	j = 0;
	prog_size = 0;
	i = 0;
	i += 4; //magic
	i += 128 + 4; //prog_name

	data = get_data("resources/corewar/champs/ex.cor");

	prog_size = get_prog_size(data + i);

	printf("\n\n prog_size : %d\n", prog_size);

	i += 2048 + 4; //prog_comments
	i += 4; //prog size
	while (j < prog_size)
	{
		((char*)vm->mem)[j] = (unsigned char)data[i];
		// printf("%02x ", (unsigned char)data[i]);
		i++;
		j++;
	}
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

void	init_op_table(t_vm *vm)
{


}
