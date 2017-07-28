/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/28 05:51:45 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_param(int argc, char **argv)
{


}

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
// 		while (player < vm->p_nb)
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
	printf("MEM BEFORE   %x\n", (unsigned char)vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].need_ocp)
	{
		proc->pc++;
		proc->op->ocp = vm->mem[proc->pc];
	}
	printf("MEM AFTER   %x\n", (unsigned char)vm->mem[proc->pc]);
}

void	get_dir(t_vm *vm, t_proc *proc, int num)
{
	unsigned int value;

	value = 0;


	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	printf(" hexa dans mem %x\n", vm->mem[proc->pc]);
	if (op_tab[proc->op->code - 1].une_heure_de_perdue)
	{
		proc->op->ar[num] = value;
		printf("deux octets value %x\n", value);
		return ;
	}
	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	printf("4 octets value %x\n", value);
	proc->op->ar[num] = value;
}

void	get_reg(t_vm *vm, t_proc *proc, int num)
{
	unsigned char value;

	proc->pc++;
	value = (unsigned char)vm->mem[proc->pc];

	printf("reg value %d\n", value);

	proc->op->ar[num] = value;
}

void	get_ind(t_vm *vm, t_proc *proc, int num)
{
	printf(">>>>>>>>>>GET_IND<<<<<<<<<<<\n");

	unsigned int value;

	value = 0;

	printf("FUCK >>>>> %d\n", vm->mem[proc->pc]);
	proc->pc++;
	value = value | (unsigned char)vm->mem[proc->pc];

	proc->pc++;
	value = value << 8;
	value = value | (unsigned char)vm->mem[proc->pc];

	// printf("deux octets value %x\n", value);

	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	//
	// proc->pc++;
	// value = value << 8;
	// value = value | (unsigned char)vm->mem[proc->pc];
	proc->op->ar[num] = value;
}



void	find_args(t_vm *vm, t_proc *proc, int num)
{
	printf("ENTER FUNC : FIND_ARGS\n");
	unsigned char	type;
	unsigned char	mask;

	type = proc->op->ocp;
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



}

void	fill_cur_op(t_vm *vm, t_proc *proc)
{
	int i;

	i = 0;
	get_ocp(vm, proc);

	printf("OCP ===== %x\n", proc->op->ocp);
	printf("nb arg %d\n", op_tab[proc->op->code - 1].nb_arg);
	while (i < op_tab[proc->op->code - 1].nb_arg)
	{
		find_args(vm, proc, i);
		printf("Nature Arg %d\n", proc->op->ar[i]);
		i++;
	}
	printf("0 %x\n", proc->op->ar[0]);
	printf("1 %x\n", proc->op->ar[1]);
	printf("2 %x\n", proc->op->ar[2]);

	printf("%s\n", "OURS ");
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
	// printf("TEST %d\n", (char)data);
	if (!is_opcode(data))
		return (NULL);
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		error("error : malloc\n");
	op->code = data;
	// printf("FILL OP CODE %d\n", op->code);
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


int		winner_exist(t_vm *vm)
{
	t_proc	*lst;
	int		tmp;
	int		i;

	lst = vm->proc;
	tmp = 0;
	i = 0;
	//  I SHOULD EDIT CYCLE TO DIE WOULD BE EASIER TO SEE RESULTS

	if (vm->countdown == CYCLE_TO_DIE)
	{
		while (vm->life_signal[i] && vm->life_signal[i] != -1)
		{
			if (vm->life_signal[i] != 1)
				champ_burial(vm->proc, i + 1);
			else
				n++;
			i++;
		}
		if (n == 0)
			// no winner  ? ?
		if (n == 1)
			return 0
	}
/*	while (lst)
	{
		if (lst->live)
			tmp = lst->id * -1;
		printf("PLAYER ID => %d\n", tmp);
		while (lst && tmp)
		{
			if (lst->live && (lst->id * -1) != tmp)
				return (0);
			lst = lst->next;
		}
		if (lst != NULL)
			lst = lst->next;
	}*/
	return (1);
}

// J AI COMMENTE LA PARTIE DE LCHETY LCHETY LCHETY


void	run(t_vm *vm)
{
	int		i;
	int		player;
	t_proc	*proc;

	i = 0;
	proc = vm->proc;
	proc->op = NULL;

	while (i < 400 && !winner_exist(vm)) // main while stop if winner_exist
	{
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->state == IDLE)
			{
				//printf("IDLE\n");
				if ((proc->op = create_op(vm, proc, vm->mem[proc->pc])))
					proc->state = WAIT;
				else
					proc->pc = (proc->pc + 1) % MEM_SIZE;
			}
			else if (proc->state == WAIT)
			{
				// op_tab[1].func(vm, proc);
				//printf("WAIT  %d\n", proc->op->loadtime);
				proc->op->loadtime--;
				if (proc->op->loadtime <= 0)
				{
					fill_cur_op(vm, proc);
					printf("SEGFAULT %d\n", proc->op->code - 1);

					if (op_tab[proc->op->code - 1].func != NULL)
					{
						printf("ENTER IF FUNC \n");
						op_tab[proc->op->code - 1].func(vm, proc);
					}
					printf("%s\n", " MAIS, NON ");
					// op_tab[1].func(vm, proc);
					proc->state = IDLE;
				}
			}
			proc = proc->next;
		}
		vm->countdown++;			// added to reach cycle to die   <<<<<<< ??? ??  ?  ?? ? ? ?? >>>>>
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	check_param(argc, argv);//check des parametres
	init_vm(&vm);//initialisation de la machine virtuelle
	run(&vm);//lancement du combat
	show_mem(&vm);

	return (0);
}


// Faire un instruction buffer et un instruction_is_complete pour voir si on run l instruction ou pas
// je dois quand meme savoir ce que je dois chercher ensuite (dans le prochain octet)
