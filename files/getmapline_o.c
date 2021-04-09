/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmapline_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:12:42 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:29:50 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getmapline_o(char *line, int *mapline)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (g_maplinefound == 0)
		(*mapline) += 1;
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
		g_maplinefound = update_matrix_width(line);
	if (line[i] == 'E' || line[i] == 'W' || line[i] == 'N' || line[i] == 'S')
		if (line[i + 1] == '1' || line[i + 1] == '0' || line[i + 1] == '2')
			g_maplinefound = update_matrix_width(line);
	if (g_maplinefound == 1)
		g_matrix_height++;
	if (g_maplinefound == 1 && line[0] == '\0' && g_backslachn_index == -1)
		g_backslachn_index = g_matrix_height;
}

int		fivecondition(char *line, int i)
{
	int r;

	r = 0;
	r = get_resolution(line, i);
	if (r == 0)
		r = get_texture(line, i, 0, "NO");
	if (r == 0)
		r = get_texture(line, i, 1, "SO");
	if (r == 0)
		r = get_texture(line, i, 2, "WE");
	if (r == 0)
		r = get_texture(line, i, 3, "EA");
	if (r == 0)
		r = get_texture(line, i, 4, "S ");
	if (r == 0)
		r = get_color(line, i, &g_floorcolor, 'F');
	if (r == 0)
		r = get_color(line, i, &g_skycolor, 'C');
	if (r == 0)
		r = ismapline(line, i);
	if (line[i] == '\0')
		return (1);
	return (r);
}
