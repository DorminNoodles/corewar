/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:25:41 by lchety            #+#    #+#             */
/*   Updated: 2017/11/29 15:58:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		display_pc(t_vm *vm, int i)
{
	if (vm->ram[i].num == -1)
		attron(COLOR_PAIR(NC_C_GREEN_LIGHT));
	else if (vm->ram[i].num == -2)
		attron(COLOR_PAIR(NC_C_BLUE_LIGHT));
	else if (vm->ram[i].num == -3)
		attron(COLOR_PAIR(NC_C_RED_LIGHT));
	else if (vm->ram[i].num == -4)
		attron(COLOR_PAIR(NC_C_YELLOW_LIGHT));
	vm->ram[i].pc = 0;
}

static void		mem_main(t_vm *vm)
{
	int	i;

	i = 0;
	// attron(A_BOLD);
	while (i < MEM_SIZE)
	{
		attron(COLOR_PAIR(NC_C_BASIC));
		if (vm->ram[i].num == -1)
			attron(COLOR_PAIR(NC_C_GREEN));
		else if (vm->ram[i].num == -2)
			attron(COLOR_PAIR(NC_C_BLUE));
		else if (vm->ram[i].num == -3)
			attron(COLOR_PAIR(NC_C_RED));
		else if (vm->ram[i].num == -4)
			attron(COLOR_PAIR(NC_C_YELLOW));
		if (vm->ram[i].blingbling)
		{
			attron(A_BOLD);
			vm->ram[i].blingbling--;
		}
		if (vm->ram[i].pc)
			display_pc(vm, i);
		// if (vm->ram[i].live)
		// {
		// 	attron(COLOR_PAIR(NC_C_LIFE_LIGHT));
		// 	vm->ram[i].live--;
		// }
		mvprintw((3 + i / 64), (3 + (i % 64) * 3), "%02x", (unsigned char)vm->ram[i].mem);
		attroff(A_BOLD);
		i++;
	}
	// attroff(A_STANDOUT);
	// attroff(COLOR_PAIR(NC_C_GREY));
}

// static void		display_bling()


void	display_mem(t_vm *vm)
{
	mem_main(vm);

}
