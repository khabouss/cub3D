/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funseven.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:02:40 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:50:32 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall(t_variables_wall vars)
{
	int		xt;
	int		start;
	int		end;
	float	c[2];
	int		color;

	xt = -1;
	start = (g_height - vars.l) / 2 + g_up;
	end = (g_height + vars.l) / 2 + g_up;
	end = (end >= g_height) ? g_height : end;
	while (start++ < end)
	{
		c[0] = (++xt * vars.texture_height) / vars.l;
		c[1] = (((int)vars.ix % vars.s) * vars.texture_width / vars.s);
		color = 0;
		if (((int)c[0]) < vars.texture_height && (int)c[1] < vars.texture_width)
			color = vars.texture[((int)c[0]) * vars.texture_width + (int)c[1]];
		if (start >= 0 && color > 0x000000)
			draw_img(vars.px, start, vars.texture[((int)c[0])
					* vars.texture_width + (int)c[1]]);
	}
}

int		onclicklistener(int key)
{
	int a[8];

	a[0] = ((g_y - 1.5 * (g_wallsize / 1.5
					* sin(g_vision_alpha))) / g_wallsize);
	a[1] = ((g_x - 1.5 * (g_wallsize / 1.5
					* cos(g_vision_alpha))) / g_wallsize);
	a[2] = ((g_y + 1.5 * (g_wallsize / 1.5
					* sin(g_vision_alpha))) / g_wallsize);
	a[3] = ((g_x + 1.5 * (g_wallsize / 1.5
					* cos(g_vision_alpha))) / g_wallsize);
	a[4] = ((g_y - 1.5 * (g_wallsize / 1.5
					* sin(M_PI / 2 - g_vision_alpha))) / g_wallsize);
	a[5] = ((g_x + 1.5 * (g_wallsize / 1.5
					* cos(M_PI / 2 - g_vision_alpha))) / g_wallsize);
	a[6] = ((g_y + 1.5 * (g_wallsize / 1.5
					* sin(M_PI / 2 - g_vision_alpha))) / g_wallsize);
	a[7] = ((g_x - 1.5 * (g_wallsize / 1.5
					* cos(M_PI / 2 - g_vision_alpha))) / g_wallsize);
	conditions(key, a);
	vision();
	mlx_put_image_to_window(g_mlx_id, g_win_id, g_img_id, 0, 0);
	return (1);
}
