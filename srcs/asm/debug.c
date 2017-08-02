#include "corewar.h"

void print_labs_lst (t_tab_labs *lst)
{
	int			count;
	t_tab_labs *tmp;

	count = 0;
	tmp = lst;
	printf("Labels list :\n");
	while (tmp && tmp->label)
	{
		printf("%d - '%s' at + %d bytes\n", count, tmp->label, tmp->nb_oct);
		tmp = tmp->next;
		++count;
	}
	printf("\n");
}
