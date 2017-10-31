/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:05:43 by lchety            #+#    #+#             */
/*   Updated: 2017/10/31 15:01:42 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VM = https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C

#ifndef COREWAR_H
#define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "libft.h"
#include "ft_printf.h"
//-------------------------

#define IND_SIZE				2
#define REG_SIZE				1
#define DIR_SIZE				4


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
#define START 4

#define	MAGIC_NB 4
#define PROG_NAME 128 + 4
#define PROG_COMS 2048 + 4
#define	PROG_SIZE 4

#define D4 0
#define D2 1

#define SRC_BEGIN MAGIC_NB + PROG_NAME + PROG_COMS + PROG_SIZE

#define BLING_DELAY 65
#define BLING_LIVE 45
#define NCURSES_DELAY 100000

typedef struct s_vm t_vm;
typedef struct s_optab t_optab;

typedef struct s_op
{
	t_optab			*optab_ref;
	char			code;
	unsigned char	ocp;
	int				ar[3];
	int				ar_typ[3];
	int				loadtime;
	int				pos_opcode;
	int				countdown;
}	t_op;


typedef struct s_player
{
	int		active;
	// int		id;
	int		life_signal;
	int		last_live;
	char	*file_name;
}	t_player;

typedef struct s_proc
{
	int		id;
	int		active;
	int		num;//Num du programme/player a fournir dans r1 (registre 1)
	int		last_pc;
	int		pc;// L adresse dans la memoire de la machine virtuelle de la prochaine instruction du programme
	int		state;
	char	carry;// Mystere //edit : plus maintenant;
	// int		*reg;//la on garde les registres en void* car ca taille est defini par une macro
	int		reg[17];
	// int		loadtime;
	int		last_live; // si le processus a fait appel a live durant CYCLE_TO_DIE
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

typedef struct s_mem
{
	char	mem;
	int		num;
	int		blingbling;
	int		live;
}	t_mem;

typedef struct s_optab
{
	char	*inst;
	void	(*func)(t_vm *vm, t_proc *proc);
	int		nb_arg;
	int		ocp[3];
	int		code;
	int		loadtime;
	char	*name;
	int		need_ocp;
	int		direct_size; 	// nombre d'octect d'encodage. 2 ou 4;
	//changez ce nom de variable de merde :)
}	t_optab;

extern t_optab op_tab[];


typedef struct s_vm
{
	int		nb_player;
	int		ctd;
	int		cycle;
	int		keycode;
	int		pause;
	int		ncurses;
	int		delay;
	int		next_ctd;
	int		ctd_check;
	int		dump;
	int		debug;
	int		verbosity;
	int		lives_in_cycle;
	// char	*mem;
	char	mem[MEM_SIZE];
	t_mem	ram[MEM_SIZE];
	int		life_signal[4];			// tab pour les vies.
	char	*files_name[5];
	t_player	player[5];
	t_player	*last_one;

	//void	(*op_tab[20])(struct s_vm *vm, t_op *op, int player);

	t_optab	optab[17];
	t_proc	*proc;
}	t_vm;


void		init_vm(t_vm *vm);
void		create_players(t_vm *vm);
void		error(char *str);
// void	write_player(t_vm *vm);
void		write_player(t_vm *vm, int nb, int num);
int			check_arg(t_vm *vm, int argc, char **argv);
t_proc		*create_process(t_vm *vm, int num);
void		add_process(t_vm *vm, t_proc *proc);
void		wait_state(t_vm *vm, t_proc *proc);
void		idle_state(t_vm *vm, t_proc *proc);
t_op		*create_op(t_vm *vm, t_proc *proc, char data);
void		call_ncurses(t_vm *vm);
void		undertaker(t_vm *vm);
void		kill_proc(t_vm *vm);
void		fill_cur_op(t_vm *vm, t_proc *proc);
void		controller(t_vm *vm);
int			is_pc(t_vm *vm, int nb);
int			count_proc(t_vm *vm);
int			all_died(t_vm *vm);
int			is_opcode(char data);
int			cycle_to_die(t_vm *vm);
t_player	*get_survivor(t_vm *vm);
void		get_ocp(t_vm *vm, t_proc *proc);
void		find_args(t_vm *vm, t_proc *proc, int num);
void		get_dir(t_vm *vm, t_proc *proc, int num);
int			modulo(int a, int b);
void		show_operations(t_vm *vm, t_proc *proc);
void		show_pc_move(t_vm *vm, t_proc *proc);
void		reduce_ctd(t_vm *vm);
int			process_living(t_vm *vm);
void		set_ctd(t_vm *vm);
// int			*init_registre(int id);

/*
 ** --------INSTRUCTIONS----------
 */
