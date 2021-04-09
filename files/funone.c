/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:16:39 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:55:15 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*g_errors[9] = {
	"Error\nMissing arguments",
	"Error\nwrong argument format",
	"Error\nMap file should end with .cub",
	"Error\nError while reading from cub file",
	"Error\nThere are some additional information",
	"Error\nResolution element is wrong",
	"Error\nOne or more elements are missing or wrong",
	"Error\nMap is missconfigured",
	"Error\nPlayer has not been found"
};

void	editemap(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_matrix_height)
	{
		j = 0;
		while (j < g_matrix_width)
		{
			if (g_map[i][j] == 8 || g_map[i][j] == ' ')
				g_map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int		return_print(char *s)
{
	printf("%s", s);
	return (0);
}

void	get_player_cord(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_matrix_height)
	{
		j = -1;
		while (++j < g_matrix_width)
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'W'
					|| g_map[i][j] == 'S' || g_map[i][j] == 'E')
			{
				g_x = (j + 0.5) * g_wallsize;
				g_y = (i + 0.5) * g_wallsize;
				if (g_map[i][j] == 'N')
					g_vision_alpha = (-1) * M_PI_2;
				if (g_map[i][j] == 'E')
					g_vision_alpha = 0;
				if (g_map[i][j] == 'W')
					g_vision_alpha = M_PI;
				if (g_map[i][j] == 'S')
					g_vision_alpha = M_PI_2;
			}
		}
	}
}

void	get_wall_size(void)
{
	if (g_matrix_width > g_matrix_height)
	{
		if (g_width > g_matrix_width)
			g_wallsize = g_width / g_matrix_width;
		else
			g_wallsize = g_matrix_width / g_width;
	}
	else
	{
		if (g_height > g_matrix_height)
			g_wallsize = g_height / g_matrix_height;
		else
			g_wallsize = g_matrix_height / g_height;
	}
	g_wallsize = 64;
}

int		initialize_game(int argc, char **argv)
{
	if (argc <= 1)
		return (return_print(g_errors[0]));
	if (argc > 2 && ft_strncmp(argv[2], "--save", 7) != 1)
		return (return_print(g_errors[1]));
	if (!cubextension(argv[1]))
		return (return_print(g_errors[2]));
	g_path = argv[1];
	if (readfile(g_path) != 1)
		return (return_print(g_errors[3]));
	if (readmap(getmapline() - 1) != 0)
		return (return_print(g_errors[4]));
	if (!varset())
		return (return_print(g_errors[6]));
	if (g_width <= 0 || g_height <= 0)
		return (return_print(g_errors[5]));
	if (checkmap())
		return (return_print(g_errors[7]));
	editemap();
	get_wall_size();
	get_player_cord();
	if (g_x == -1)
		return (return_print(g_errors[8]));
	return (1);
}
