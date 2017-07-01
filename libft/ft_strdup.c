/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:48:53 by lchety            #+#    #+#             */
/*   Updated: 2016/11/13 16:38:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *ptr;

	ptr = ft_strnew(ft_strlen(s));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy((void *)ptr, (void *)s, ft_strlen(s));
	return (ptr);
}
