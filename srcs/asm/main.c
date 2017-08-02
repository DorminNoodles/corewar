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

void  op_ocp(int i, char *line)
{
  /*printf("*** ENTER OCP ***\n")*/;
//  printf("line = %s\n", line);
}

void  op_no_ocp(int i, char *line)
{
/*  printf("*** ENTER NO OCP ***\n")*/;
//  printf("line = %s\n", line);
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
  printf("%s\n", line);
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

int find_op(char *word, char *line)
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
        op_no_ocp(i, line);
      }
      else
      {
        tmp = i;
        ++oct;
        op_ocp(i, line);
      }
      oct = analyse(oct, line, tmp);
    }
    ++i;
  }
//  printf("Octets : %d\n", oct);
//  printf("---------------------\n");
  return (oct);
}

t_tab_labs    *new_label(char *line, int bytes)
{
  int         a;
  int         len;
  char        *name;
  t_tab_labs  *new;

  len = 0;
  while (line[len] != ':')
    ++len;
  if (!(name = ft_strnew(len)))
      error("Error : Malloc failed\n");
  a = 0;
  while (a != len)
  {
    name[a] = line[a];
    ++a;
  }
  if (!(new = (t_tab_labs*)malloc(sizeof(t_tab_labs))))
      error("Error : Malloc failed\n");
  new->label = ft_strdup(name);
  new->nb_oct = bytes;
  new->next = NULL;
  return (new);
}

void  create_label(t_tab_labs **labels, int bytes, char *line)
{
  t_tab_labs *tmp;

  tmp = *labels;
  if (tmp)
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new_label(line, bytes);

  }
  else
    *labels = new_label(line, bytes);
}

void parse(t_asm_env *env, char *line, int checkmode)
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
        if (checkmode)
        //  env->labs = create_label(&env->labs , env->bytes, line + a);
          create_label(&env->labs , env->bytes, line + a);
        while(ft_isalpha(line[a]) || ft_isdigit(line[a]))
          ++a;
        while (line[a] == ' ' || line[a] == '\t' || line[a] == ':')
          ++a;
        free(word);
        word = take_word(line + a);
        if (*word)
          env->bytes += find_op(word, line + a);
        }
      else
      {
        env->bytes += find_op(word, line + a);
      }
      free(word);
    }
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
    parse(&env, line, 1);
    ft_memdel((void*)&line);
  }
  printf("\n\nFinal bytes number = %d\n\n", env.bytes);
  print_labs_lst(env.labs);

/*  while (env.labs && env.labs->label)
  {
    printf("%s\n", env.labs->label);
    env.labs = env.labs->next;
  }*/
/*  fd2 = open(argv[1], O_RDONLY);
  line = NULL;
  while (get_next_line(fd2, &line))
  {
    printf("line = %s\n", line);
    parse(&env, line, 0);
    ft_memdel((void*)&line);
  }*/
  return (0);
}
