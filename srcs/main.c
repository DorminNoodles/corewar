/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/09/08 22:38:59 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//
// int		shrt_value(char *tab)
// {
// 	int ret;
//
// 	ret = 0;
//
// 	ret = ret | *tab;
// 	ret = ret << 8;
// 	ret = ret | tab[1];
// 	return (ret);
// }

// int		is_opcode(char data)
// {
// 	if (data >= 1 && data <= 16)
// 		return (1);
// 	return (0);
// }

//
// void	get_bytes_format(t_vm *vm, int player)
// {
// 	//get bytes format
// 	vm->p_bag[player].pc++;
// }

// void	move_pc(t_vm *vm, int player)
// {
// 	if (vm->p_bag[player].pc + 1 < MEM_SIZE - 1)
// 		vm->p_bag[player].pc++;
// 	else
// 		vm->p_bag[player].pc = 0;
// }

// void	stock_inst(t_bag *bag, char data)
// {
// 	bag->cur_op = (t_op*)ft_memalloc(sizeof(t_op));
// 	ft_bzero(bag->cur_op, sizeof(bag->cur_op));
// 	// printf("######### ###### data : %d\n", data);
// 	bag->cur_op->code = data;
// 	bag->cur_op->loadtime = 20;
// }

// void		run_op(t_vm *vm, t_op *op, int player)
// {
// 	printf("#############################OPCODE >> %d\n", op->code);
// 	vm->optab[op->code].func(vm, op, player);
// }

// int			need_ocp()
// {
//
// 	return (1);
// }

// char		get_ocp(t_vm *vm, int player)
// {
// 	int		pc;
// 	char	ocp;
//
// 	vm->p_bag[player].pc++;
// 	ocp = vm->mem[vm->p_bag[player].pc];
// 	return (ocp);
// }

// unsigned char		get_type_ocp(int pos, char ocp)
// {
// 	if (pos == 1)
// 		return((unsigned char)ocp >> 6);
// 	if (pos == 2)
// 	{
// 		ocp = ocp >> 4;
// 		ocp = ocp & 0x3;
// 		return ((unsigned char)ocp);
// 	}
// 	if (pos == 3)
// 	{
// 		ocp = ocp >> 2;
// 		ocp = ocp & 0x3;
// 		return ((unsigned char)ocp);
// 	}
// 	return (0);
// }
//
// int			get_arg(t_vm *vm, int num, unsigned char type, int player)
// {
// 	t_bag	*bag;
// 	t_op	*op;
// 	int		ret;
// 	int		direct;
//
// 	ret = 0;
// 	bag = &vm->p_bag[player];
// 	direct = vm->optab[bag->cur_op->code].direct;
//
// 	// printf("############### OP->direct : %d	\n", direct);
//
// 	printf("type of arg >> %d\n", type);
//
// 	if (type == T_REG)
// 	{
// 		bag->pc++;
// 		ret = (int)vm->mem[bag->pc];
// 		return (ret);
// 	}
// 	if (type == T_DIR && direct == 2)
// 	{
// 		bag->pc++;
// 		ret = (unsigned char)vm->mem[bag->pc];
// 		ret = ret << 8;
//
// 		bag->pc++;
// 		ret = ret | (unsigned char)vm->mem[bag->pc];
// 		// if ()
// 		return(ret);
// 	}
// 	if (type == T_DIR && direct == 4)
// 	{
// 		printf("DIRECT == 4\n");
// 		bag->pc++;
// 		ret = (unsigned char)vm->mem[bag->pc];
// 		ret = ret << 8;
// 		bag->pc++;
// 		ret = ret | (unsigned char)vm->mem[bag->pc];
// 		ret = ret << 8;
// 		bag->pc++;
// 		ret = ret | (unsigned char)vm->mem[bag->pc];
// 		ret = ret << 8;
// 		bag->pc++;
// 		ret = ret | (unsigned char)vm->mem[bag->pc];
//
// 		return(ret);
// 	}
// 	return (0);
// }
//
// int			get_arg_num(t_vm *vm, int opcode)
// {
// 	return (vm->optab[opcode].nb_arg);
// }


