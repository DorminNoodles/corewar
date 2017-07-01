/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:32:33 by lchety            #+#    #+#             */
/*   Updated: 2016/11/28 12:03:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		x;
	int		value;

	i = 0;
	sign = 1;
	x = 1;
	value = 0;
	while ((nptr[i] == ' ' || nptr[i] == '\v' || nptr[i] == '\t' ||
	nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'))
	{
		nptr++;
	}
	if (nptr[i] == '-' && nptr++)
		sign = -1;
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * x) + (nptr[i] - '0');
		x = 10;
		i++;
	}
	return (value * sign);
}
