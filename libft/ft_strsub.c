/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 00:31:13 by lchety            #+#    #+#             */
/*   Updated: 2017/03/24 14:41:12 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	s = s + start;
	start = 0;
	while (s[start] && len > 0)
	{
		*(str + start) = s[start];
		start++;
		len--;
	}
	return (str);
}
