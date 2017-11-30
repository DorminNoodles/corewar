/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:53:48 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/30 18:02:33 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_instr(int fd, int c)
{
	char	*ins;
	int		size;

	ins = op_tab[c - 1].inst;
	size = ft_strlen(ins);
	write(fd, "\t", 1);
	write(fd, ins, ft_strlen(ins));
	write(fd, "\t", 1);
}

void	parse_cor(t_dasm_env *env)
{
	int		i;
	int		inst;

	i = SRC_BEGIN;
	while (i < env->sizeFile)
	{
		inst = env->file[i];
		print_instr(env->fd, inst);
		++i;
		if (!op_tab[inst - 1].need_ocp)
		{
			if (inst == 1)
				i += print_dir4(env->fd, env->file + i);
			else
				i += print_dir2(env->fd, env->file + i);
		}
		else
			i += print_args(env->fd, inst, env->file + i);
		write(env->fd, "\n", 1);
	}
}

void	print_head(t_dasm_env *env)
{
	char	*name;
	char	*comments;
	int		binsize;

	binsize = ft_bin_len(env->file + MAGIC_NB);
	if (binsize > PROG_NAME_LENGTH)
		dasm_error(NAME_SIZE_ERR, NULL);
	name = ft_strnew(binsize + 1);
	name[binsize] = '\0';
	ft_memcpy(name, env->file + MAGIC_NB, binsize);
	write(env->fd, ".name \"", 7);
	write(env->fd, name, binsize);
	write(env->fd, "\"\n", 2);
	binsize = ft_bin_len(env->file + PROG_NAME + PROG_SIZE + MAGIC_NB);
	if (binsize > COMMENT_LENGTH)
		dasm_error(COM_SIZE_ERR, NULL);
	comments = ft_strnew(binsize + 1);
	name[binsize] = '\0';
	ft_memcpy(comments, env->file + (PROG_NAME + PROG_SIZE + MAGIC_NB),
	binsize);
	write(env->fd, ".comment \"", 10);
	write(env->fd, comments, binsize);
	write(env->fd, "\"\n\n", 3);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			arg;
	int 		len;
	char		*line;
	t_dasm_env	env;

	arg = 1;
	while (arg < argc)
	{
		if ((fd = open(argv[arg], O_RDONLY)) == -1)
			dasm_error(SOURCE_ERR, argv[arg]);
		line = NULL;
		len = ft_strlen(argv[arg]) - 1;
		if (len > 3 && argv[arg][len] == 'r' && argv[arg][len-1] == 'o' &&
		argv[arg][len-2] == 'c' && argv[arg][len-3] == '.')
		{
			create_file_cor(&env, argv[arg]);
			env.file = open_bin(&env, fd);
			print_head(&env);
			parse_cor(&env);
			argv[arg][ft_strlen(argv[arg]) - 4] = '\0';
			ft_printf("Writting output file to %s.s\n", argv[arg]);
		}
		else
			dasm_error(WRONG_FILE, argv[arg]);
		++arg;
	}
	return (0);
}
