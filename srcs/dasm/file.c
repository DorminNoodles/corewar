/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/27 03:48:25 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				ft_bin_len(unsigned char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

unsigned char	*open_bin(t_dasm_env *env, int fd)
{
	unsigned char *ret;

	if (!(ret = malloc(MEM_SIZE + 1)))
		dasm_error(MALLOC_ERR, NULL);
	env->sizeFile = read(fd, ret, MEM_SIZE);
	if (env->sizeFile > MEM_SIZE)
		dasm_error(SIZE_ERROR, NULL);
	return (ret);
}

void			create_file_cor(t_dasm_env *env, char *str)
{
	int		fd;
	int		len;
	char	*tmp;
	char	*name;

	len = ft_strlen(str) - 4;
	tmp = ft_strndup(str, len);
	name = ft_strnew(len + 2);
	name = ft_strcpy(name, tmp);
	name = ft_strcat(name, ".s");
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
		dasm_error(OPEN_ERROR, str);
	env->fd = fd;
}
