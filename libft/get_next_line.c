/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:58:19 by tkhabous          #+#    #+#             */
/*   Updated: 2019/11/14 17:02:06 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int g_buffer_size = 4;

int	free_m(char *str, int rt)
{
	free(str);
	return (rt);
}

int	store_controle(char *p, char **store, char *buff)
{
	*p++ = '\0';
	free(*store);
	*store = ft_strdup(p);
	return ((free_m(buff, 1)));
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*store;
	int			rt;
	char		*var[2];

	*line = (store) ? ft_strdup(store) : ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (g_buffer_size + 1));
	while (!(var[1] = ft_strchr(*line, '\n')))
	{
		if ((!buff || (rt = read(fd, buff, g_buffer_size)) < 0)
			&& free_m(buff, 1))
			return (-1);
		buff[rt] = '\0';
		if (rt == 0)
		{
			if (store != NULL)
				free(store);
			store = NULL;
			return (free_m(buff, 0));
		}
		var[0] = *line;
		*line = (!*line) ? ft_strdup(buff) : ft_strjoin(*line, buff);
		free(var[0]);
	}
	return (store_controle(var[1], &store, buff));
}
