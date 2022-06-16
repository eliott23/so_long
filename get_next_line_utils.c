/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:36:35 by aababach          #+#    #+#             */
/*   Updated: 2022/02/17 16:32:26 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
			i++;
		rtn = malloc (sizeof(char) * (i + 1));
		if (!rtn)
			return (0);
		while (j < i)
		{
			rtn[j] = str[j];
			j++;
		}
		rtn[j] = 0;
		return (rtn);
	}
	return (0);
}

int	ft_length(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *chyata)
{
	int		i;
	int		j;
	int		line_len;
	int		chyata_len;
	char	*joined;

	line_len = ft_length(line);
	chyata_len = ft_length(chyata);
	joined = malloc (sizeof(char) * (line_len + chyata_len + 1));
	if (!joined)
		return (0);
	i = 0;
	j = 0;
	while (i < chyata_len)
	{
		joined[i] = chyata[i];
		i++;
	}
	while (i < chyata_len + line_len)
		joined[i++] = line[j++];
	joined[i] = 0;
	free(chyata);
	return (joined);
}

int	ft_chyata(char *line, int i, char **chyata)
{
	int	j;

	j = 0;
	*chyata = malloc(sizeof(char) * (ft_length(line) - i + 1));
	if (!*chyata)
		return (0);
	while (line[i])
		(*chyata)[j++] = line[i++];
	(*chyata)[j] = 0;
	return (0);
}

char	*ft_clear(char *line, char **chyata)
{
	int		i;
	int		j;
	char	*newline;

	j = 0;
	i = 0;
	while (line[j] != '\n')
		j++;
	newline = malloc (sizeof(char) * (j + 2));
	if (!newline)
		return (0);
	while (i < j)
	{
		newline[i] = line[i];
		i++;
	}
	newline[i++] = '\n';
	newline[i] = 0;
	ft_chyata(line, i, chyata);
	free(line);
	return (newline);
}
