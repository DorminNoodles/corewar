/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:33:15 by lchety            #+#    #+#             */
/*   Updated: 2017/09/24 22:08:19 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	controller(t_vm *vm)
{
	vm->keycode = getch();
	if (vm->keycode == ' ')
	{
		vm->pause = 1;
	}
	if (vm->keycode == 'w')
	{
		if (vm->delay + 24000 < 1000000)
			vm->delay += 24000;
		// vm->delay += 40000;
		// vm->delay *= 2;
	}
	else if (vm->keycode == 'e')
	{
		if (vm->delay - 8000 > 0)
			vm->delay -= 8000;
		else
			vm->delay = 0;
		// vm->delay -= 40000;
		// vm->delay *= 0.8;
	}

	while (vm->pause)
	{
		vm->keycode = getch();
		if (vm->keycode == ' ')
		{
			vm->pause = 0;
			break;
		}
	}
}
