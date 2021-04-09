/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtwo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:16:48 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:35:43 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*g_texture1_id;
void	*g_texture2_id;
void	*g_texture3_id;
void	*g_texture4_id;
void	*g_textures_id;

int		checkmap(void)
{
	int i;
	int j;

	i = -1;
	if (playercount())
		return (1);
	while (++i < g_matrix_height)
	{
		j = 0;
		while (j < g_matrix_width)
		{
			if (g_map[i][j] == 0 || g_map[i][j] == 2
			|| ft_strrchr_o("WSNE", g_map[i][j]))
				if (!oneclosed_h(i, j) || !oneclosed_v(i, j))
					return (1);
			if (g_map[i][j] == ' ')
				if (checksurround(g_map, i, j, 0))
					return (1);
			if (g_map[i][j] != 1 && g_map[i][j] != 2 && g_map[i][j] != 8
			&& !ft_strrchr_o(" WSNE", g_map[i][j]) && g_map[i][j] != 0)
				return (1);
			j++;
		}
	}
	return (0);
}

int		varset(void)
{
	int	add;

	add = 0;
	initialize_textures(add);
	if (g_maplinefound == 0)
		return (0);
	if (g_width == -1 || g_height == -1)
		return (0);
	if (g_skycolor == (unsigned long)-1 || g_floorcolor == (unsigned long)-1)
		return (0);
	return (1);
}

int		cubextension(char *s)
{
	int		i;
	int		j;
	char	*cub;

	cub = ".cub";
	i = ft_strlen(s) - 1;
	j = 3;
	while (j)
	{
		if (s[i] != cub[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void	initialize_textures(int add)
{
	g_texture1_id = mlx_xpm_file_to_image(g_mlx_id, g_texturepaths[0],
			&g_texture_width1, &g_texture_height1);
	g_texture2_id = mlx_xpm_file_to_image(g_mlx_id, g_texturepaths[1],
			&g_texture_width2, &g_texture_height2);
	g_texture3_id = mlx_xpm_file_to_image(g_mlx_id, g_texturepaths[2],
			&g_texture_width3, &g_texture_height3);
	g_texture4_id = mlx_xpm_file_to_image(g_mlx_id, g_texturepaths[3],
			&g_texture_width4, &g_texture_height4);
	g_textures_id = mlx_xpm_file_to_image(g_mlx_id, g_texturepaths[4],
			&g_texture_widths, &g_texture_heights);
	if (!g_texture1_id || !g_texture2_id || !g_texture3_id
	|| !g_texture4_id || !g_textures_id)
	{
		printf("Error\ninvalid texture path");
		exit(-1);
	}
	g_texture1 = (int *)mlx_get_data_addr(g_texture1_id, &add, &add, &add);
	g_texture2 = (int *)mlx_get_data_addr(g_texture2_id, &add, &add, &add);
	g_texture3 = (int *)mlx_get_data_addr(g_texture3_id, &add, &add, &add);
	g_texture4 = (int *)mlx_get_data_addr(g_texture4_id, &add, &add, &add);
	g_textures = (int *)mlx_get_data_addr(g_textures_id, &add, &add, &add);
}

void	initvars(void)
{
	g_width = -1;
	g_height = -1;
	g_matrix_width = 0;
	g_matrix_height = 0;
	g_skycolor = -1;
	g_floorcolor = -1;
	g_x = -1;
	g_up = 0;
}
