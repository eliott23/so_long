#include "so_long.h"

int	valid_move(char **map, int x, int y, ptr *l)
{
	if (map[y][x] != '1' && map[y][x] != 'E')
	{
		if (map[y][x] == 'C')
		{
			map[y][x] = '0';
			l->n_coin--;
		}
		return (1);
	}
	if (map[y][x] == 'E' && !l->n_coin)
		exit(0);
	return (0);
}