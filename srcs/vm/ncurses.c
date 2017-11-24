/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:07:36 by lchety            #+#    #+#             */
/*   Updated: 2017/11/24 19:51:35 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	colors_init(void)
{
	init_color(NC_C_GREY, 350, 350, 350);//basic grey
	init_color(NC_C_WHITE, 1000, 1000, 1000);//basic white
	init_pair(NC_C_BASIC, NC_C_GREY, COLOR_BLACK);//basic
	init_pair(NC_C_WHITE, COLOR_BLACK, NC_C_WHITE);//basic white on black
	init_pair(NC_C_GREYBLACK, NC_C_GREY, NC_C_GREY);//grey back

	init_pair(NC_C_GREEN, COLOR_GREEN, COLOR_BLACK);//player_1
	init_color(NC_C_GREEN_FLUO, 150, 1000, 150);//fluo_green
	init_color(NC_C_GREEN_BLING, 500, 1000, 500);//blingbling_green
	init_pair(NC_C_GREEN_LIGHT, COLOR_GREEN, NC_C_GREEN_FLUO);//player_1_highlight
	init_pair(NC_C_GREEN_BLACK, NC_C_GREEN_BLING, COLOR_BLACK);//player_1_blingbling

	init_pair(NC_C_BLUE, COLOR_BLUE, COLOR_BLACK);//player_2
	init_color(COLOR_BLUE, 200, 200, 800);//blue change
	init_color(NC_C_BLUE_FLUO, 500, 500, 1000);//fluo_blue
	init_pair(NC_C_BLUE_LIGHT, COLOR_BLUE, NC_C_BLUE_FLUO);//player_2_highlight
	init_pair(NC_C_BLUE_BLING, NC_C_BLUE_FLUO, COLOR_BLACK);//player_2_blingbling

	init_pair(NC_C_RED, COLOR_RED, COLOR_BLACK);
	init_color(NC_C_RED_FLUO, 1000, 250, 250);
	init_color(NC_C_RED_BLING, 1000, 400, 400);
	init_pair(NC_C_RED_LIGHT, COLOR_RED, NC_C_RED_FLUO);
	init_pair(NC_C_RED_BLACK, NC_C_RED_BLING, COLOR_BLACK);

	init_pair(NC_C_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_color(COLOR_YELLOW, 650, 650, 0); // change yellow color
	init_color(NC_C_YELLOW_FLUO, 750, 750, 50);
	init_color(NC_C_YELLOW_BLING, 900, 900, 50);
	init_pair(NC_C_YELLOW_LIGHT, COLOR_YELLOW, NC_C_YELLOW_FLUO);
	init_pair(NC_C_YELLOW_BLACK, NC_C_YELLOW_BLING, COLOR_BLACK);

	init_pair(NC_C_LIFE_LIGHT, COLOR_GREEN, COLOR_RED);//life highlight

}

static void	ram_init(t_vm *vm)
{
	int	i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		attron(COLOR_PAIR(NC_C_BASIC));
		if ((is_pc(vm, i)))
		{
			if (vm->ram[i].num == -1)
				attron(COLOR_PAIR(NC_C_GREEN_LIGHT));
			else if (vm->ram[i].num == -2)
				attron(COLOR_PAIR(NC_C_BLUE_LIGHT));
			else if (vm->ram[i].num == -3)
				attron(COLOR_PAIR(NC_C_RED_LIGHT));
			else if (vm->ram[i].num == -4)
				attron(COLOR_PAIR(NC_C_YELLOW_LIGHT));
			attron(A_STANDOUT);
		}
		else if (vm->ram[i].num == -1)
		{
			attron(COLOR_PAIR(NC_C_GREEN));
		}
		else if (vm->ram[i].num == -2)
		{
			attron(COLOR_PAIR(NC_C_BLUE));
		}
		else if (vm->ram[i].num == -3)
		{
			attron(COLOR_PAIR(NC_C_RED));
		}
		else if (vm->ram[i].num == -4)
		{
			attron(COLOR_PAIR(NC_C_YELLOW));
		}
		if (vm->ram[i].blingbling)
		{
			attron(A_BOLD);
			if (vm->ram[i].num == -1)
				attron(COLOR_PAIR(NC_C_GREEN_BLACK));
			if (vm->ram[i].num == -2)
				attron(COLOR_PAIR(NC_C_BLUE_BLING));
			if (vm->ram[i].num == -3)
				attron(COLOR_PAIR(NC_C_RED_BLACK));
			if (vm->ram[i].num == -4)
				attron(COLOR_PAIR(NC_C_YELLOW_BLACK));
			vm->ram[i].blingbling--;
		}
		if (vm->ram[i].live)
		{
			attron(COLOR_PAIR(NC_C_LIFE_LIGHT));
			vm->ram[i].live--;
		}
		mvprintw((3 + i / 64), (3 + (i % 64) * 3), "%02x", (unsigned char)vm->ram[i].mem);
		attroff(A_STANDOUT);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(NC_C_GREY));
	}
}

void on_color(int player)
{
	if (player == 1)
		attron(COLOR_PAIR(NC_C_GREEN));
	else if (player == 2)
		attron(COLOR_PAIR(NC_C_BLUE));
	else if (player == 3)
		attron(COLOR_PAIR(NC_C_RED));
	else
		attron(COLOR_PAIR(NC_C_YELLOW));
}

void off_color(int player)
{
	if (player == 1)
		attroff(COLOR_PAIR(NC_C_GREEN));
	else if (player == 2)
		attroff(COLOR_PAIR(NC_C_BLUE));
	else if (player == 3)
		attroff(COLOR_PAIR(NC_C_RED));
	else
		attroff(COLOR_PAIR(NC_C_YELLOW));
}

void	call_ncurses(t_vm *vm)
{
	int i;
	int	j;
	int ret;

	i = -1;
	ret = 0;
	colors_init();
	ram_init(vm);
	attron(COLOR_PAIR(NC_C_GREYBLACK));
	attron(A_INVIS);
	while (++i < MEM_SIZE / 64 + 6)
	{
		j = -1;
		while (++j < 3 * (MEM_SIZE / 64) + 50)
		{
			if (i == 0 || j == 0 || i == MEM_SIZE / 64 + 5
					|| j == 3 * (MEM_SIZE / 64) + 4 ||
					j == 3 * (MEM_SIZE / 64) + 49)
				mvprintw(i, j, "*");
		}
	}
	attroff(COLOR_PAIR(NC_C_GREYBLACK));
	attroff(A_INVIS);
	attron(A_STANDOUT);
	attron(COLOR_PAIR(NC_C_WHITE));
	attron(A_BOLD);
	// mvprintw(32, 3 * (MEM_SIZE / 64) + 6, "%d <= pause", vm->pause);
	if (vm->pause == 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** PAUSED **");
	if (vm->pause != 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** RUNNING **");
	mvprintw(4, 3 * (MEM_SIZE / 64) + 6, "Cycles/second limit : %d", vm->delay);
	mvprintw(7, 3 * (MEM_SIZE / 64) + 6, "Cycles : %d", vm->cycle);
	mvprintw(9, 3 * (MEM_SIZE / 64) + 6, "Processes : %d", count_proc(vm));

	int a = 1;
	int b = 11;
	attroff(A_BOLD);
	while (a < vm->nb_player + 1)
	{
		mvprintw(b, 3 * (MEM_SIZE / 64) + 6, "Player -%d : ", a);
		attroff(A_STANDOUT);
		attroff(COLOR_PAIR(NC_C_WHITE));
		// attroff(A_BOLD);
		on_color(a);
		attron(A_BOLD);
		mvprintw(b, 3 * (MEM_SIZE / 64) + 8 + 10, "%s", vm->player[a].name);
		attroff(A_BOLD);
		off_color(a);
		attroff(A_INVIS);
		attron(A_STANDOUT);
		attron(COLOR_PAIR(NC_C_WHITE));
		mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1, "Last live : ");
		if (!vm->player[a].last_live)
			mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "0");
		else
			mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "%d", vm->player[a].last_live + 1);
		mvprintw(b + 2, 3 * (MEM_SIZE / 64) + 6 + 1, "Live in current period : %d",
		vm->player[a].life_signal);
		++a;
		b += 4;
	}
	//
	mvprintw(b, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for current period :", vm->ctd);
	mvprintw(b + 3, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for last period :", vm->ctd);

	mvprintw(b, 5 * (MEM_SIZE / 64) + 6, "CYCLE_TO_DIE : %d", vm->ctd);
	mvprintw(b + 7, 3 * (MEM_SIZE / 64) + 6, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(b + 9, 3 * (MEM_SIZE / 64) + 6, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(b + 11, 3 * (MEM_SIZE / 64) + 6, "MAX_CHECKS : %d", MAX_CHECKS);

	// printw("%i", MEM_SIZE);
	attroff(COLOR_PAIR(NC_C_WHITE));
	//attron(A_BOLD);
	attroff(A_BOLD);
	attroff(A_STANDOUT);
	// debug_display_proc(vm);


	refresh();
}

void	init_ncurses(WINDOW **w)
{
	*w = initscr();
	if (has_colors() == FALSE)
	{
		ft_printf("Your terminal does not support colors.\n");
		endwin();
		exit(1);
	}
	start_color();			/* Start color 			*/
	cbreak(); //getch() no block
	nodelay(*w, TRUE);
}
