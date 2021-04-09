/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funfour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:59:41 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:03:22 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		getmapline(void)
{
	int		fd;
	char	*line;
	int		mapline;

	fd = open(g_path, O_RDONLY);
	mapline = 0;
	g_maplinefound = 0;
	g_backslachn_index = -1;
	while (get_next_line(fd, &line) != 0)
	{
		getmapline_o(line, &mapline);
		free(line);
	}
	free(line);
	g_matrix_height++;
	return (mapline);
}

void	*ft_set(void *b, int c, size_t len)
{
	unsigned char	*t;
	unsigned int	i;

	i = 0;
	t = b;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	alloc_map(void)
{
	int i;

	i = 0;
	g_map = (char **)malloc(sizeof(char *) * (g_matrix_height + 1));
	while (i <= g_matrix_height)
	{
		g_map[i] = (char *)malloc(sizeof(char) * g_matrix_width);
		ft_set(g_map[i], 8, sizeof(char) * g_matrix_width);
		i++;
	}
}

void	fill_map(char *line, int l, int mapline, int *error)
{
	int a;
	int b;

	b = ft_strlen(line);
	a = 0;
	while (a < g_matrix_width)
	{
		if (a <= b)
		{
			if (line[a] == ' ')
				g_map[l - mapline][a] = ' ';
			if (line[a] == '1')
				g_map[l - mapline][a] = 1;
			if (line[a] == '0')
				g_map[l - mapline][a] = 0;
			if (line[a] == '2')
				g_map[l - mapline][a] = 2;
			if (ft_strrchr_o("SWEN", line[a]))
				g_map[l - mapline][a] = line[a];
			if (!ft_strrchr_o("SWEN 102", line[a]) && line[a] != '\0')
				*error = l - mapline;
		}
		a++;
	}
}

int		readmap(int mapline)
{
	int		i;
	int		error;
	int		fd;
	char	*line;

	i = 0;
	error = 0;
	alloc_map();
	fd = open(g_path, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		if (i >= mapline)
			fill_map(line, i, mapline, &error);
		free(line);
		i++;
	}
	fill_map(line, i, mapline, &error);
	free(line);
	close(fd);
	return (error);
}
