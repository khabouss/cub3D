/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:51:44 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:17:57 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_intersection	g_intersection;
double			g_bx;
double			g_by;
double			g_right;
int				g_i;
int				g_j;
int				g_found;

void			fun(double alpha)
{
	g_intersection.l = INT32_MAX;
	g_intersection.ls = 0;
	g_right = acosf(cosf(alpha));
	if (g_right < M_PI / 2)
		g_bx = (floor((g_x / g_wallsize)) * g_wallsize) + g_wallsize;
	else
		g_bx = (floor((g_x / g_wallsize)) * g_wallsize);
	g_by = g_y - (g_x - g_bx) * tanf(alpha);
	g_i = g_by / g_wallsize;
	g_j = (g_bx - (g_right >= M_PI / 2)) / g_wallsize;
	g_found = 0;
}

void			fun_2(double alpha)
{
	if (g_map[g_i][g_j] == 2)
	{
		g_intersection.is_sprite = 1;
		g_intersection.ls = sqrt(powf(g_x - g_bx, 2) + powf(g_y - g_by, 2));
	}
	if (g_map[g_i][g_j] == 1 && g_found == 0)
	{
		g_found = 1;
		g_intersection.l = sqrtl(powf(g_x - g_bx, 2) + powf(g_y - g_by, 2));
		g_intersection.xi = g_bx;
		g_intersection.yi = g_by;
	}
	if (g_right < M_PI / 2)
	{
		g_bx = g_bx + g_wallsize;
		g_by = (g_by) + (g_wallsize * tanf(alpha));
	}
	else
	{
		g_bx = g_bx - g_wallsize;
		g_by = (g_by) - (g_wallsize * tanf(alpha));
	}
}

t_intersection	gvi(double alpha)
{
	g_intersection.is_sprite = 0;
	if (g_x == 0 || g_y == 0)
		return (g_intersection);
	fun(alpha);
	while (g_j >= 0 && g_i >= 0 && g_i < g_matrix_height
	&& g_j < g_matrix_width)
	{
		fun_2(alpha);
		g_j = (g_bx - (g_right >= M_PI / 2)) / g_wallsize;
		g_i = g_by / g_wallsize;
	}
	return (g_intersection);
}
