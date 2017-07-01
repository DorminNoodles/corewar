/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:04:04 by lchety            #+#    #+#             */
/*   Updated: 2017/05/18 18:23:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			n++;
		if (s[i] != c && n == 0)
			n++;
		i++;
	}
	return (n);
}

static char		**create_tab(int n)
{
	char **tab;

	tab = (char**)malloc(sizeof(char *) * (n + 1));
	if (tab == NULL)
		return (NULL);
	tab[n] = NULL;
	return (tab);
}

static char		*add_word(char const *s, size_t n)
{
	char *str;

	str = ft_strnew(n);
	ft_memcpy(str, s, n);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nb_w;

	nb_w = 0;
	tab = create_tab(count_words(s, c));
	if (!tab)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		if (i)
			tab[nb_w++] = add_word(s - i, i);
		if (*s)
			s++;
	}
	return (tab);
}
