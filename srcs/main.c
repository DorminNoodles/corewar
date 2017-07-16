/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/16 22:53:12 by lchety           ###   ########.fr       */
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
	printf("WARBOY\n");
	if (data < 17 && data > 0)
		return (1);
	else
		return (0);

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

// void	fill_inst(t_vm *vm, int player, char *data)
// {
// 	int		pos;
//
//
// }

void	stock_inst(t_bag *bag, char data)
{
	bag->cur_inst = (t_inst*)ft_memalloc(sizeof(t_inst));
	ft_bzero(bag->cur_inst, sizeof(bag->cur_inst));
	bag->cur_inst->name = data;
	bag->cur_inst->cooldown = 50;
}

void		run_op(t_vm *vm, t_inst *op, int player)
{
	vm->op_tab[op->name](vm, op, player);
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
	int		ret;

	ret = 0;
	bag = &vm->p_bag[player];

	printf("type of arg >> %d\n", type);
	if (type == T_REG)
	{
		bag->pc++;
		ret = (int)vm->mem[bag->pc];
		return (ret);
	}
	if (type == T_DIR)
	{
		bag->pc++;
		ret = (unsigned char)vm->mem[bag->pc];
		ret = ret << 8;
		printf("ret :> %d\n", ret);
		bag->pc++;
		ret = ret | (unsigned char)vm->mem[bag->pc];
		return(ret);
	}
	return (0);
}

void		fill_cur_op(t_vm *vm, t_inst *op, int player)
{
	int pos;

	if (need_ocp())
	{
		op->ocp = get_ocp(vm, player);

		printf("ocp > %d\n", op->ocp);

		op->ar1 = get_arg(vm, 1, get_type_ocp(1, op->ocp), player);

		printf("ar1 => %d\n", op->ar1);
		printf("ocp > %d\n", op->ocp);

		op->ar2 = get_arg(vm, 2, get_type_ocp(2, op->ocp), player);

		printf("ar2 => %d\n", op->ar2);

		printf("player pc-> %d\n", vm->p_bag[player].pc);

		// printf("mem --> %x\n", vm->mem[vm->p_bag[player].pc + 1]);
		op->ar3 = get_arg(vm, 3, get_type_ocp(3, op->ocp), player);

		printf("ar3 => %d\n", op->ar3);
	}
}

void	remove_op(t_bag *bag)
{
	bag->cur_inst = NULL;
}

void	run(t_vm *vm)
{
	int		player;
	t_bag	*p_cur;
	int test = 150;

	while (test)// si il n y a plus qu un seul player en vie stop :)
	{
		player = 0;
		while (player < vm->p_nb)
		{
			p_cur = &vm->p_bag[player];
			if (p_cur->cur_inst) //si une instruction est deja en buffer
			{
				if (p_cur->cur_inst->cooldown > 0)
				{
					p_cur->cur_inst->cooldown--;
				}
				else
				{
					fill_cur_op(vm, p_cur->cur_inst, player);
					printf("op > %d\n", p_cur->cur_inst->name);
					run_op(vm, vm->p_bag[player].cur_inst, player);
					printf("Here\n");
					remove_op(&vm->p_bag[player]);
				}
			}
			else //sinon il n y a pas d inst en buffer
			{//on va chercher si opcode
				if (is_opcode(vm->mem[p_cur->pc % MEM_SIZE]))
				{
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
		usleep(12000);
		test--;
	}
}

void	sti(t_vm *vm, t_inst *op, int player)
{
	int addr;
	int reg;
	t_bag *bag;

	bag = &vm->p_bag[player];
	addr = op->ar2 + op->ar3;
	reg = op->ar1;

	printf("ADDR = %d = %d + %d\n", addr, op->ar2, op->ar3);
	printf("ADDR = %d\n", addr % MEM_SIZE);
	printf("Player = %d\n", player);
	printf("Reg = %x\n", bag->reg[reg]);
	// printf("REG = %d\n", bag->reg[reg]);
	// printf("REG = %d")
	vm->mem[addr % MEM_SIZE] = bag->reg[reg];
	vm->mem[(addr + 1) % MEM_SIZE] = bag->reg[reg] >>8;
	vm->mem[(addr + 2) % MEM_SIZE] = bag->reg[reg] >>16;
	vm->mem[(addr + 3) % MEM_SIZE] = bag->reg[reg] >>24;

}

void	and(t_vm *vm, t_inst *op, int player)
{
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
	vm.op_tab[11] =  &sti;
	vm.op_tab[06] =  &and;

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
	show_mem(&vm);

	return (0);
}


// Faire un instruction buffer et un instruction_is_complete pour voir si on run l instruction ou pas
// je dois quand meme savoir ce que je dois chercher ensuite (dans le prochain octet)
