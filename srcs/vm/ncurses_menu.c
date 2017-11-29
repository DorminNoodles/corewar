/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:43:34 by lchety            #+#    #+#             */
/*   Updated: 2017/11/29 16:02:39 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_menu(t_vm *vm)
{
	attron(COLOR_PAIR(NC_C_BASIC));
	if (vm->pause == 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** PAUSED **");
	if (vm->pause != 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** RUNNING **");
	mvprintw(4, 3 * (MEM_SIZE / 64) + 6, "Speed : %d  ",
	100 - (vm->delay / 10000));
	mvprintw(7, 3 * (MEM_SIZE / 64) + 6, "Cycles : %d    ", vm->cycle);
	mvprintw(9, 3 * (MEM_SIZE / 64) + 6, "Processes : %d     ", count_proc(vm));

	display_players();




	// int a = 1;
	// int b = 11;
	attroff(A_BOLD);
}
