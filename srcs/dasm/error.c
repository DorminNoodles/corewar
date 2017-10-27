/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/27 03:47:01 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dasm_error(int err, char *str)
{
	if (err == SOURCE_ERR)
		ft_printf("Can't read source file %s\n", str);
	else if (err == MALLOC_ERR)
		ft_printf("Error: malloc failed\n");
	else if (err == OPEN_ERROR)
		ft_printf("Error: Open error\n");
	else if (err == SIZE_ERROR)
		ft_printf("Error: Size too big\n");
	exit(EXIT_FAILURE);
}
