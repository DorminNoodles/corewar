/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 03:12:39 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/24 15:08:54 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char *take_word(char *str)
{
  int a;
  int len;
  char  *word;

  a = 0;
  len = 0;
  while (str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != SEPARATOR_CHAR)
    ++len;
  if (!(word = (char*)malloc(sizeof(char) * len + 1)))
    exit (0);
  word[len] = '\0';
  while (a != len)
  {
    word[a] = str[a];
    ++a;
  }
  word[a] = '\0';
  return (word);
}

int   detect_arg(char *line)
{
  int a;

  a = 0;
  if (line[a] == 'r')
    return (REG_CODE);
  if (line[a] == LABEL_CHAR || ft_isdigit(line[a]))
    return (IND_CODE);
  if (line [a] == DIRECT_CHAR)
    return (DIR_CODE);
  return (0);
}

char *concat_opcode(char *ocp, int arg)
{
  if (!ocp)
  {
    if (!(ocp = ft_strnew(0)))
      asm_error(MALLOC_ERR, NULL);
  }
    if (arg == REG_CODE)
      ft_strcat(ocp, "01");
    else if (arg == DIR_CODE)
      ft_strcat(ocp, "10");
    else if (arg == IND_CODE)
      ft_strcat(ocp, "11");
  return (ocp);
}

void write_ocp(t_asm_env *env, char *ocp)
{
  char *str;
  char res;

  while (ft_strlen(ocp) != 8)
    ft_strcat(ocp, "00");
  str = ft_convert_base(ocp, "01", "0123456789");
  res = ft_atoi(str);
  ft_putchar_fd(res, env->fd);
}

int  goto_nextarg(char *line)
{
  int a;

  a  = 0;
  while (line[a] && line[a] != SEPARATOR_CHAR)
    ++a;
  if (line[a] == SEPARATOR_CHAR)
    ++a;
  while(line[a] && (line[a] == ' ' || line[a] == '\t'))
    ++a;
  return (a);
}

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

void parse(t_asm_env *env, char *line, int printmode)
{
  int   a;
  char  *word;

  if (line && line[0] != '#')
  {
    a = 0;
    while (line[a] == ' ' || line[a] == '\t')
      ++a;
    if (!line[a] || line[a] == '#')
      return ;
    word = take_word(line + a);
    if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
      write_header(env, line, printmode);
      else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
      {
//    bullshit pour tester si le compteur d'octets fonctionne
//    on recuperera les label et leur postition soon
        if (!printmode)
          create_label(&env->labs , env->bytes, line + a);
        //  env->labs = create_label(&env->labs , env->bytes, line + a);
        while(ft_isalpha(line[a]) || ft_isdigit(line[a]))
          ++a;
        while (line[a] == ' ' || line[a] == '\t' || line[a] == ':')
          ++a;
        free(word);
        word = take_word(line + a);
        if (*word)
          env->bytes += find_op(env, word, line + a, printmode);
        }
      else
      {
        env->bytes += find_op(env, word, line + a, printmode);
      }
      free(word);
    }
//    printf("bytes = %d\n", env->bytes);
}

void  create_file(t_asm_env *env, char *str)
{
  int fd;
  int len;
  char *tmp;
  char *name;

  len = ft_strlen(str) - 2;
  tmp = ft_strndup(str, len);
  name = ft_strnew(len + 2);
  name = ft_strcpy(name, tmp);
  name = ft_strcat(name, ".cor");
  fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
  env->fd = fd;
}

int main (int argc, char **argv)
{
  int   fd;
  int   fd2;
  char  *line;
  t_asm_env env;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    asm_error(SOURCE_ERR, argv[1]);
  line = NULL;
  env.bytes = 1;
  while (get_next_line(fd, &line))
  {
   // printf("%s\n", line);
    parse(&env, line, 0);
    ft_memdel((void*)&line);
  }

//  printf("\n\nFinal bytes number = %d\n\n", env.bytes - 1);
  env.size = env.bytes - 1;
  create_file(&env, argv[1]);
  fd2 = open(argv[1], O_RDONLY);
  line = NULL;
  env.bytes = 1;
  while (get_next_line(fd2, &line))
  {
  //  printf("line = '%s'\n", line);
    parse(&env, line, 1);
    ft_memdel((void*)&line);
  }
  argv[1][ft_strlen(argv[1]) - 2] = '\0';
  ft_printf("Writting output program to %s.cor\n", argv[1]);
  return (0);
}
