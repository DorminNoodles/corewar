/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/02 01:24:40 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void parse(t_asm_env *env, char *line, int printmode)
{
  int   a;
  int len;
  char  *word;

  if (line && line[0] != '#')
  {
    a = 0;
    while (line[a] && (line[a] == ' ' || line[a] == '\t'))
      ++a;
    if (!line[a] || line[a] == '#')
      return ;
    word = take_word(line + a);
    len = len_is_label(word);
    if (word[len] == LABEL_CHAR && len + 1 != ft_strlen(word))
    {
      word = red_label_name(word, len);
    }
    if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
      write_header(env, line, printmode);
    else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
    {
//    bullshit pour tester si le compteur d'octets fonctionne
//    on recuperera les label et leur postition soon
        if (!printmode)
          create_label(&env->labs , env->bytes, line + a);
        //  env->labs = create_label(&env->labs , env->bytes, line + a);

        while(line[a] && (ft_isalpha(line[a]) || ft_isdigit(line[a])))
          ++a;
        while (line[a] && (line[a] == ' ' || line[a] == '\t' || line[a] == ':'))
          ++a;
        free(word);
        word = take_word(line + a);
        if (*word)
          env->bytes += find_op(env, word, line + a, printmode);
      }
    else
      env->bytes += find_op(env, word, line + a, printmode);
      free(word);
    }
//    printf("bytes = %d\n", env->bytes);
}
