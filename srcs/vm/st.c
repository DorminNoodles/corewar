/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:37:51 by mlambert          #+#    #+#             */
/*   Updated: 2017/11/07 16:09:09 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	unsigned int	addr;

	if (!check_params(proc->op))
		return ;

	if (proc->op->ar_typ[1] == REG_CODE)
	{
		if (proc->op->ar[1] >= 1 && proc->op->ar[1] <= 16)
			proc->reg[proc->op->ar[1]] = proc->reg[proc->op->ar[0]];
	}
	else
	{
		if (!vm->ncurses && vm->debug)
			printf("ST in IND\n");

		addr = (proc->op->pos_opcode + (proc->op->ar[1] % IDX_MOD));

		addr = modulo(addr, MEM_SIZE);

		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 24;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		if (!vm->ncurses && vm->debug)
			printf("> : %x  ", vm->ram[addr].mem);

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 16;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		if (!vm->ncurses && vm->debug)
			printf("> : %x  ", vm->ram[addr].mem);

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]] >> 8;
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		if (!vm->ncurses && vm->debug)
			printf("> : %x  ", vm->ram[addr].mem);

		addr = modulo(addr + 1, MEM_SIZE);
		vm->ram[addr].mem = proc->reg[proc->op->ar[0]];
		vm->ram[addr].num = proc->num;
		vm->ram[addr].blingbling = 40;

		if (!vm->ncurses && vm->debug)
		{
			printf("> : %x  ", vm->ram[addr].mem);
			printf("\n");
		}
	}


	if (proc->num == -1)
	{
		// printf("SEGV_1\n");
		// printf(" FFFFFFFFFFFFFF %d\n", proc->carry);
		// move(20, 200);
		// printw("Cycles : %d", vm->cycle);
		// printw("CARRY       au bal du diable %d", proc->carry);
		// printf("SEGV_2\n");
	}

	if (0x4 & vm->verbosity)
	{
		show_operations(vm, proc);
		printf("\n");
	}

	// printf("r3 == %d\n", proc->reg[3]);
	// printf("carry == %d\n", proc->carry);

}


//(PC + (42 % IDX_MOD)
