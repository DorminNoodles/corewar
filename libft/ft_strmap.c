/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:39:57 by lchety            #+#    #+#             */
/*   Updated: 2016/11/30 13:00:20 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	while (*s)
	{
		dest[i] = (*f)(*s);
		i++;
		s++;
	}
	return (dest);
}
