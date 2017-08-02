#include "corewar.h"

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