// void		fill_cur_op(t_vm *vm, t_op *op, int player)
// {
// 	// printf("FILL_CUR_OP\n");
// 	int pos;
//
// 	if (need_ocp())
// 	{
// 		op->ocp = get_ocp(vm, player);
// 		printf("ocp > %d\n", op->ocp);
//
//
// 		printf("GET ARG NUM %d\n", get_arg_num(vm, op->code));
//
// 		printf("Get_type_ocp : %d \n", get_type_ocp(1, op->ocp));
//
// 		if (get_arg_num(vm, op->code) >= 1)
// 			op->ar1 = get_arg(vm, 1, get_type_ocp(1, op->ocp), player);
// 		// printf("FUCKKKKKKKKKKKKKKKKKKK\n");
//
// 		printf("ar1 => %d\n", op->ar1);
// 		printf("ocp > %d\n", op->ocp);
//
// 		if (get_arg_num(vm, op->code) >= 2)
// 			op->ar2 = get_arg(vm, 2, get_type_ocp(2, op->ocp), player);
//
// 		printf("ar2 => %d\n", op->ar2);
//
// 		// printf("player pc-> %d\n", vm->p_bag[player].pc);
//
// 		if (get_arg_num(vm, op->code) >= 3)
// 			op->ar3 = get_arg(vm, 3, get_type_ocp(3, op->ocp), player);
//
// 		vm->p_bag[player].pc++;
//
// 		// printf("ar3 => %d\n", op->ar3);
// 	}
// }

//
// void	remove_op(t_bag *bag)
// {
// 	bag->cur_op = NULL;
// }

//
// void	run(t_vm *vm)
// {
// 	int		player;
// 	t_bag	*p_cur;
// 	int test = 160;

// 	while (test)// si il n y a plus qu un seul player en vie stop :)
// 	{
// 		player = 0;
// 		while (player < vm->nb_player)
// 		{
// 			p_cur = &vm->p_bag[player];
// 			if (p_cur->cur_op) //si une instruction est deja en buffer
// 			{
// 				if (p_cur->cur_op->loadtime > 0)
// 				{
// 					p_cur->cur_op->loadtime--;
// 				}
// 				else
// 				{
// 					// printf("#######################RUN OP\n");
// 					// printf("#######################PC = %d\n", p_cur->pc);
// 					// printf("#######################OPCODE = %d\n", p_cur->cur_op->code);
// 					fill_cur_op(vm, p_cur->cur_op, player);
// 					run_op(vm, vm->p_bag[player].cur_op, player);
// 					remove_op(&vm->p_bag[player]);
// 				}
// 			}
// 			else //sinon il n y a pas d inst en buffer
// 			{//on va chercher si opcode
// 				if (is_opcode(vm->mem[p_cur->pc % MEM_SIZE]))
// 				{
// 					// printf(" -> OPCODE   :  %d\n", vm->mem[p_cur->pc % MEM_SIZE]);
// 					stock_inst(p_cur, vm->mem[p_cur->pc % MEM_SIZE]);
// 				}
// 				else //sinon pas opcode move pc
// 				{
// 					p_cur->pc++;
// 				}
// 			}
// 			player++;
// 		}
// 		vm->cycle++;
// 		printf("cycle : %d\n", vm->cycle);
// 		usleep(10000);
// 		test--;
// 	}
// }

void	get_ocp(t_vm *vm, t_proc *proc)
{
	// printf("MEM BEFORE   %x\n", (unsigned char)vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].need_ocp)
	{
		proc->pc++;
		proc->op->ocp = vm->mem[proc->pc];
	}
	// printf("MEM AFTER   %x\n", (unsigned char)vm->mem[proc->pc]);
}

void	get_dir(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_DIR<<<<<<<<<<<\n");
	unsigned int value;

	value = 0;


	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf(" hexa dans mem %x\n", vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].direct_size)
	{
		proc->op->ar[num] = value;
		// printf("deux octets value %x\n", value);
		return ;
	}
	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf("4 octets value %x\n", value);
	proc->op->ar[num] = value;
}

void	get_reg(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_REG<<<<<<<<<<<\n");
	unsigned char value;

	proc->pc++;
	value = (unsigned char)vm->mem[proc->pc];

	// printf("reg value %d\n", value);

	proc->op->ar[num] = value;
}

void	get_ind(t_vm *vm, t_proc *proc, int num)
{
	// printf(">>>>>>>>>>GET_IND<<<<<<<<<<<\n");

	unsigned int value;

	value = 0;

	// printf("FUCK >>>>> %d\n", vm->mem[proc->pc]);
	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf("deux octets value %x\n", value);

	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	proc->op->ar[num] = value;
}



void	find_args(t_vm *vm, t_proc *proc, int num)
{
	// printf("ENTER FUNC : FIND_ARGS\n");
	unsigned char	type;
	unsigned char	mask;

	type = proc->op->ocp;
	// printf("OCP => %d\n", type);
	mask = 0xC0;
	mask = mask >> (2 * num);
	type = type & mask;
	type = type >> (6 - 2 * num);
	proc->op->ar_typ[num] = type;

	if (type == REG_CODE)
		get_reg(vm, proc, num);
	if (type == DIR_CODE)
		get_dir(vm, proc, num);
	if (type == IND_CODE)
		get_ind(vm, proc, num);

	// if (mask )

	// printf("EXIT FUNC : FIND_ARGS\n");
}

