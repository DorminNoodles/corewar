/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:33:15 by lchety            #+#    #+#             */
/*   Updated: 2017/11/03 17:18:25 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
static void	keys_press(t_vm *vm, char key)
{
	if (key == ' ' && vm->pause != 1)
	{
		vm->pause = 1;
	}
	if (key == 'w')
	{
		if (vm->delay + 24000 < 1000000)
			vm->delay += 24000;
		// vm->delay += 40000;
		// vm->delay *= 2;
	}
	else if (key == 'e')
	{
		if (vm->delay - 12000 > 0)
			vm->delay -= 12000;
		else
			vm->delay = 0;
	}
}
*/
void	controller(t_vm *vm)
{
	char	key;

	key = -1;
	key = getch();
	if (key == ' ' && vm->pause != 1)
	{
		vm->pause = 1;
	}
	if (key == 'w')
	{
		if (vm->delay + 24000 < 1000000)
			vm->delay += 24000;
		// vm->delay += 40000;
		// vm->delay *= 2;
	}
	else if (key == 'e')
	{
		if (vm->delay - 12000 > 0)
			vm->delay -= 12000;
		else
			vm->delay = 0;
	}
//	if (key != -1)
//		keys_press(vm, key);
	while (vm->pause)
	{
		call_ncurses(vm);
		key = getch();
		if (key == ' ')
		{
			vm->pause = 0;
			break;
		}
	}
}
