/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 11:03:04 by lchety            #+#    #+#             */
/*   Updated: 2016/11/29 19:05:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	go;
	size_t			i;

	i = 0;
	go = 0;
	str = NULL;
	while (s[go] == ' ' || s[go] == '\n' || s[go] == '\t')
	{
		go++;
	}
	while (s[go + i])
		i++;
	while ((s[go + i] == ' ' || s[go + i] == '\n' ||
		s[go + i] == '\t' || s[go + i] == '\0') && i)
	{
		i--;
	}
	str = ft_strsub(s, go, i + 1);
	return (str);
}
