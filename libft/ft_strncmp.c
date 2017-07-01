/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:07:52 by lchety            #+#    #+#             */
/*   Updated: 2016/11/30 15:20:13 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2 && n)
	{
		if (n > ft_strlen(s1) && n > ft_strlen(s2))
			n = (ft_strlen(s1) > ft_strlen(s2)) ? ft_strlen(s1) : ft_strlen(s2);
	}
	return (ft_memcmp(s1, s2, n));
}
