/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_breakdown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:06:02 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/29 21:35:21 by rfulop           ###   ########.fr       */
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

int get_nb_live(t_vm *vm)
{
	int i;
	int live;

	i = 1;
	live = 0;
	while (i <= MAX_PLAYERS)
	{
		live += vm->player[i].life_signal;
		++i;
	}
	return (live);
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
    name_color(p);
    i = 0;
    while (i < vm->player[p].last_period)
    {
      mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + i + col, "-");
      ++i;
    }
    col += i;
    // name_color_off(p);
    ++p;
  }
  attron(COLOR_PAIR(NC_P_WHITE));
  while (col <= BREAK_DIS)
  {
    mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + col, "-");
    ++col;
  }
  // attron(COLOR_PAIR(NC_P_WHITE));
  mvprintw(line, 3 * (MEM_SIZE / 64) + 6 + col, "]");
  return (line);
}

int current_breakdown(t_vm *vm, int line, int tot_live, int dv)
{
  int p;
  int i;
  int col;
  float perdiv;
  float p_lives;

  p = 1;
  col = 1;
  while (p <= MAX_PLAYERS)
  {
    if (tot_live)
    {
      perdiv = (vm->player[p].life_signal * 100.0) / tot_live;
      p_lives = ((BREAK_DIS / 100.0) * perdiv);
      if (p_lives)
        ++p_lives;
      // p_lives = dv * vm->player[p].life_signal;
      // if (BREAK_DIS % tot_live && p_lives)
      //   ++p_lives;
    }
    else
      p_lives = 0;
    name_color(p);
    i = loop_breakdown(line, col, p_lives);
    vm->player[p].tot = i;
    col += i;
    // name_color_off(p);
    ++p;
  }
  return (col);
}

int display_breakdown(t_vm *vm, int line)
{
  int col;
  int dv;
  int tot_live;

	mvprintw(line, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for current period :");
	mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6, "[");
	// attroff(COLOR_PAIR(NC_C_WHITE));
	tot_live = get_nb_live(vm);
  dv = get_dv(vm, tot_live);
  col = current_breakdown(vm, line + 1, tot_live, dv);
  attron(COLOR_PAIR(NC_P_WHITE));
  while (col <= BREAK_DIS)
  {
  	mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6 + col, "-");
  	++col;
  }
	// attron(COLOR_PAIR(NC_C_WHITE));
  mvprintw(line + 1, 3 * (MEM_SIZE / 64) + 6 + col, "]");
  mvprintw(line + 3, 3 * (MEM_SIZE / 64) + 6, "Live breakdown for last period :");
  mvprintw(line + 4, 3 * (MEM_SIZE / 64) + 6, "[");
  // attroff(COLOR_PAIR(NC_C_WHITE));
  line = last_breakdown(vm, line + 4);
  return (line);
}
