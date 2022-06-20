/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:53:32 by aababach          #+#    #+#             */
/*   Updated: 2022/06/20 13:29:25 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_protect2(char *name)
{
	int					fd;
	char				*str;
	int					i;
	struct s_elements	el;

	el.c = 0;
	el.e = 0;
	el.p = 0;
	fd = open(name, O_RDWR);
	str = malloc(sizeof(char));
	while (str)
	{
		i = 0;
		free(str);
		str = get_next_line(fd);
		while (str && str[i] && str[i] != '\n')
		{
			cringenorms(str[i], &el);
			i++;
		}
	}
	if (!el.e || !el.c || !el.p)
		ft_error();
	close(fd);
}

void	bruh(char c, int *x, int *y, t_ptr *l)
{
	if (c == 2)
	{
		*x = l->x + 64;
		*y = l->y;
	}
	if (c == 0)
	{
		*x = l->x - 64;
		*y = l->y;
	}
	if (c == 1)
	{
		*x = l->x;
		*y = l->y + 64;
	}
	if (c == 13)
	{
		*x = l->x;
		*y = l->y - 64;
	}
}

int	ft_test(int c, t_ptr *l)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	bruh(c, &x, &y, l);
	if (valid_move(l->map, x / 64, y / 64, l))
	{
		mlx_put_image_to_window(l->ptr, l->w_ptr, l->backg, l->x, l->y);
		mlx_put_image_to_window(l->ptr, l->w_ptr, l->backg, x, y);
		mlx_put_image_to_window(l->ptr, l->w_ptr, l->player, x, y);
		l->x = x;
		l->y = y;
		l->n_moves++;
		put_nbr(l->n_moves);
		write(1, "\n", 1);
	}
	if (c == 53)
		exit(0);
	return (0);
}

int	x_count(char *name)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(name, O_RDWR);
	i = 0;
	str = get_next_line(fd);
	while (str && str[i] && str[i] != '\n')
		i++;
	free(str);
	return (i);
}

int	main(int argc, char **argv)
{
	t_ptr	l;

	if (argc < 2)
		exit(0);
	map_protect(argv[1]);
	m_protect2(argv[1]);
	rect(argv[1]);
	ft_closed(argv[1]);
	l.n_moves = 0;
	l.ptr = mlx_init();
	l.w_ptr = \
	mlx_new_window(l.ptr, x_count(argv[1]) * 64, lines(argv[1]) * 64, "lol");
	l.backg = mlx_xpm_file_to_image(l.ptr, "grass.xpm", &argc, &argc);
	l.player = mlx_xpm_file_to_image(l.ptr, "plyr.xpm", &argc, &argc);
	l.obs = mlx_xpm_file_to_image(l.ptr, "obs.xpm", &argc, &argc);
	l.coin = mlx_xpm_file_to_image(l.ptr, "coin.xpm", &argc, &argc);
	l.ex = mlx_xpm_file_to_image(l.ptr, "exit.xpm", &argc, &argc);
	str_map(argv[1], &l);
	mlx_key_hook(l.w_ptr, ft_test, &l);
	mlx_hook(l.w_ptr, 17, 0, f_exit, l.ptr);
	put_nbr(l.n_moves);
	write(1, "\n", 1);
	mlx_loop(l.ptr);
}
