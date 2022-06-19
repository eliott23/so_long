/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:53:32 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 18:45:41 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	rect(char *name)
{
	int		fd;
	char	*str;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 1;
	fd = open(name, O_RDWR);
	str = get_next_line(fd);
	i = ft_strlen(str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str && i != ft_strlen(str))
			ft_error();
		count++;
	}
	close(fd);
	if (count <= 1)
		ft_error();
}

int	lines(char *name)
{
	int		fd;
	int		count;
	char	*str;

	count = -1;
	fd = open(name, O_RDWR);
	str = malloc(sizeof(char));
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	check_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			exit(2);
		i++;
	}
}

void	ft_closed(char *name)
{
	int		i;
	char	*str;
	int		fd;
	int		n_lines;

	i = 0;
	n_lines = lines(name);
	fd = open(name, O_RDWR);
	str = get_next_line(fd);
	check_line(str);
	while (--n_lines)
	{
		i = 0;
		free(str);
		str = get_next_line(fd);
		if (str[i] != '1')
			exit(2);
		while (str[i] && str[i] != '\n' && str[i + 1] != '\n')
			i++;
		if (str[i] != '1')
			exit(2);
	}
	check_line(str);
	free(str);
	close(fd);
}

void	m_protect2(char *name)
{
	int				fd;
	char			*str;
	int				i;
	struct elements	el;

	el.C = 0;
	el.E = 0;
	el.P = 0;
	fd = open(name, O_RDWR);
	str = malloc(sizeof(char));
	while (str)
	{
		i = 0;
		free(str);
		str = get_next_line(fd);
		while (str && str[i] && str[i] != '\n')
		{
			if (str[i] == 'E')
				el.E = 1;
			if (str[i] == 'C')
				el.C = 1;
			if (str[i] == 'P')
				el.P = 1;
			i++;
		}
	}
	if (!el.E || !el.C || !el.P)
		ft_error();
	close(fd);
}

int	ft_test(int c, ptr *l)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (c == 2)
	{
		x = l->x + 64;
		y = l->y;
	}
	if (c == 0)
	{
		x = l->x - 64;
		y = l->y;
	}
	if (c == 1)
	{
		x = l->x;
		y = l->y + 64;
	}
	if (c == 13)
	{
		x = l->x;
		y = l->y - 64;
	}
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

int	lol(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	ptr	l;

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
	mlx_hook(l.w_ptr, 17, 0, lol, l.ptr);
	put_nbr(l.n_moves);
	write(1, "\n", 1);
	mlx_loop(l.ptr);
}
