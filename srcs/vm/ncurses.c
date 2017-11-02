/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:07:36 by lchety            #+#    #+#             */
/*   Updated: 2017/11/02 17:33:01 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_ncurses(WINDOW **w)
{
	*w = initscr();
	start_color();			/* Start color 			*/
	cbreak(); //getch() no block
	nodelay(*w, TRUE);
}

void	call_ncurses(t_vm *vm)
{
	int i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;

	init_color(35, 350, 350, 350);//basic grey
	init_color(40, 1000, 1000, 1000);//basic white
	init_pair(15, 35, COLOR_BLACK);//basic
	init_pair(40, COLOR_BLACK, 40);//basic white on black
	init_pair(41, 35, 35);//grey back
	init_pair(20, COLOR_GREEN, COLOR_BLACK);//player_1

	init_color(36, 150, 1000, 150);//fluo_green
	init_color(38, 500, 1000, 500);//blingbling_green
	init_pair(21, COLOR_GREEN, 36);//player_1_highlight
	init_pair(24, 38, COLOR_BLACK);//player_1_blingbling

	init_pair(22, COLOR_BLUE, COLOR_BLACK);//player_2
	init_color(COLOR_BLUE, 200, 200, 800);//blue change

	init_color(37, 400, 400, 1000);//fluo_blue
	init_pair(23, COLOR_BLUE, 37);//player_2_highlight
	init_pair(25, 37, COLOR_BLACK);//player_2_blingbling

	init_pair(26, COLOR_GREEN, COLOR_RED);//life highlight

	move(0,0);
	while (i < MEM_SIZE)
	{
		// printf("FOOOOOO\n");
		attron(COLOR_PAIR(15));
		move(3 + i / 64, 3 + (i % 64) * 3);
		if ((is_pc(vm, i)))
		{
			if (vm->ram[i].num == -1)
				attron(COLOR_PAIR(21));
			else if (vm->ram[i].num == -2)
				attron(COLOR_PAIR(23));
			attron(A_STANDOUT);
		}
		else if (vm->ram[i].num == -1)
		{
			attron(COLOR_PAIR(20));
		}
		else if (vm->ram[i].num == -2)
		{
			attron(COLOR_PAIR(22));
		}

		if (vm->ram[i].blingbling)
		{
			attron(A_BOLD);
			if (vm->ram[i].num == -1)
				attron(COLOR_PAIR(24));
			if (vm->ram[i].num == -2)
				attron(COLOR_PAIR(25));
			vm->ram[i].blingbling--;
		}

		if (vm->ram[i].live)
		{
			attron(COLOR_PAIR(26));
			vm->ram[i].live--;
		}

		printw("%02x", (unsigned char)vm->ram[i].mem);
		attroff(A_STANDOUT);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(35));
		i++;
	}
	i = -1;
//	attron(A_STANDOUT);
	attron(COLOR_PAIR(41));
	attron(A_INVIS);
	while (++i < MEM_SIZE / 64 + 6)
	{
		j = -1;
		while (++j < 3 * (MEM_SIZE / 64) + 50)
		{
			if (i == 0 || j == 0 || i == MEM_SIZE / 64 + 5
					|| j == 3 * (MEM_SIZE / 64) + 4 ||
					j == 3 * (MEM_SIZE / 64) + 49)
			{
				mvprintw(i, j, "*");
			}
		}
	}
//	attroff(A_STANDOUT);
	attroff(COLOR_PAIR(41));
	attroff(A_INVIS);
	attron(A_STANDOUT);
	attron(COLOR_PAIR(40));
	attron(A_BOLD);
	if (vm->pause == 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** PAUSED **");
	if (vm->pause != 1)
		mvprintw(2, 3 * (MEM_SIZE / 64) + 6, "** RUNNING **");
	mvprintw(5, 3 * (MEM_SIZE / 64) + 6, "Delay : %d", vm->delay);
	mvprintw(10, 3 * (MEM_SIZE / 64) + 6, "Cycles : %d", vm->cycle);
	mvprintw(12, 3 * (MEM_SIZE / 64) + 6, "Keycode : %d", vm->keycode);
	mvprintw(14, 3 * (MEM_SIZE / 64) + 6, "Proc Nb : %d", count_proc(vm));
	mvprintw(22, 3 * (MEM_SIZE / 64) + 6, "CYCLE_TO_DIE : %d", vm->ctd);
	mvprintw(24, 3 * (MEM_SIZE / 64) + 6, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(26, 3 * (MEM_SIZE / 64) + 6, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(28, 3 * (MEM_SIZE / 64) + 6, "MAX_CHECKS : %d", MAX_CHECKS);
	mvprintw(30, 3 * (MEM_SIZE / 64) + 6, "Live P1 : %08d", vm->player[1].life_signal);
	printw("%i", MEM_SIZE);
	attroff(COLOR_PAIR(40));
	//attron(A_BOLD);
	attroff(A_BOLD);
	attroff(A_STANDOUT);
	// debug_display_proc(vm);

	refresh();

}
