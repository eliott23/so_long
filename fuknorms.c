/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuknorms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:34:45 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 21:26:18 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_move(char **map, int x, int y, t_ptr *l)
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

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (!s1[i] && !s2[i])
			return (1);
	}
	return (0);
}

int	map_protect(char *m_name)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (m_name[i])
	{
		while (m_name[i] && m_name[i] != '.')
			i++;
		if (m_name[i] == '.')
			j = i;
		if (m_name[i])
			i++;
	}
	if (m_name[j])
	{
		if (!str_cmp(".ber", m_name + j))
			ft_error();
		return (1);
	}
	write(1, "Error\n", 6);
	exit(0);
}
