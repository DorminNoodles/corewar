/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:05:43 by lchety            #+#    #+#             */
/*   Updated: 2017/07/31 11:21:13 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VM = https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C

#ifndef COREWAR_H
#define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "libft/includes/libft.h"
#include "stdlib.h"
#include "stdio.h"

//-------------------------

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

// typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;


//-------------------------

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

typedef struct s_op
{
	char	code;
	unsigned char	ocp;
	int		ar[3];
	int		ar_typ[3];
	int		loadtime;
	int		pos_opcode;
}	t_op;

typedef struct s_proc
{
	int		id;//Num du programme/player a fournir dans r1 (registre 1)
	int		pc;// L adresse dans la memoire de la machine virtuelle de la prochaine instruction du programme
	int		state;
	char	carry;// Mystere //edit : plus maintenant;
	int		*reg;//la on garde les registres en void* car ca taille est defini par une macro
	int		loadtime;
	int		live; // si le processus a fait appel a live durant CYCLE_TO_DIE
	t_op	*op;
	struct	s_proc	*next;
}	t_proc;

// typedef struct s_optab
// {
// 	void	(*func)(t_vm *vm, t_op *op, int player);
// 	int		nb_arg;
// 	int		direct;
// 	int		ocp;
// }	t_optab;

typedef struct s_optab
{
	char	*inst;
	void	(*func)(t_vm *vm, t_proc *proc);
	int		nb_arg;
	int		ocp;
	int		code;
	int		loadtime;
	char	*name;
	int		need_ocp;
	int		une_heure_de_perdue; 	// nombre d'octect d'encodage. 2 ou 4;
/* GROUPE DE FDP - comme les flics ces batards (on va niquer leurs meres)
  MLAMBERT AU BUCHET
*/
}	t_optab;

typedef struct s_vm
{
	int		p_nb;
	int		cycle;
	int		countdown;
	char	*mem;
	int		life_signal[4];			// tab pour les vies.
	//void	(*op_tab[20])(struct s_vm *vm, t_op *op, int player);
	t_optab	optab[17];
	t_proc	*proc;
}	t_vm;

typedef struct s_asm_env
{
  struct s_tab_labs *labs;
  int              bytes;
  int              fd;
}                  t_asm_env;

typedef struct s_tab_labs
{
  char              *label;
  int               nb_oct;
  struct s_tab_labs  *next;
}                   t_tab_labs;

void print_labs_lst(t_tab_labs *lst);
void create_label(t_tab_labs **labels, int bytes, char *line);
extern t_optab op_tab[17];

void	init_vm(t_vm *vm);
void	error(char *str);
void	and(t_vm *vm, t_proc *proc);
void	ld(t_vm *vm, t_proc *proc);
void	sti(t_vm *vm, t_proc *proc);
void	live(t_vm *vm, t_op *op, int player);
void	add(t_vm *vm, t_proc *proc);
void	or(t_vm *vm, t_proc *proc);
void	xor(t_vm *vm, t_proc *proc);
void	sub(t_vm *vm, t_proc *proc);
void	write_player(t_vm *vm);
void	st(t_vm *vm, t_proc *proc);

/*-------DEBUG-------*/
void	show_mem(t_vm *vm);

#endif
