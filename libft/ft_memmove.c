/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 18:00:55 by lchety            #+#    #+#             */
/*   Updated: 2016/11/28 11:48:39 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*src_temp;

	src_temp = (char *)ft_memalloc(n + 1);
	if (src_temp != NULL)
	{
		ft_memcpy(src_temp, src, n);
		ft_memcpy(dest, src_temp, n);
		free(src_temp);
	}
	return (dest);
}
