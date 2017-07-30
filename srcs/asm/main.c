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
  printf("*** ENTER OCP ***\n");
  printf("line = %s\n", line);
}

void  op_no_ocp(int i, char *line)
{
  printf("*** ENTER NO OCP ***\n");
  printf("line = %s\n", line);
}

void find_op(char *word, char *line)
{
  int i;
  i = 0;
  while (op_tab[i].inst)
  {
    if (!ft_strcmp(word, op_tab[i].inst))
    {
      if (!op_tab[i].need_ocp)
        op_no_ocp(i, line);
      else
        op_ocp(i, line);
    }
    ++i;
  }
}

void parse(char *line)
{
  int   a;
  char  *word;

  a = 0;
  while (!ft_isprint(line[a]))
    ++a;
  word = take_word(line + a);
  printf("word = '%s' ", word);
  if (!ft_strcmp(word, NAME_CMD_STRING) || !ft_strcmp(word, COMMENT_CMD_STRING))
    printf("is head\n");
  else if (word[ft_strlen(word) - 1] == LABEL_CHAR)
    printf("is label\n");
  else
  {
    printf("is op\n");
    find_op(word, line);
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
