/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:10:50 by lchety            #+#    #+#             */
/*   Updated: 2017/07/11 20:50:40 by lchety           ###   ########.fr       */
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

void	run(t_vm *vm)
{
	int i;

	while (1)
	{
		if (vm->)

	}

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

void	function_de_test(void *a1, void *a2, void *a3)
{
	printf("function de merde\n");
}

int		main(int argc, char **argv)
{
	t_vm	vm;
	// int		*op_tab[20];


	vm.op_tab[0] =  &function_de_test;

	check_param(argc, argv);// check des parametres
	init_vm(&vm);//initialisation de la machine virtuelle

// -------------------  TEST

	vm.op_tab[0](NULL, NULL, NULL);
	// (op_table[0]) = &function_de_test;
	// (op_table[0])();
	// (*op_tab[0]) = function_de_test;
	//
	// printf("\n   %d  \n\n\n", (op_tab));



// --------------------- TEST END









	run(&vm);//lancement du combat
	show_mem(&vm);


}
