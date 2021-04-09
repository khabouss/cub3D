/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funfive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:59:48 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:06:51 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture(char *line, int i, int k, char *c)
{
	int j;

	if (line[i] == 'N')
		j = 0;
	if (line[i] != '\0' && line[i] == c[0] && line[i + 1] == c[1])
	{
		if (g_texturepaths[k] != NULL)
			return (0);
		j = i + 2;
		while (line[j] != '\0' && line[j] == ' ')
			j++;
		g_texturepaths[k] = ft_strdup(line + j);
		return (1);
	}
	return (0);
}

int	free_and_return(char **data, int a)
{
	free(data[0]);
	free(data[1]);
	free(data[2]);
	free(data);
	return (a);
}

int	get_color(char *line, int i, unsigned long *color, char c)
{
	char	**d;
	int		j;

	if (line[i] != '\0' && line[i] == c && line[i + 1] == ' ')
	{
		if (*color != (unsigned long)-1)
			return (0);
		j = i + 2;
		if (count(line + j, ',') != 2)
			return (0);
		d = ft_split(line + j, ',');
		if (!is_digit(d[0]) || !is_digit(d[1]) || !is_digit(d[2]))
			return (free_and_return(d, 0));
		if (is_all_space(d[0]) || is_all_space(d[1])
				|| is_all_space(d[2]))
			return (free_and_return(d, 0));
		if (ft_atoi(d[0]) > 255 || ft_atoi(d[1]) > 255 || ft_atoi(d[2]) > 255
			|| ft_atoi(d[0]) < 0 || ft_atoi(d[1]) < 0 || ft_atoi(d[2]) < 0
			|| isbigger(d[0]) || isbigger(d[1]) || isbigger(d[2]))
			return (0);
		*color = getcolor(ft_atoi(d[0]), ft_atoi(d[1]), ft_atoi(d[2]));
		free_and_return(d, 0);
		return (1);
	}
	return (0);
}

int	readfile(char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) != 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (!fivecondition(line, i))
			return (0);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

int	update_matrix_width(char *line)
{
	if (ft_strlen(line) >= (unsigned long)g_matrix_width)
		g_matrix_width = ft_strlen(line);
	return (1);
}
