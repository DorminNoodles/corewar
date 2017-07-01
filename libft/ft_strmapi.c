/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 23:27:33 by lchety            #+#    #+#             */
/*   Updated: 2016/11/29 19:09:51 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	while (*s)
	{
		dest[i] = (*f)(i, *s);
		i++;
		s++;
	}
	return (dest);
}
