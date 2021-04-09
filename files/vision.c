/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:49:13 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:12:48 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_intersection	g_hi;
t_intersection	g_vi;
double			g_l;
double			g_alpha;
int				g_n;
double			g_tetta;
double			g_tettaf1;
double			g_tettaf2;
double			g_tettaf;

void			vision(void)
{
	draw_heavens();
	g_alpha = g_vision_alpha - (M_PI / 6);
	g_n = 0;
	g_tetta = (M_PI / 3) / g_width * (-1);
	g_tettaf1 = -1;
	g_tettaf2 = -1;
	g_tettaf = -1;
	while (g_alpha < g_vision_alpha + (M_PI / 6))
	{
		draw_one(g_alpha, g_n, &g_l);
		g_alpha += (M_PI / 3) / g_width;
		g_n++;
	}
	calcul_sprite();
}
