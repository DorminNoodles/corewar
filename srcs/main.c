/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/10 19:43:11 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_param(int argc, char **argv)
{


}

void	run(t_vm *vm)
{
	int i;

	// while (1)
	// {
	// 	i = 0;
	// 	while (i < vm->p_nb)
	// 	{
	//
	// 		i++;
	// 	}
	//
	// }
}

void	function_de_test()
{
	printf("function de merde\n");
}

int		main(int argc, char **argv)
{
	t_vm	vm;
	// int		*op_tab[20];
	void	(*op_table[20])();

	check_param(argc, argv);// check des parametres
	init_vm(&vm);//initialisation de la machine virtuelle

// -------------------  TEST

	(op_table[0]) = &function_de_test;
	(op_table[0])();
	// (*op_tab[0]) = function_de_test;
	//
	// printf("\n   %d  \n\n\n", (op_tab));



// --------------------- TEST END









	run(&vm);//lancement du combat
	show_mem(&vm);


}
