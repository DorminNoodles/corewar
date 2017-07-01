/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 14:42:39 by lchety            #+#    #+#             */
/*   Updated: 2017/07/01 16:48:18 by lchety           ###   ########.fr       */
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

void	init_each_players(t_vm *vm)
{
	int nb;

	nb = 0;
	init_p_nb(vm);
	while (nb < vm->p_nb)
	{
		init_p_bag(vm, nb);
		nb++;
	}

}

void	init_vm(t_vm *vm)
{//appel de toutes les fonctions d init
	init_mem(vm);
	init_each_players(vm);
}
