/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:11 by lchety            #+#    #+#             */
/*   Updated: 2017/05/08 11:04:33 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

typedef struct s_fd_lst		t_fd_lst;
struct	s_fd_lst
{
	int			fd;
	char		*content;
	t_fd_lst	*next;
};
int		get_next_line(int fd, char **line);
#endif
