/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:43:34 by lchety            #+#    #+#             */
/*   Updated: 2017/11/29 18:46:01 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	name_color(int i)
{
	// NC_C_WHITE
	if (i == 1)
		attron(COLOR_PAIR(NC_P_GREEN_BLING));
	else if (i == 2)
		attron(COLOR_PAIR(NC_P_BLUE_BLING));
	else if (i == 3)
		attron(COLOR_PAIR(NC_P_RED_BLING));
	else if (i == 4)
		attron(COLOR_PAIR(NC_P_CYAN_BLING));
}

void	name_color_off(int i)
{
	// NC_C_WHITE
	if (i == 1)
		attroff(COLOR_PAIR(NC_P_GREEN_BLING));
	else if (i == 2)
		attroff(COLOR_PAIR(NC_P_BLUE_BLING));
	else if (i == 3)
		attroff(COLOR_PAIR(NC_P_RED_BLING));
	else if (i == 4)
		attroff(COLOR_PAIR(NC_P_CYAN_BLING));
}



int		display_players(t_vm *vm)
{
	int i;
	int b;

	b = 11;
	i = 1;
	while (i < vm->nb_player + 1)
	{
		attron(COLOR_PAIR(NC_P_WHITE));
		mvprintw(b, 3 * (MEM_SIZE / 64) + 6, "Player -%d : ", i);
		// attroff(A_STANDOUT);
		// attroff(COLOR_PAIR(NC_C_WHITE));
		// attroff(A_BOLD);
		// on_color(a);
		attron(A_BOLD);
		name_color(i);
		mvprintw(b, 3 * (MEM_SIZE / 64) + 8 + 10, "%s", vm->player[i].name);
		attron(COLOR_PAIR(NC_P_WHITE));
		// attroff(A_BOLD);
		// off_color(a);
		// attroff(A_INVIS);
		// attron(A_STANDOUT);
		// attron(COLOR_PAIR(NC_C_WHITE));
		mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1, "Last live : ");
		if (!vm->player[i].last_live)
			mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "0");
		else
			mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "%d   ", vm->player[i].last_live + 1);
		mvprintw(b + 2, 3 * (MEM_SIZE / 64) + 6 + 1, "Live in current period : %d      ",
		vm->player[i].life_signal);
		b += 4;
		i++;
	}
	return (b);
}


void		display_menu(t_vm *vm)
{
	int line;

	attron(COLOR_PAIR(NC_P_WHITE));
	if (vm->pause == 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** PAUSED **");
	if (vm->pause != 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** RUNNING **");
	mvprintw(4, 3 * (MEM_SIZE / 64) + 6, "Speed : %d  ",
	100 - (vm->delay / 10000));
	mvprintw(7, 3 * (MEM_SIZE / 64) + 6, "Cycles : %d    ", vm->cycle);
	mvprintw(9, 3 * (MEM_SIZE / 64) + 6, "Processes : %d     ", count_proc(vm));

	line = display_players(vm);
	display_breakdown(vm, line);




	// int a = 1;
	// int b = 11;
	attroff(A_BOLD);
}
