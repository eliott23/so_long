/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuknorms2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:26:34 by aababach          #+#    #+#             */
/*   Updated: 2022/06/19 21:26:55 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