void		and(t_vm *vm, t_proc *proc);
void		ld(t_vm *vm, t_proc *proc);
void		ldi(t_vm *vm, t_proc *proc);
void		sti(t_vm *vm, t_proc *proc);
void		live(t_vm *vm, t_proc *proc);
void		add(t_vm *vm, t_proc *proc);
void		or(t_vm *vm, t_proc *proc);
void		xor(t_vm *vm, t_proc *proc);
void		st(t_vm *vm, t_proc *proc);
void		sub(t_vm *vm, t_proc *proc);
void		ft_fork(t_vm *vm, t_proc *proc);
void		zjmp(t_vm *vm, t_proc *proc);
void		lld(t_vm *vm, t_proc *proc);

/*--------NCURSES---------*/
void		init_ncurses(WINDOW **w);


/*-------DEBUG-------*/
void		show_mem(t_vm *vm);
void		show_mem_2(t_vm *vm);
void		show_proc_nb(t_vm *vm);
void		debug_display_proc(t_vm *vm);

/*
 ** ------- ASM -----------
 */
// asm_error(int ERROR, char *str, int line, int column)
#define SOURCE_ERR 1
#define MALLOC_ERR 2
#define SIZE_ERROR 3
#define OPEN_ERROR 4
#define FILE_ERROR 5
#define INST_ERROR 6
#define LEX_ERROR 7


typedef struct s_asm_env
{
	struct s_tab_labs *labs;
	int              bytes;
	int							 size;
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

void write_header(t_asm_env *env, char *line, int printmode);

int detect_arg(char *line);
char *concat_opcode(char *ocp, int arg);
int goto_nextarg(char *line);
void write_ocp(t_asm_env *env, char *ocp);
char *take_word(char *str);

/*
 ** -------- Analyse -------------
*/
int analyse(int oct, char *line, int i);
int analyse_args(int oct, char *line, int i);
void op_no_ocp(t_asm_env *env, int i, char *line);
void op_ocp(t_asm_env *env, int i, char *line);

/*
 ** ---------- Display ------------
*/
void write_reg(t_asm_env *env, char *line);
void write_dir(t_asm_env *env, char *line, int i);
void write_dir_short();
void write_ind(t_asm_env *env, char *line);
void write_args(t_asm_env *env, char *line, int i);

/*
 ** -------- Reverse types ----------
*/
int reverse_int(int nb);
short reverse_short(short nb);

/*
 ** -------- Header -------------
*/
void write_comment(t_asm_env *env, char *line);
void write_name(t_asm_env *env, char *line);
void write_headr(t_asm_env *env, char *line, int printmode);

/*
 ** --------- Labels ------------
*/
t_tab_labs *new_label(char *line, int bytes);
void create_label(t_tab_labs **labels, int bytes, char *line);
int dist_label(t_asm_env *env, char *label);

void	init_vm(t_vm *vm);
int reverse_int(int nb);

/*
 ** ------- Error -------
*/
void asm_error(int err, char *str, int line, int column);
void line_error(char *line, int nb);

/* ------------------- DECOMPILER ------------------
 **
*/

typedef struct s_dasm_env
{
	int								fd;
	int								sizeFile;
	unsigned char 		*file;
}										t_dasm_env;


/*
 ** ------ Display instructions ---------
*/
int print_dir4(int fd, unsigned char *str);
int print_dir2(int fd, unsigned char *str);
int print_reg(int fd, int reg);
int print_ind(int fd, unsigned char *str);
int print_args(int fd, int inst, unsigned char *str);

/*
 ** ------ Error -------
*/
void dasm_error(int err, char *str);
int len_is_label(char *str);

/*
 ** ----- Create file -----
*/
int ft_bin_len(unsigned char *str);
unsigned char *open_bin(t_dasm_env *env, int fd);
void create_file_cor(t_dasm_env *env, char *str);

/*
 ** ----- Get types ---
*/
int get_uint32(unsigned char *buff);
short get_uint16(unsigned char *buff);

#endif
