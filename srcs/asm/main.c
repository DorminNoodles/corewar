#include "corewar.h"

char *take_word(char *str)
{
  int a;
  int len;
  char  *word;

  a = 0;
  len = 0;
  while (str[len] && str[len] != ' ' && str[len] != '\t')
    ++len;
  if (!(word = (char*)malloc(sizeof(char) * len + 1)))
    exit (0);
  word[len] = '\0';
  while (a != len)
  {
    word[a] = str[a];
    ++a;
  }
  return (word);
}

char  *moove_on_line(char *line)
{
  int a;

  a = 0;
  while (ft_isalpha(line[a]) || ft_isdigit(line[a]))
    ++a;
  while(line[a] == ' ' || line[a] == '\t')
    ++a;
  return (line + a);
}
/*
char *moove_until_space(char *line)
{
  int a;

  a = 0;
  while (ft_isprint(line[a]))
    ++a;
  ++a;
  return (line + a);
}

char  *moove_until_sep(char *line, int *a)
{
  printf("ENTER UNTIL SEPARATOR_CHAR '%s'\n", line + *a);
    while(line[*a] && line[*a] != SEPARATOR_CHAR)
      ++*a;
    if (!line[*a])
      return (NULL);
    ++*a;
    printf("EXIT UNTIL SEPARATOR_CHAR '%s'\n", line + *a);
    return (line + *a);
}

char *moove_until_print(char *line)
{
  int a;

  a = 0;
  if (line)
  {
    while (line[a] && line[a] == ' ' || line[a] == '\t')
      ++a;
      printf("EXIT UNTIL PRINT %s\n", line + a);
      return (line + a);
  }
  return (NULL);
}
*/
int   detect_arg(char *line)
{
  int a;

  a = 0;
  if (line[a] == 'r')
    return (REG_CODE);
  if (line[a] == LABEL_CHAR)
    return (IND_CODE);
  if (line [a] == DIRECT_CHAR)
    return (DIR_CODE);
  return (0);
}

void   test()
{
  char *str;
  char *res;
  char  ocp;

  str = "01010100";
  res = ft_convert_base(str, "01", "0123456789");
  ocp = ft_atoi(res);
  ft_printf("res= %x\n", ocp);
}

void  op_ocp(t_asm_env *env, int i, char *line)
{
  int  a;
  int res;
  char op;
  char ocp;

  test();
  a = 0;
  op = i;
  res = 0;
  ft_putchar_fd(op, env->fd);
  line = moove_on_line(line);
  while (line[a])
  {
    res = detect_arg(line + a);
    while (line[a] && line[a] != SEPARATOR_CHAR)
      ++a;
    if (line[a] == SEPARATOR_CHAR)
      ++a;
    while(line[a] && line[a] == ' ' || line[a] == '\t')
      ++a;
  }
  printf("\n");
}

void  op_no_ocp(t_asm_env *env, int i, char *line)
{
  char op;

  op = i;
  ft_putchar_fd(op, env->fd);
}

int analyse_args(int oct, char *line, int i)
{
  if (*line == 'r')
    oct += 1;
  else if (*line == '%')
  {
    if ((i == 0 || i == 1 || i == 5 || i == 6 || i == 7 || i == 13))
      oct += 4;
    else
      oct += 2;
  }
  else if (*line == ':' || ft_isdigit(*line))
    oct += 2;
  return (oct);
}

int  analyse(int oct, char *line, int i)
{
  int a;

  a = 0;
//  printf("'%s'\n", line);
  while (line[a] && line[a] != '\n')
  {
    while (line[a] == ':')
      ++a;
    while (line[a] && (line[a] == '-' || ft_isalpha(line[a]) || ft_isdigit(line[a])))
      ++a;
    while (line[a] && (line[a] == ' ' || line[a] == '\t'))
      ++a;
    if (line[a] == ',')
      ++a;
    oct = analyse_args(oct, line + a, i);
    if (line[a] == ',')
      a++; // pour la vrigule tmts
    if (line[a] == '%')
      a++;
    if (line[a] == '#')
      return (oct);
  }
    return (oct);
}

int find_op(t_asm_env *env, char *word, char *line, int printmode)
{
  int i;
  int tmp;
  int oct;

  oct = 1;
  i = 0;
  tmp = 0;
//  printf("\n---------------------\n");
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
//  printf("Octets : %d\n", oct);
//  printf("---------------------\n");
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
//    printf("is head\n");
      ;
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
  fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
  env->fd = fd;
}

int main (int argc, char **argv)
{
  int   fd;
  int   fd2;
  char  *line;
  t_asm_env env;

  fd = open(argv[1], O_RDONLY);
  line = NULL;
  while (get_next_line(fd, &line))
  {
    parse(&env, line, 0);
    ft_memdel((void*)&line);
  }
  printf("\n\nFinal bytes number = %d\n\n", env.bytes);
  print_labs_lst(env.labs);
  create_file(&env, argv[1]);
  fd2 = open(argv[1], O_RDONLY);
  line = NULL;
  while (get_next_line(fd2, &line))
  {
//    printf("line = '%s'\n", line);
    parse(&env, line, 1);
    ft_memdel((void*)&line);
  }
  return (0);
}
