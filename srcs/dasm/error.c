/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/04 22:03:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dasm_error(int err, char *str)
{
	COLOR(C_RED);
	ft_printf("Error: ");
	COLOR(C_RESET);
	if (err == SOURCE_ERR)
		ft_printf("Can't read source file %s\n", str);
	else if (err == MALLOC_ERR)
		ft_printf("Malloc failed\n");
	else if (err == OPEN_ERROR)
		ft_printf("Open error\n");
	else if (err == SIZE_ERROR)
		ft_printf("Size too big\n");
	else if (err == NAME_SIZE_ERR)
		ft_printf("Name size too big\n");
	else if (err == COM_SIZE_ERR)
		ft_printf("Comments size too big\n");
	else if (err == WRONG_FILE)
		ft_printf("\"%s\" : Wrong file\n", str);
	if (!WRONG_FILE)
		exit(EXIT_FAILURE);
}
