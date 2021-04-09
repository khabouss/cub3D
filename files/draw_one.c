/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:24:26 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:16:43 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_intersection	g_hi;
t_intersection	g_vi;
double			g_lh;
double			g_lv;
int				*g_texture;
int				g_texture_width;
int				g_texture_height;

void			update_texture(int *a, int b, int c)
{
	g_texture = a;
	g_texture_width = b;
	g_texture_height = c;
}

void			m_condition(double alpha)
{
	if (g_lh > g_lv)
	{
		if (acosf(cosf(alpha)) < M_PI / 2)
			update_texture(g_texture3, g_texture_width1, g_texture_height1);
		else
			update_texture(g_texture4, g_texture_width2, g_texture_height2);
	}
	else
	{
		if (asinf(sinf(alpha)) > 0)
			update_texture(g_texture1, g_texture_width3, g_texture_height3);
		else
			update_texture(g_texture2, g_texture_width4, g_texture_height4);
	}
}

void			draw_one(double alpha, int n, double *l)
{
	double				slice_size;
	t_variables_wall	vars;

	g_hi = ghi(alpha);
	g_vi = gvi(alpha);
	g_lh = g_hi.l;
	g_lv = g_vi.l;
	*l = (g_lh > g_lv) ? g_lv : g_lh;
	g_int_col[n] = *l;
	m_condition(alpha);
	slice_size = g_wallsize * (((g_width / 2) / tanf(M_PI / 6))
	/ ((*l) * cosf(alpha - g_vision_alpha)));
	vars.l = slice_size;
	vars.px = n;
	vars.ix = (g_lh > g_lv) ? (sin(alpha) * (*l) + g_y)
							: cos(alpha) * (*l) + g_x;
	vars.texture = g_texture;
	vars.texture_width = g_texture_width;
	vars.texture_height = g_texture_height;
	vars.s = g_wallsize;
	wall(vars);
}
