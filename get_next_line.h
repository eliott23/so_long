/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:29:54 by aababach          #+#    #+#             */
/*   Updated: 2022/02/20 21:35:23 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		myread(int fd, char **line, int buff_size);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *line, char *chyata);
char	*ft_clear(char *line, char **chyata);
int		ft_chyata(char *line, int i, char **chyata);
int		ft_length(char *str);
int		ft_is_clear(char *line);

#endif
