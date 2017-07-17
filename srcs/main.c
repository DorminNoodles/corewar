/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/17 21:46:54 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_param(int argc, char **argv)
{


}

int		shrt_value(char *tab)
{
	int ret;

	ret = 0;

	ret = ret | *tab;
	ret = ret << 8;
	ret = ret | tab[1];
	return (ret);
}

int		is_opcode(char data)
{
	if (data == 11)
		return (1);
	if (data == 06)
		return (1);
	if (data == 02)
		return (1);

	return (0);
	// if (data < 17 && data > 0)
	// 	return (1);
	// else
	// 	return (0);
}

void	get_bytes_format(t_vm *vm, int player)
{
	//get bytes format
	vm->p_bag[player].pc++;
}

void	move_pc(t_vm *vm, int player)
{
	if (vm->p_bag[player].pc + 1 < MEM_SIZE - 1)
		vm->p_bag[player].pc++;
	else
		vm->p_bag[player].pc = 0;
}

void	stock_inst(t_bag *bag, char data)
{
	bag->cur_op = (t_inst*)ft_memalloc(sizeof(t_inst));
	ft_bzero(bag->cur_op, sizeof(bag->cur_op));
	printf("######### ###### data : %d\n", data);
	bag->cur_op->code = data;
	bag->cur_op->cooldown = 20;
}

void		run_op(t_vm *vm, t_inst *op, int player)
{
	vm->optab[op->code].func(vm, op, player);
}

int			need_ocp()
{

	return (1);
}

char		get_ocp(t_vm *vm, int player)
{
	int		pc;
	char	ocp;

	vm->p_bag[player].pc++;
	ocp = vm->mem[vm->p_bag[player].pc];
	return (ocp);
}

char		get_type_ocp(int pos, char ocp)
{
	if (pos == 1)
		return(ocp >> 6);
	if (pos == 2)
	{
		ocp = ocp >> 4;
		ocp = ocp & 0x3;
		return (ocp);
	}
	if (pos == 3)
	{
		ocp = ocp >> 2;
		ocp = ocp & 0x3;
		return (ocp);
	}
	return (0);
}

int			get_arg(t_vm *vm, int num, char type, int player)
{
	t_bag	*bag;
	t_inst	*op;
	int		ret;
	int		direct;

	ret = 0;
	bag = &vm->p_bag[player];
	direct = vm->optab[bag->cur_op->code].direct;

	printf("############### OP->direct : %d	\n", direct);

	printf("type of arg >> %d\n", type);

	if (type == T_REG)
	{
		bag->pc++;
		ret = (int)vm->mem[bag->pc];
		return (ret);
	}
	if (type == T_DIR && direct == 2)
	{
		bag->pc++;
		ret = (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;

		bag->pc++;
		ret = ret | (unsigned char)vm->mem[bag->pc];
		// if ()
		return(ret);
	}
	if (type == T_DIR && direct == 4)
	{
		bag->pc++;
		ret = (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;

		bag->pc++;
		ret = ret | (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;

		bag->pc++;
		ret = ret | (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;

		bag->pc++;
		ret = ret | (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;
		// if ()
		return(ret);
	}
	return (0);
}

int		get_arg_num(t_vm *vm, int opcode)
{
	return (vm->optab[opcode].nb_arg);
}

void		fill_cur_op(t_vm *vm, t_inst *op, int player)
{
	printf("FILL_CUR_OP\n");
	int pos;

	if (need_ocp())
	{
		op->ocp = get_ocp(vm, player);
		printf("ocp > %d\n", op->ocp);


		printf("GET ARG NUM %d\n", get_arg_num(vm, op->code));

		if (get_arg_num(vm, op->code) >= 1)
			op->ar1 = get_arg(vm, 1, get_type_ocp(1, op->ocp), player);
		printf("FUCKKKKKKKKKKKKKKKKKKK\n");

		printf("ar1 => %d\n", op->ar1);
		printf("ocp > %d\n", op->ocp);

		if (get_arg_num(vm, op->code) >= 2)
			op->ar2 = get_arg(vm, 2, get_type_ocp(2, op->ocp), player);

		printf("ar2 => %d\n", op->ar2);

		printf("player pc-> %d\n", vm->p_bag[player].pc);

		if (get_arg_num(vm, op->code) >= 3)
			op->ar3 = get_arg(vm, 3, get_type_ocp(3, op->ocp), player);

		printf("ar3 => %d\n", op->ar3);
	}
}

void	remove_op(t_bag *bag)
{
	bag->cur_op = NULL;
}

void	run(t_vm *vm)
{
	int		player;
	t_bag	*p_cur;
	int test = 80;

	while (test)// si il n y a plus qu un seul player en vie stop :)
	{
		player = 0;
		while (player < vm->p_nb)
		{
			p_cur = &vm->p_bag[player];
			if (p_cur->cur_op) //si une instruction est deja en buffer
			{
				if (p_cur->cur_op->cooldown > 0)
				{
					p_cur->cur_op->cooldown--;
				}
				else
				{
					printf("RUN OP\n");
					fill_cur_op(vm, p_cur->cur_op, player);
					run_op(vm, vm->p_bag[player].cur_op, player);
					remove_op(&vm->p_bag[player]);
				}
			}
			else //sinon il n y a pas d inst en buffer
			{//on va chercher si opcode
				if (is_opcode(vm->mem[p_cur->pc % MEM_SIZE]))
				{
					printf(" -> OPCODE   :  %d\n", vm->mem[p_cur->pc % MEM_SIZE]);
					stock_inst(p_cur, vm->mem[p_cur->pc % MEM_SIZE]);
				}
				else //sinon pas opcode move pc
				{
					p_cur->pc++;
				}
			}
			player++;
		}
		vm->cycle++;
		printf("cycle : %d\n", vm->cycle);
		usleep(10000);
		test--;
	}
}

void	and(t_vm *vm, t_inst *op, int player)
{
	printf(">>>>>ENTER AND<<<<<\n");
	int		ret;
	t_bag	*bag;

	bag = &vm->p_bag[player];
	ret = op->ar1 & op->ar2;
	bag->reg[op->ar3] = ret;
}



void	function_de_test(t_vm *vm, void *a1, void *a2, void *a3)
{
	printf("function de merde\n");
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	// vm.op_tab[0] =  &function_de_test;
	// vm.optab[11].func =  &sti;
	// vm.optab[6].func =  &and;
	// vm.optab[2].func =  &ld;

	check_param(argc, argv);//check des parametres
	init_vm(&vm);//initialisation de la machine virtuelle

// -------------------  TEST

	//vm.op_tab[0](NULL, NULL, NULL);
	// (op_table[0]) = &function_de_test;
	// (op_table[0])();
	// (*op_tab[0]) = function_de_test;
	// printf("\n   %d  \n\n\n", (op_tab));

// --------------------- TEST END

	run(&vm);//lancement du combat

	printf(">>>>>>%d\n", vm.p_bag[0].reg[1]);
	show_mem(&vm);

	return (0);
}


// Faire un instruction buffer et un instruction_is_complete pour voir si on run l instruction ou pas
// je dois quand meme savoir ce que je dois chercher ensuite (dans le prochain octet)
