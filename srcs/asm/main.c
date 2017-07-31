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
    if ((i == 0 || i == 1 || i == 6 || i == 7 || i == 13))
      oct += 4;
    else
      oct += 2;
  }
  else if (*line == ':')
    oct += 2;
  return (oct);
}

int  analyse(int oct, char *line, int i)
{
  int a;

  a = 0;
  printf("ANALYSE - %s\n", line);
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
  printf("word '%s'\n", word);
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
  oct = analyse(oct, line, tmp);
  printf(" ****** NB OCT %d ******\n", oct);
  return (oct);
}

int parse(char *line)
{
  int   a;
  int   oct;
  char  *word;
  int   bytes;

  a = 0;
  oct = 0;
  bytes = 0;
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
//    bullshit pour tester si le compteur d'octets fonctionne
//    on recuperera les label et leur postition soon
      while(ft_isalpha(line[a]) || ft_isdigit(line[a]))
        ++a;
      while (line[a] == ' ' || line[a] == '\t' || line[a] == ':')
        ++a;
      free(word);
      printf("line + a = '%s'\n", line + a);
      word = take_word(line + a);
      if (*word)
        bytes += find_op(word, line + a);
  }
  else
  {
//    printf("is op\n");
    bytes += find_op(word, line + a);
  }
  return (bytes); // JE TYPE EN RETURN INT POUR RECUPERER dans le main LE nb octect
  // bisous bisous
}

int main (int argc, char **argv)
{
  int   fd;
  char  *line;
  int   bytes;

  line = NULL;
  bytes = 0;
  fd = open(argv[1], O_RDONLY);
  while (get_next_line(fd, &line))
  {
    if (ft_strlen(line))
    {
        bytes += parse(line);
        //  free(line); Ca double free ici, je ne sais pas pourquoi - peut etre mon gnl
    }
  }
  printf("Final bytes number = %d\n", bytes);
  return (0);
}
