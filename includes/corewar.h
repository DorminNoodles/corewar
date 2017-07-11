/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:05:43 by lchety            #+#    #+#             */
/*   Updated: 2017/07/11 13:59:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VM = https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C

#ifndef COREWAR_H
#define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "stdlib.h"
#include "stdio.h"

#define REG_NUMBER 2
#define REG_SIZE 1
#define MEM_SIZE 4096
// #define PC;


typedef struct s_bag
{
	int		id;//Num du programme/player a fournir dans r1 (registre 1)
	int		pc;// L adresse dans la memoire de la machine virtuelle de la prochaine instruction du programme
	char	carry;// je sais plus
	void	*r;//la on garde les registres en void* car ca taille est defini par une macro


}	t_bag;

typedef struct s_vm
{
	int		p_nb;
	void	*mem;
	void	(*op_tab[20])(void *a1, void *a2, void *a3);
	t_bag	*p_bag;

}	t_vm;


void	init_vm(t_vm *vm);
void	error(char *str);


/*-------DEBUG-------*/
void	show_mem(t_vm *vm);

#endif
