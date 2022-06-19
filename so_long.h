/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:10:10 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 19:40:47 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

struct	elements{
	int	E;
	int	C;
	int	P;
};
void	put_nbr(int n);
void	ft_error();
typedef struct	p{
	void	*ptr;
	void	*w_ptr;
	void	*player;
	void	*backg;
	void	*obs;
	void	*coin;
	void	*ex;
	int		n_coin;
	int		x;
	int		y;
	char	**map;
	int		n_moves;
}ptr;
int		valid_move(char **map, int x, int y, ptr *l);
int		lines(char *name);
int		x_count(char *name);
void	str_map(char *name, ptr *l);
void	double_free(char **str, int y);
#endif
