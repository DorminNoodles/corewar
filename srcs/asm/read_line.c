/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/03 00:01:34 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void parse_label(t_asm_env *env, char *line, char *label, int printmode)
{
  int a;

  a = 0;
  if (!printmode)
    create_label(&env->labs , env->bytes, line);
  if (env->verbose && printmode == PRINT_MODE)
    verbose_lab(label, env->bytes);
  while (line[a] && (ft_isalnum(line[a])))
    ++a;
  while (line[a] && (is_space(line[a]) || line[a] == LABEL_CHAR))
    ++a;
  free(label);
  label = take_word(line + a);
  if (*label)
    env->bytes += find_op(env, label, line + a, printmode);
}

void parse(t_asm_env *env, char *line, int printmode)
{
  int   a;
  int len;
  char  *word;

  if (line && line[0] != '#')
  {
    if (env->verbose && printmode == PRINT_MODE)
      ft_printf("Line %d: '%s'\n", env->line, line);
    a = 0;
    while (line[a] && is_space(line[a]))
      ++a;
    if (!line[a] || line[a] == COMMENT_CHAR)
      return ;
    word = take_word(line + a);
    len = len_is_label(word);
    if (word[len] == LABEL_CHAR && len + 1 != ft_strlen(word))
      word = red_label_name(word, len);
    if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
      write_header(env, line, printmode);
    else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
      parse_label(env, line + a, word, printmode);
    else
      env->bytes += find_op(env, word, line + a, printmode);
      free(word);
    if (env->verbose && printmode == PRINT_MODE)
      ft_printf(" - Current bytes = %d\n", env->bytes);
    }
}
