/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:05:43 by lchety            #+#    #+#             */
/*   Updated: 2017/07/20 15:54:47 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VM = https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C

#ifndef COREWAR_H
#define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "libft.h"
#include "stdlib.h"
#include "stdio.h"

#define REG_NUMBER 16
#define REG_SIZE 1
#define MEM_SIZE 4096
// #define PC;

#define INST_IDLE 0
#define INST_NAME 1
#define INST_OCP 2
#define INST_ARG 2

#define	IDLE 1
#define	WAIT 2
#define	READY 3

// #define T_REG 1
// #define T_DIR 2
// #define T_IND 3

typedef struct s_vm t_vm;

typedef struct s_inst
{
	char	code;
	char	ocp;
	int		ar1;
	int		ar2;
	int		ar3;
	int		ar1_typ;
	int		ar2_typ;
	int		ar3_typ;
	int		cooldown;
}	t_inst;

typedef struct s_proc
{
	int		id;//Num du programme/player a fournir dans r1 (registre 1)
	int		pc;// L adresse dans la memoire de la machine virtuelle de la prochaine instruction du programme
	int		state;
	char	carry;// je sais plus
	int		*reg;//la on garde les registres en void* car ca taille est defini par une macro
	int		in_inst;
	int		cooldown;
	t_inst	*cur_op;
	struct	s_proc	*next;
}	t_proc;

typedef struct s_optab
{
	void	(*func)(t_vm *vm, t_inst *op, int player);
	int		nb_arg;
	int		direct;
	int		ocp;
}	t_optab;

typedef struct s_op
{
	char	*inst;
	void	(*func)(t_vm *vm, t_proc *proc);
	int		nb_arg;
	int		ocp;
	int		code;
	int		cooldown;
	char	*name;
	int		pouet;
	int		pouet2;//ocp
}	t_op;

typedef struct s_vm
{
	int		p_nb;
	int		cycle;
	char	*mem;
	//void	(*op_tab[20])(struct s_vm *vm, t_inst *op, int player);

	t_optab	optab[17];
	t_proc	*proc;
}	t_vm;

void	init_vm(t_vm *vm);
void	error(char *str);
void	and(t_vm *vm, t_inst *op, int player);
void	ld(t_vm *vm, t_inst *op, int player);
void	sti(t_vm *vm, t_inst *op, int player);
void	live(t_vm *vm, t_inst *op, int player);
void	add(t_vm *vm, t_inst *op, int player);

/*-------DEBUG-------*/
void	show_mem(t_vm *vm);

#endif
