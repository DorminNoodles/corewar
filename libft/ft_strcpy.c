/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 23:09:12 by lchety            #+#    #+#             */
/*   Updated: 2016/11/13 16:35:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t size;
	size_t i;

	i = 0;
	size = ft_strlen(src) + 1;
	while (i < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
