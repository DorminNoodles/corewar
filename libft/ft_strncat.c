/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:31:15 by lchety            #+#    #+#             */
/*   Updated: 2016/11/16 18:40:17 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;

	i = ft_strlen(dest);
	n += i;
	while (i < n && *(src))
	{
		*(dest + i) = *src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
