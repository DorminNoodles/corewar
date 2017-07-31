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
    ++oct;
  else if (*line == '%')
  {
    printf("pourcent oct = %d i = %d\n", oct);
    if (i == 1 || i == 2 || i == 6 || i == 7 || i == 9 || i == 13)
      oct += 4;
    else
      oct += 2;
  }
  else if (*line == ':')
    oct += 2;
  printf("'%s' - oct  = %d\n", line, oct);
  return (oct);
}

int  analyse(int oct, char *line, int i)
{
  int a;

  a = 0;
  printf("%s\n", line);
  while (line[a])
  {
    while (line[a] == ':')
      ++a;
    while (line[a] && (ft_isalpha(line[a]) || ft_isdigit(line[a])))
      ++a;
//      printf("line + %d = '%s'\n", a, line + a);
    while (line[a] && (line[a] == ' ' || line[a] == '\t'))
      ++a;
//      printf("2line + %d = '%s'\n", a, line + a);
    oct = analyse_args(oct, line + a, i);
//    printf("a = %d\n", a);
    if (line[a] == ',')
      a++; // pour la vrigule tmts
    if (line[a] == '%')
      a++;
  }
    return (oct);
}

void find_op(char *word, char *line)
{
  int i;
  int tmp;
  int oct;

  oct = 1;
  i = 0;
  printf("%s\n", word);
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
    }
    ++i;
  }
  printf("tmp = %d\n", tmp);
  oct = analyse(oct, line, tmp);
  printf("%d\n", oct);
}

void parse(char *line)
{
  int   a;
  int   oct;
  char  *word;

  a = 0;
  oct = 0;
  while (!ft_isprint(line[a]))
    ++a;
  word = take_word(line + a);
//  printf("word = '%s' ", word);
  if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
//    printf("is head\n");
      ;
  else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
  {
    ;
//    printf("is label\n");
//    bullshit pour tester si le compteur d'octets fonctionne
//    on recuperera les label et leur postition soon
      while(ft_isalpha(line[a]) || ft_isdigit(line[a]))
        ++a;
      while (line[a] == ' ' || line[a] == ':')
        ++a;
      printf("before find op = '%s'\n", line + a);
      if (line + a) // si, ex: l2: '\n'
        find_op(word, line + a);
  }
  else
  {
//    printf("is op\n");
    find_op(word, line + a);
  }
}

int main (int argc, char **argv)
{
  int   fd;
  char  *line;

  line = NULL;
  fd = open(argv[1], O_RDONLY);
  while (get_next_line(fd, &line))
  {
    if (ft_strlen(line))
    {
        parse(line);
        free(line);
    }
//      printf("%s\n", line);
//    if (ft_strlen(line))
  }
  return (0);
}
