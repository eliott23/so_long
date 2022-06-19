/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:29:12 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 22:47:03 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_coin(t_ptr *l, int i, int fd)
{
	mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
	i = (i * 64) + 15.5;
	fd = (fd * 64) + 15.5;
	mlx_put_image_to_window(l->ptr, l->w_ptr, l->coin, i, fd);
	l->n_coin++;
}

void	d_e(t_ptr *l, int i, int fd)
{
	mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
	mlx_put_image_to_window(l->ptr, l->w_ptr, l->ex, i * 64, fd * 64);
}

void	d_p(t_ptr *l, int i, int fd)
{
	mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
	mlx_put_image_to_window(l->ptr, l->w_ptr, l->player, i * 64, fd * 64);
	l->x = i * 64;
	l->y = fd * 64;
}

void	f_norms(t_ptr *l, int i, int fd)
{
	if (l->map[fd][i] == '1')
		mlx_put_image_to_window(l->ptr, l->w_ptr, l->obs, i * 64, fd * 64);
	else if (l->map[fd][i] == 'C')
		draw_coin(l, i, fd);
	else if (l->map[fd][i] == 'E')
		d_e(l, i, fd);
	else if (l->map[fd][i] == 'P')
		d_p(l, i, fd);
	else if (l->map[fd][i] == '0')
		mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
	else
		ft_error();
}

void	str_map(char *name, t_ptr *l)
{
	int	y;
	int	i;
	int	fd;

	fd = open(name, O_RDWR);
	y = lines(name);
	l->map = malloc(sizeof(char *) * y);
	i = -1;
	while (++i < y)
		l->map[i] = get_next_line(fd);
	l->n_coin = 0;
	i = 0;
	fd = 0;
	while (fd < y)
	{
		i = 0;
		while (l->map[fd][i] && l->map[fd][i] != '\n')
		{
			f_norms(l, i, fd);
			i++;
		}
		fd++;
	}
}
