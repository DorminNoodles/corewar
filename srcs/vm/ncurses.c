/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:07:36 by lchety            #+#    #+#             */
/*   Updated: 2017/11/30 16:32:03 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	colors_init(void)
{
	init_color(NC_C_WHITE, 800, 800, 800);
	init_color(NC_C_BLACK, 0, 0, 0);
	init_color(NC_C_GREY, 350, 350, 350);
	init_color(NC_C_GREEN, 410, 750, 300);
	init_color(NC_C_BLUE, 200, 300, 600);
	init_color(NC_C_RED, 700, 150, 200);
	init_color(NC_C_CYAN, 100, 500, 600);

	init_color(NC_C_GREEN_BLING, 600, 1000, 500);
	init_color(NC_C_BLUE_BLING, 400, 600, 1000);
	init_color(NC_C_RED_BLING, 1000, 300, 400);
	init_color(NC_C_CYAN_BLING, 300, 1000, 1000);


	init_pair(NC_P_GREY, NC_C_GREY, NC_C_BLACK);
	init_pair(NC_P_WHITE, NC_C_WHITE, NC_C_BLACK);
	init_pair(NC_P_GREEN, NC_C_GREEN, NC_C_BLACK);
	init_pair(NC_P_BLUE, NC_C_BLUE, NC_C_BLACK);
	init_pair(NC_P_RED, NC_C_RED, NC_C_BLACK);
	init_pair(NC_P_CYAN, NC_C_CYAN, NC_C_BLACK);

	init_pair(NC_P_GREEN_BLING, NC_C_GREEN_BLING, NC_C_BLACK);
	init_pair(NC_P_BLUE_BLING, NC_C_BLUE_BLING, NC_C_BLACK);
	init_pair(NC_P_RED_BLING, NC_C_RED_BLING, NC_C_BLACK);
	init_pair(NC_P_CYAN_BLING, NC_C_CYAN_BLING, NC_C_BLACK);

	init_pair(NC_P_GREEN_PC, NC_C_BLACK, NC_C_GREEN);
	init_pair(NC_P_BLUE_PC, NC_C_BLACK, NC_C_BLUE);
	init_pair(NC_P_RED_PC, NC_C_BLACK, NC_C_RED);
	init_pair(NC_P_CYAN_PC, NC_C_BLACK, NC_C_CYAN);

	init_pair(NC_P_GREEN_LIFE, NC_C_WHITE, NC_C_GREEN);
	init_pair(NC_P_BLUE_LIFE, NC_C_WHITE, NC_C_BLUE);
	init_pair(NC_P_RED_LIFE, NC_C_WHITE, NC_C_RED);
	init_pair(NC_P_CYAN_LIFE, NC_C_WHITE, NC_C_CYAN);

	init_pair(NC_P_WHITE_B, NC_C_WHITE, NC_C_WHITE);

	// init_color(NC_C_GREY, 350, 350, 350);//basic grey
	// // init_color(NC_C_WHITE, 1000, 1000, 1000);//basic white
	// init_pair(NC_C_BASIC, NC_C_GREY, COLOR_BLACK);//basic
	// init_pair(NC_C_WHITE, COLOR_WHITE, COLOR_BLACK);//basic white on black
	// init_pair(NC_C_GREYBLACK, NC_C_GREY, NC_C_GREY);//grey back
    //
	// init_pair(NC_C_GREEN, COLOR_GREEN, COLOR_BLACK);//player_1
	// init_color(NC_C_GREEN_FLUO, 150, 1000, 150);//fluo_green
	// init_color(NC_C_GREEN_BLING, 500, 1000, 500);//blingbling_green
	// init_pair(NC_C_GREEN_LIGHT, COLOR_GREEN, NC_C_GREEN_FLUO);//player_1_highlight
	// init_pair(NC_C_GREEN_BLACK, NC_C_GREEN_BLING, COLOR_BLACK);//player_1_blingbling
    //
	// init_pair(NC_C_BLUE, COLOR_BLUE, COLOR_BLACK);//player_2
	// init_color(COLOR_BLUE, 200, 200, 800);//blue change
	// init_color(NC_C_BLUE_FLUO, 500, 500, 1000);//fluo_blue
	// init_pair(NC_C_BLUE_LIGHT, COLOR_BLUE, NC_C_BLUE_FLUO);//player_2_highlight
	// init_pair(NC_C_BLUE_BLING, NC_C_BLUE_FLUO, COLOR_BLACK);//player_2_blingbling
    //
	// init_pair(NC_C_RED, COLOR_RED, COLOR_BLACK);
	// init_color(NC_C_RED_FLUO, 1000, 250, 250);
	// init_color(NC_C_RED_BLING, 1000, 400, 400);
	// init_pair(NC_C_RED_LIGHT, COLOR_RED, NC_C_RED_FLUO);
	// init_pair(NC_C_RED_BLACK, NC_C_RED_BLING, COLOR_BLACK);
    //
	// init_pair(NC_C_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	// init_color(COLOR_YELLOW, 650, 650, 0); // change yellow color
	// init_color(NC_C_YELLOW_FLUO, 750, 750, 50);
	// init_color(NC_C_YELLOW_BLING, 900, 900, 50);
	// init_pair(NC_C_YELLOW_LIGHT, COLOR_YELLOW, NC_C_YELLOW_FLUO);
	// init_pair(NC_C_YELLOW_BLACK, NC_C_YELLOW_BLING, COLOR_BLACK);
    //
	// init_pair(NC_C_LIFE_LIGHT, COLOR_GREEN, COLOR_RED);//life highlight

}



// void on_color(int player)
// {
// 	if (player == 1)
// 		attron(COLOR_PAIR(NC_C_GREEN));
// 	else if (player == 2)
// 		attron(COLOR_PAIR(NC_C_BLUE));
// 	else if (player == 3)
// 		attron(COLOR_PAIR(NC_C_RED));
// 	else
// 		attron(COLOR_PAIR(NC_C_YELLOW));
// }
//
// void off_color(int player)
// {
// 	if (player == 1)
// 		attroff(COLOR_PAIR(NC_C_GREEN));
// 	else if (player == 2)
// 		attroff(COLOR_PAIR(NC_C_BLUE));
// 	else if (player == 3)
// 		attroff(COLOR_PAIR(NC_C_RED));
// 	else
// 		attroff(COLOR_PAIR(NC_C_YELLOW));
// }

// int get_nb_live(t_vm *vm)
// {
// 	int i;
// 	int live;
//
// 	i = 1;
// 	live = 0;
// 	while (i <= MAX_PLAYERS)
// 	{
// 		live += vm->player[i].life_signal;
// 		++i;
// 	}
// 	return (live);
// }
//
// void display_breakdown(t_vm *vm, int a)
// {
// 	int i;
// 	int j;
// 	int p;
// 	int di;
// 	int tot;
// 	int live;
//
// 	p = 1;
// 	mvprintw(a, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for current period :");
// 	mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6, "[");
// 	attroff(A_STANDOUT);
// 	attroff(COLOR_PAIR(NC_C_WHITE));
// 	live = get_nb_live(vm);
// 	j = 1;
// 	while (p <= MAX_PLAYERS)
// 	{
// 		if (live)
// 		{
// 			di = (BREAK_DIS / live);
// 			if (BREAK_DIS % live)
// 				++di;
// 			tot = di * vm->player[p].life_signal;
// 			if (BREAK_DIS % live && tot)
// 				++tot;
// 		}
// 		else
// 			tot = 0;
// 		on_color(p);
// 		i = 0;
// 		while (i < tot && i + j <= BREAK_DIS)
// 		{
// 			mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + i + j, "-");
// 			++i;
// 		}
// 		vm->player[p].tot = i;
// 		j += i;
// 		off_color(p);
// 		++p;
// 	}
// 	while (j <= BREAK_DIS)
// 	{
// 		mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + j, "-");
// 		++j;
// 	}
// 	// attroff(A_INVIS);
// 	attron(A_STANDOUT);
// 	attron(COLOR_PAIR(NC_C_WHITE));
// 	mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + j, "]");
// 	mvprintw(a + 3, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for last period :");
// 	mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6, "[");
// 	attroff(A_STANDOUT);
// 	attroff(COLOR_PAIR(NC_C_WHITE));
// 	p = 1;
// 	j = 1;
// 	while (p <= MAX_PLAYERS)
// 	{
// 		on_color(p);
// 		i = 0;
// 		while (i < vm->player[p].last_period)
// 		{
// 			mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + i + j, "-");
// 			++i;
// 		}
// 		j += i;
// 		off_color(p);
// 		++p;
// 	}
// 	while (j <= BREAK_DIS)
// 	{
// 		mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + j, "-");
// 		++j;
// 	}
// 	attroff(A_INVIS);
// 	attron(A_STANDOUT);
// 	attron(COLOR_PAIR(NC_C_WHITE));
// 	mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + j, "]");
// }

void	border_ncurses(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	attron(COLOR_PAIR(NC_P_WHITE_B));
	while (++i < MEM_SIZE / 64 + 5)
	{
		j = -1;
		while (++j < 3 * (MEM_SIZE / 64) + 72)
		{
			if (i == 1 || j == 0 || i == MEM_SIZE / 64 + 4
					|| j == 3 * (MEM_SIZE / 64) + 5 ||
					j == 3 * (MEM_SIZE / 64) + 70
					|| j == 3 * (MEM_SIZE / 64) + 71 || j == 1)
				mvprintw(i, j, " ");
		}
	}
}

void	call_ncurses(t_vm *vm)
{
	int i;
	int	j;
	int ret;

	i = -1;
	ret = 0;
	if (!vm->ncurses)
		return ;
	if (vm->boost && !vm->winner && (vm->cycle % BOOST_CYCLES))
		return ;
	colors_init();
	border_ncurses(vm);
	display_mem(vm);
	display_menu(vm);
	controller(vm);
	usleep(vm->delay);
	// attron(COLOR_PAIR(NC_C_GREYBLACK));
	// attron(A_INVIS);
	// attroff(COLOR_PAIR(NC_C_GREYBLACK));
	// attroff(A_INVIS);
	// attron(A_STANDOUT);
	// attron(COLOR_PAIR(NC_C_WHITE));
	// attron(A_BOLD);
	// mvprintw(32, 3 * (MEM_SIZE / 64) + 6, "%d <= pause", vm->pause);
	// if (vm->pause == 1)
	// 	mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** PAUSED **");
	// if (vm->pause != 1)
	// 	mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** RUNNING **");
	// mvprintw(4, 3 * (MEM_SIZE / 64) + 6, "Speed : %d  ",
	// 100 - (vm->delay / 10000));
	// mvprintw(7, 3 * (MEM_SIZE / 64) + 6, "Cycles : %d    ", vm->cycle);
	// mvprintw(9, 3 * (MEM_SIZE / 64) + 6, "Processes : %d     ", count_proc(vm));

	// int a = 1;
	// int b = 11;
	// attroff(A_BOLD);
	// while (a < vm->nb_player + 1)
	// {
	// 	mvprintw(b, 3 * (MEM_SIZE / 64) + 6, "Player -%d : ", a);
	// 	attroff(A_STANDOUT);
	// 	attroff(COLOR_PAIR(NC_C_WHITE));
	// 	// attroff(A_BOLD);
	// 	on_color(a);
	// 	attron(A_BOLD);
	// 	mvprintw(b, 3 * (MEM_SIZE / 64) + 8 + 10, "%s", vm->player[a].name);
	// 	attroff(A_BOLD);
	// 	off_color(a);
	// 	attroff(A_INVIS);
	// 	attron(A_STANDOUT);
	// 	attron(COLOR_PAIR(NC_C_WHITE));
	// 	mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1, "Last live : ");
	// 	if (!vm->player[a].last_live)
	// 		mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "0");
	// 	else
	// 		mvprintw(b + 1, 3 * (MEM_SIZE / 64) + 6 + 1 + 25, "%d   ", vm->player[a].last_live + 1);
	// 	mvprintw(b + 2, 3 * (MEM_SIZE / 64) + 6 + 1, "Live in current period : %d      ",
	// 	vm->player[a].life_signal);
	// 	++a;
	// 	b += 4;
	// }
	// display_breakdown(vm, b);
	// mvprintw(b + 6, 3 * (MEM_SIZE / 64) + 6, "CYCLE_TO_DIE : %d     ", vm->ctd);
	// mvprintw(b + 8, 3 * (MEM_SIZE / 64) + 6, "CYCLE_DELTA : %d    ", CYCLE_DELTA);
	// mvprintw(b + 10, 3 * (MEM_SIZE / 64) + 6, "NBR_LIVE : %d    ", NBR_LIVE);
	// mvprintw(b + 12, 3 * (MEM_SIZE / 64) + 6, "MAX_CHECKS : %d    ", MAX_CHECKS);
    //
	// attroff(COLOR_PAIR(NC_C_WHITE));
	// attroff(A_BOLD);
	// attron(COLOR_PAIR(COLOR_BLACK));
	// attron(A_INVIS);
	// mvprintw((MEM_SIZE / 64) + 5, 0, "");

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
