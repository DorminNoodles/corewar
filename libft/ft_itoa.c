/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 19:58:41 by lchety            #+#    #+#             */
/*   Updated: 2016/11/30 13:37:52 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digit_quantity(unsigned int n)
{
	int ret;

	ret = 1;
	while (n >= 10)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

static char		*create_str(char *str, int neg, unsigned int nb)
{
	int digits;

	digits = 0;
	digits = ft_digit_quantity(nb);
	str = ft_strnew(digits + neg);
	return (str);
}

static char		*recursive_itoa(char *str, unsigned int nb)
{
	if (nb >= 10)
	{
		str = recursive_itoa(str, nb / 10);
		str = recursive_itoa(str + 1, nb % 10);
		return (str);
	}
	else
	{
		*str = '0' + nb;
		return (str);
	}
}

char			*ft_itoa(int n)
{
	char			*str;
	int unsigned	nb;
	int				negatif;

	str = NULL;
	nb = n;
	negatif = 0;
	if (n < 0)
	{
		negatif = 1;
		nb = (unsigned int)n * -1;
	}
	str = create_str(str, negatif, nb);
	if (str == NULL)
		return (NULL);
	if (negatif)
		*str = '-';
	recursive_itoa(str + negatif, nb);
	return (str);
}
