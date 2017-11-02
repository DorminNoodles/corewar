/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 01:24:52 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int find_op(t_asm_env *env, char *word, char *line, int printmode)
{
  int i;
  int tmp;
  int oct;

  oct = 1;
  i = 0;
  tmp = 0;
  while (op_tab[i].inst)
  {
    if (!ft_strcmp(word, op_tab[i].inst))
    {
      if (!op_tab[i].need_ocp)
      {
        tmp = i;
        if (printmode)
          op_no_ocp(env, i, line);
      }
      else
      {
        tmp = i;
        ++oct;
        if (printmode)
          op_ocp(env, i, line);
      }
      oct = analyse(oct, line, tmp);
    }
    ++i;
  }
  return (oct);
}