// ref = get_optab_entry();

t_optab		*get_optab_entry(int code)
{
	return (&op_tab[code - 1]);
}

void	fill_cur_op(t_vm *vm, t_proc *proc)
{
	int i;
	t_optab *optab_ref;

	i = 0;
	// printf("OCP CODE >>>> %d\n", proc->op->code);
	optab_ref = get_optab_entry(proc->op->code);
	if (optab_ref->need_ocp)
	{
		// printf("                                               NEED OCP !\n");
		get_ocp(vm, proc);
		while (i < op_tab[proc->op->code - 1].nb_arg)
		{
			find_args(vm, proc, i);
			i++;
		}
	}
	else
	{
		get_dir(vm, proc, 0);
		// printf("                                            DONT NEED OCP !\n");
	}

	proc->pc++;
}

int		is_opcode(char data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if ((char)op_tab[i].code == data)
			return (data);
		i++;
	}
	return (0);
}

t_op		*create_op(t_vm *vm, t_proc *proc, char data)
{
	int		i;
	t_op	*op;

	i = 0;
	op = NULL;
	if (!is_opcode(data))
		return (NULL);
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		error("error : malloc\n");
	op->code = data;
	op->loadtime = op_tab[data - 1].loadtime;
	op->pos_opcode = proc->pc;
	return (op);
}

//  FUNCTIONS WERE ADDED TO KILL PROCESSES, AND SO ALLOW VICTORY AND LOSE CONDITIONS
//	TO HAVE AN EFFECT ON THE MEMORY.

/*int		kill_process(t_proc *proc, int i)
{
	t_proc *tmp;

	tmp = proc;
	if (i == proc->id)
	{
		tmp = tmp->next;
		ft_memdel(proc);			//  jsuis fatigue, probleme de maillons etc.
		proc = tmp;
	}
	else
		while (tmp->next)
		{
			if (tmp->next == proc && proc->next != NULL)
			{
				tmp->next = proc->next;
				ft_memdel(proc);
			}
			else if (tmp->next == proc)
				ft_memdel(tmp->next);
			tmp->next = (tmp->next != NULL) ? tmp->next : tmp;
		}
}

int		burial(t_proc *proc, int i)
{
	t_proc	*tmp;

	tmp = proc;
	if (proc == NULL)
		return (0);
	if (proc->id == i)
		kill_process(tmp, i);
	burial(proc->next, i);
}*/

//  FUNCTIONS WERE ADDED TO KILL PROCESSES, AND SO ALLOW VICTORY AND LOSE CONDITIONS
//	TO HAVE AN EFFECT ON THE MEMORY.

//WINNER EXIST TWEAKED BUT NOT TESTED.

void	champ_burial(t_proc *proc, int i)
{


}

//LE WINNER_EXIST DE MIKE avec son champ_burial....
// int		winner_exist(t_vm *vm)
// {
// 	t_proc	*lst;
// 	int		tmp;
// 	int		i;
// 	int		n;
//
// 	lst = vm->proc;
// 	tmp = 0;
// 	i = 0;
// 	n = 0;
// 	//  I SHOULD EDIT CYCLE TO DIE WOULD BE EASIER TO SEE RESULTS
// 	if (vm->countdown / CYCLE_TO_DIE >= 1 && vm->countdown % CYCLE_TO_DIE == 0)
// 	{
// 		printf("Cycle to die => %d\n", CYCLE_TO_DIE);
// 		printf("    debug : cycle to die hit !\n");
// 		while (vm->life_signal[i] && vm->life_signal[i] != -1)
// 		{
// 			if (vm->life_signal[i] != 1)
// 				champ_burial(vm->proc, i + 1);
// 			else
// 				n++;
// 			i++;
// 		}
// 		if (n == 0)
// 			// no winner  ? ?
// 		if (n == 1)
// 			return (1);
// 	}
// 	// printf("return 0 ??????\n");
// 	return (0);
// }

// J AI COMMENTE LA PARTIE DE LCHETY LCHETY LCHETY
//lchety: arrete de crier lchety

//lchety : bon je vais faire une nouvelle version de winner_exist :D

void	reset_life_signal(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		vm->player[i].life_signal = 0;
		i++;
	}
}

void	undertaker(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!vm->player[i].life_signal && vm->player[i].active)
		{
			// printf("Player %d died !\n", i);
			vm->player[i].active = 0;
		}
		i++;
	}
}

t_player	*get_last_one(t_vm *vm)
{
	int i;

	i  = 1;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
			return (&vm->player[i]);
		i++;
	}
	return (vm->last_one);
}

int		cycle_to_die(t_vm *vm)
{
	if (vm->countdown % vm->ctd == 0 && vm->countdown / vm->ctd > 0)
		return (1);
	return (0);
}

