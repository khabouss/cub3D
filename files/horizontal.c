/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:20:13 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:25:11 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_intersection	g_intersection;
double			g_ax;
double			g_ay;
double			g_upp;
int				g_i;
int				g_j;
int				g_found;

void			fun_h(double alpha)
{
	g_intersection.l = INT32_MAX;
	g_intersection.ls = 0;
	g_upp = asinf(sinf(alpha));
	if (g_upp < 0)
		g_ay = (floor((g_y / g_wallsize)) * g_wallsize);
	else
		g_ay = (floor((g_y / g_wallsize)) * g_wallsize) + g_wallsize;
	g_ax = g_x - (g_y - g_ay) / tanf(alpha);
	g_i = (g_ay - (g_upp < 0)) / g_wallsize;
	g_j = g_ax / g_wallsize;
	g_found = 0;
}

void			fun_h2(double alpha)
{
	if (g_map[g_i][g_j] == 2)
	{
		g_intersection.is_sprite = 1;
		g_intersection.ls = sqrt(powf(g_x - g_ax, 2) + powf(g_y - g_ay, 2));
	}
	if (g_map[g_i][g_j] == 1 && g_found == 0)
	{
		g_found = 1;
		g_intersection.l = sqrtl(powf(g_x - g_ax, 2) + powf(g_y - g_ay, 2));
		g_intersection.xi = g_ax;
		g_intersection.yi = g_ay;
	}
	if (g_upp < 0)
	{
		g_ax = g_ax - g_wallsize / tanf(alpha);
		g_ay = (g_ay) - (g_wallsize);
	}
	else
	{
		g_ax = g_ax + g_wallsize / tanf(alpha);
		g_ay = (g_ay) + (g_wallsize);
	}
}

t_intersection	ghi(double alpha)
{
	g_intersection.is_sprite = 0;
	if (g_x == 0 || g_y == 0)
		return (g_intersection);
	fun_h(alpha);
	while (g_j >= 0 && g_i >= 0 && g_i < g_matrix_height
	&& g_j < g_matrix_width)
	{
		fun_h2(alpha);
		g_j = g_ax / g_wallsize;
		g_i = (g_ay - (g_upp < 0)) / g_wallsize;
	}
	return (g_intersection);
}
