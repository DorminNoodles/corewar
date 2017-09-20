/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:33:15 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 14:34:19 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	controller(t_vm *vm)
{
	// vm->keycode = getch();
	if (getch() == ' ')
		vm->pause = 1;
	if (getch() == 'w')
		vm->delay *= 1.2;
		// vm->delay += 40000;
	if (getch() == 'e')
		vm->delay *= 0.8;
		// vm->delay -= 40000;
	while (vm->pause)
	{
		if (getch() == ' ')
		{
			vm->pause = 0;
			break;
		}
	}
}
