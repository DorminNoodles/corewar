/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_breakdown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:06:02 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/29 17:45:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int loop_breakdown(int line, int col, int until)
{
  int i;

  i = 0;
  while (i < until && i + col <= BREAK_DIS)
  {
    mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + i + col, "-");
    ++i;
  }
  return (i);
}

int get_dv(t_vm *vm, int live)
{
  int dv;

  dv = 0;
  if (live)
  {
    dv = (BREAK_DIS / live);
    if (BREAK_DIS % live)
      ++dv;
  }
  return (dv);
}

int last_breakdown(t_vm *vm, int line)
{
  int i;
  int p;
  int col;

  p = 1;
  col = 1;
  while (p <= MAX_PLAYERS)
  {
    on_color(p);
    i = 0;
    while (i < vm->player[p].last_period)
    {
      mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + i + col, "-");
      ++i;
    }
    col += i;
    off_color(p);
    ++p;
  }
  while (col <= BREAK_DIS)
  {
    mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + col, "-");
    ++col;
  }
  attron(COLOR_PAIR(NC_C_WHITE));
  mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + col, "]");
  return (col);
}

int current_breakdown(t_vm *vm, int line, int tot_live, int dv)
{
  int p;
  int i;
  int col;
  int p_lives;

  p = 1;
  col = 1;
  while (p <= MAX_PLAYERS)
  {
    if (tot_live)
    {
      p_lives = dv * vm->player[p].life_signal;
      if (BREAK_DIS % tot_live && p_lives)
        ++p_lives;
    }
    else
      p_lives = 0;
    on_color(p);
    i = loop_breakdown(line, col, p_lives);
    vm->player[p].tot = i;
    col += i;
    off_color(p);
    ++p;
  }
  return (col);
}

void init_breakdown(t_vm *vm, int line)
{
  int col;
  int dv;
  int tot_live;

	mvprintw(line, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for current period :");
	mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6, "[");
	attroff(COLOR_PAIR(NC_C_WHITE));
	tot_live = get_nb_live(vm);
  dv = get_dv(vm, tot_live);
  col = current_breakdown(vm, line, tot_live, dv);
  while (col <= BREAK_DIS)
  {
  	mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6 + col, "-");
  	++col;
  }
	attron(COLOR_PAIR(NC_C_WHITE));
  mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6 + col, "]");
  mvprintw(line + 3, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for last period :");
  mvprintw(line + 4, 3 * (MEM_SIZE / 64) + 6, "[");
  attroff(COLOR_PAIR(NC_C_WHITE));
  col = last_breakdown(vm, line + 4);

}

// void display_breakdown(t_vm *vm, int a)
// {
// 	int i;
// 	int j;
// 	int p;
// 	int di;
// 	int tot;
// 	int live;

	// p = 1;
	// mvprintw(a, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for current period :");
	// mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6, "[");
	// attroff(A_STANDOUT);
	// attroff(COLOR_PAIR(NC_C_WHITE));
	// live = get_nb_live(vm);
	// j = 1;
	// while (p <= MAX_PLAYERS)
	// {
	// 	if (live)
	// 	{
	// 		di = (BREAK_DIS / live);
	// 		if (BREAK_DIS % live)
	// 			++di;
	// 		tot = di * vm->player[p].life_signal;
	// 		if (BREAK_DIS % live && tot)
	// 			++tot;
	// 	}
	// 	else
	// 		tot = 0;
	// 	on_color(p);
	// 	i = 0;
	// 	while (i < tot && i + j <= BREAK_DIS)
	// 	{
	// 		mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + i + j, "-");
	// 		++i;
	// 	}
	// 	vm->player[p].tot = i;
	// 	j += i;
	// 	off_color(p);
	// 	++p;
	// }


	// while (j <= BREAK_DIS)
	// {
	// 	mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + j, "-");
	// 	++j;
	// }
	// attroff(A_INVIS);
	// attron(A_STANDOUT);
	// attron(COLOR_PAIR(NC_C_WHITE));
	// mvprintw(a + 1, 3 * (MEM_SIZE / 64) + 6 + j, "]");
	// mvprintw(a + 3, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for last period :");
	// mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6, "[");
	// attroff(A_STANDOUT);
	// attroff(COLOR_PAIR(NC_C_WHITE));
	// p = 1;
	// j = 1;
	// while (p <= MAX_PLAYERS)
	// {
	// 	on_color(p);
	// 	i = 0;
	// 	while (i < vm->player[p].last_period)
	// 	{
	// 		mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + i + j, "-");
	// 		++i;
	// 	}
	// 	j += i;
	// 	off_color(p);
	// 	++p;
	// }
	// while (j <= BREAK_DIS)
	// {
	// 	mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + j, "-");
	// 	++j;
	// }
	// attroff(A_INVIS);
	// attron(A_STANDOUT);
	// attron(COLOR_PAIR(NC_C_WHITE));
	// mvprintw(a + 4, 3 * (MEM_SIZE / 64) + 6 + j, "]");
// }
