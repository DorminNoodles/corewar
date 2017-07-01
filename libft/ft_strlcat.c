/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 11:25:41 by lchety            #+#    #+#             */
/*   Updated: 2016/11/30 13:01:32 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	dlen;
	size_t	rest;

	d = dst;
	s = (char *)src;
	n = size;
	while (*d != '\0' && n--)
		d++;
	dlen = d - dst;
	rest = size - dlen;
	if (rest == 0)
		return (dlen + ft_strlen(src));
	while (*s != '\0' && rest > 1)
	{
		*d = *s;
		d++;
		rest--;
		s++;
	}
	*d = '\0';
	return (dlen + ft_strlen(src));
}
