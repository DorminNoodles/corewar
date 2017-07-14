/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/14 16:36:53 by lchety           ###   ########.fr       */
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



// void	instructoid(t_vm *vm, char *data, int player)
// {
// 	printf("player : %d   -> %#04x\n", player, (unsigned char)*data);
//
// 	if(vm->p_bag[player].pc + 1 < MEM_SIZE - 1)
// 		vm->p_bag[player].pc++;
// 	else
// 		vm->p_bag[player].pc = 0;
//
// 	//take the instruction opcode
//
// 	get_bytes_format(vm, player);
//
// }

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

void	run(t_vm *vm)
{
	int		player;
	t_bag	*p_cur;

	while (1)// si il n y a plus qu un seul player en vie stop :)
	{
		player = 0;
		while (player < vm->p_nb)
		{
			p_cur = vm->p_bag[player];

			if (p_cur->cur_inst) //si une instruction est deja en buffer
			{
				if (p_cur->cur_inst->cooldown > 0)
				{
					p_cur->cur_inst->cooldown--;

				}
				// if (is_opcode(vm->mem[vm->p_bag->pc]))
				// {
				// 	stock_inst(&vm->p_bag[player], vm->mem[vm->p_bag->pc]);
				// }
				// else
				// {
				//
				// }
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

				// move_pc(vm, player);
			player++;
		}
	}
}

void	function_de_test(void *a1, void *a2, void *a3)
{
	printf("function de merde\n");
}

int		main(int argc, char **argv)
{
	t_vm	vm;


	vm.op_tab[0] =  &function_de_test;

	check_param(argc, argv);//check des parametres
	init_vm(&vm);//initialisation de la machine virtuelle

// -------------------  TEST

	vm.op_tab[0](NULL, NULL, NULL);
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
