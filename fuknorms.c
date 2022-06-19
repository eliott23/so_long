/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuknorms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:34:45 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 18:41:52 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	put_nbr(int n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = (n % 10) + 48;
	write (1, &c, 1);
}
