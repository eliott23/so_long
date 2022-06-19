#include "so_long.h"

int	f_exit(void)
{
	exit(0);
}

void	cringenorms(char c, struct s_elements *el)
{
	if (c == 'E')
		el->e = 1;
	if (c == 'C')
		el->c = 1;
	if (c == 'P')
		el->p = 1;
}