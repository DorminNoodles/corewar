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
//  printf("with oct %d line = '%s'\n", oct, line);
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
//  printf("oct = %d\n", oct);
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
  printf("\n---------------------\n");
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
  printf("Octets : %d\n", oct);
  printf("---------------------\n");
  return (oct);
}

int parse(char *line)
{
  int   a;
  int   oct;
  char  *word;
  int   bytes;

  bytes = 0;
  if (line && line[0] != '#')
  {
    a = 0;
    while (line[a] == ' ' || line[a] == '\t')
      ++a;
    if (!line[a] || line[a] == '#')
      return (0);
    oct = 0;
    word = take_word(line + a);
    if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
//    printf("is head\n");
      ;
      else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
      {
//    bullshit pour tester si le compteur d'octets fonctionne
//    on recuperera les label et leur postition soon
        while(ft_isalpha(line[a]) || ft_isdigit(line[a]))
          ++a;
        while (line[a] == ' ' || line[a] == '\t' || line[a] == ':')
          ++a;
        free(word);
        word = take_word(line + a);
        if (*word)
          bytes += find_op(word, line + a);
        }
      else
      {
        bytes += find_op(word, line + a);
      }
      free(word);
    }
    return (bytes); // JE TYPE EN RETURN INT POUR RECUPERER dans le main LE nb octect
    // bisous bisous
}

int main (int argc, char **argv)
{
  int   fd;
  char  *line;
  int   bytes;

  bytes = 0;
  fd = open(argv[1], O_RDONLY);
  line = NULL;
  while (get_next_line(fd, &line))
  {
  //  ft_memdel((void*)&line);
  //    printf("line size = %d\n", ft_strlen(line));
    bytes += parse(line);
  //  if (line)
      ft_memdel(&line);
      free(line);
  }
  printf("\n\nFinal bytes number = %d\n\n", bytes);
  return (0);
}