int		all_died(t_vm *vm)
{
	// int i;
	// int cnt;
	//
	// i = 0;
	// cnt = 0;
	// if (cycle_to_die(vm))
	// {
	// 	undertaker(vm);
	// 	vm->last_one = get_last_one(vm);
	// 	reset_life_signal(vm);
	// 	while (i <= MAX_PLAYERS && cnt == 0)
	// 	{
	// 		if (vm->player[i].active)
	// 			cnt++;
	// 		i++;
	// 	}
	// 	if (!cnt)
	// 		return (1);
	// }
	return (0);
}

void	idle_state(t_vm *vm, t_proc *proc)
{
	// printf("------------IDLE_STATE------------\n");
	if ((proc->op = create_op(vm, proc, vm->mem[proc->pc])))
		proc->state = WAIT;
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}

void	wait_state(t_vm *vm, t_proc *proc)
{
	// printf("------------WAIT_STATE------------\n");
	proc->op->loadtime--;
	if (proc->op->loadtime <= 0)
	{
		fill_cur_op(vm, proc);
		if (op_tab[proc->op->code - 1].func != NULL)
			op_tab[proc->op->code - 1].func(vm, proc);
		proc->state = IDLE;
	}
}

void	animate_proc(t_vm *vm, t_proc *proc)
{
	if (proc->state == IDLE)
		idle_state(vm, proc);
	else if (proc->state == WAIT)
		wait_state(vm, proc);
}

void	call_ncurses(t_vm *vm)
{
	int i;

	i = 0;


	init_pair(1, COLOR_RED, COLOR_BLACK);

	move(0,0);
	while (i < MEM_SIZE)
	{
		move(i / 64, (i % 64) * 3);
		if (i == 30)
		{
			attron(COLOR_PAIR(1));
			attron(A_STANDOUT);
		}
		printw("%02x", (unsigned char)vm->mem[i]);
		attroff(A_STANDOUT);
		attroff(COLOR_PAIR(1));
		i++;
	}
	move(10, 200);
	printw("Cycles : %d", vm->countdown);
	move(12, 200);
	printw("Keycode : %d", vm->keycode);
	// printw("hello world");
	refresh();

}

void	controller(t_vm *vm)
{
	// vm->keycode = getch();
	if (getch() == ' ')
		vm->pause = 1;
	while (vm->pause)
	{
		if (getch() == ' ')
		{
			vm->pause = 0;
			break;
		}
	}
}

void	run(t_vm *vm)
{
	t_proc	*proc;

	while (!all_died(vm))
	{
		proc = vm->proc;
		while (proc != NULL)
		{
			animate_proc(vm, proc);
			proc = proc->next;
		}
		vm->countdown++;

//-------------------------Debug
		// printf(">>>> %d\n", vm->countdown);
		// if (vm->countdown > 1200)
		// {
		// 	// show_mem(vm);
		// 	exit(1);
		// }
		// show_proc_nb(vm);
//-------------------------Debug
//-------------------NCURSES
		if (1)
			call_ncurses(vm);
//-------------------NCURSES
		controller(vm);
		usleep(100000);
	}
	printf("END\n");
	if (vm->last_one)
		printf("Last_one => %s\n", vm->last_one->file_name);


}



// #include <ncurses.h>
// #include <string.h>

// void main(void)
// {
// 	initscr();
//
// 	int c;
// 	printw("NCRUSES");
// 	while ((c=getch()) != 27)
// 	{
// 		move(10,0);
// 		printw("Keycode : %d, char : %c", c, c);
// 		move(0,0);
// 		printw("press (ESC) for quit");
// 		refresh();
// 	}
// 	// printf("Kefgdngjk %d, eghdthio %c", c, c);
// 	endwin();
// }

int		main(int argc, char **argv)
{
	t_vm	vm;
	WINDOW *w;

	w = initscr();
	start_color();			/* Start color 			*/
	cbreak(); //getch() no block
	nodelay(w, TRUE);


	// initscr();              // Initialise la structure WINDOW et autres paramètres
	// printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
	// refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
	// getch();                // On attend que l'utilisateur appui sur une touche pour quitter
	// endwin();
	//
	// exit(1);

	// char ch;
	// ch = getch();
	// printf("Input Char Is :%c",ch);



	init_vm(&vm);

	if(check_arg(&vm, argc, argv))//check des parametres
		error("Error\n");
//-------------Debug
	// printf("Debug : active -> %d\n", vm.player[1].active);
//-------------Debug
	create_players(&vm);//initialisation de la machine virtuelle

	run(&vm);//lancement du combat


	endwin();
	return (0);
}


// Faire un instruction buffer et un instruction_is_complete pour voir si on run l instruction ou pas
// je dois quand meme savoir ce que je dois chercher ensuite (dans le prochain octet)
