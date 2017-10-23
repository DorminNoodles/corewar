/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/23 21:54:52 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void dasm_error(int err, char *str)
{
	switch (err)
	{
		case SOURCE_ERR:
			ft_printf("Can't read source file %s\n", str);
			break;
		case MALLOC_ERR:
			ft_printf("Error: malloc failed\n");
			break;
		case OPEN_ERROR:
			ft_printf("Error: Open error\n");
			break;
		case SIZE_ERROR:
			ft_printf("Error: Size too big\n");
			break;
	}
	exit (EXIT_FAILURE);
}
