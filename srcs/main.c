/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/22 19:49:59 by lchety           ###   ########.fr       */
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
	if (op_tab[proc->op->code - 1].ocp)
	{
		proc->pc++;
		proc->op->ocp = vm->mem[proc->pc];
	}
}

void	*get_dir()
{
	int *ptr;

	ptr = ft_memalloc(sizeof(int*));

	*ptr = 5;


	return ((void*)ptr);
}



void	find_args(t_vm *vm, t_proc *proc)
{
	char	ocp;
	void	*pouet;

	ocp = proc->op->ocp;

	if (!ocp) //alors c est un T_DIR
	{
		proc->op->ar1_typ = T_DIR;
		pouet = get_dir();
		// proc->op->ar1 = *(DIR_SIZE)get_dir();
	}
	else
	{
		while (ocp)
		{

			ocp = ocp << 2;
			proc->pc++;
		}

	}
}

void	fill_cur_op(t_vm *vm, t_proc *proc)
{
	if (op_tab[proc->op->code].ocp)
		get_ocp(vm, proc);
	printf("OP->OCP == %d\n", proc->op->ocp);
	find_args(vm, proc);
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
	printf("TEST %d\n", data);
	if (!is_opcode(data))
		return (NULL);
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		error("error : malloc\n");
	op->code = data;
	printf("FILL OP CODE %d\n", op->code);
	op->loadtime = op_tab[data - 1].loadtime;
	return (op);
}

void	run(t_vm *vm)
{
	int		i;
	int		player;
	t_proc	*proc;

	i = 0;
	proc = vm->proc;
	proc->op = NULL;

	while (i < 200) // main while stop if winner_exist
	{
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->state == IDLE)
			{
				printf("IDLE\n");
				if ((proc->op = create_op(vm, proc, vm->mem[proc->pc])))
					proc->state = WAIT;
				else
					proc->pc = (proc->pc + 1) % MEM_SIZE;
			}
			else if (proc->state == WAIT)
			{
				// op_tab[1].func(vm, proc);
				printf("WAIT  %d\n", proc->op->loadtime);
				proc->op->loadtime--;
				if (proc->op->loadtime <= 0)
				{
					fill_cur_op(vm, proc);
					printf("SEGFAULT\n");
					// printf("SEGFAULT %d\n", proc->op->code - 1);
					op_tab[proc->op->code - 1].func(vm, proc);
					// op_tab[1].func(vm, proc);
					proc->state = IDLE;
				}
			}
			proc = proc->next;
		}
		// printf("Cycle \n");
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
