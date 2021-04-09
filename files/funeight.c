/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funeight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:02:49 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:11:39 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	getcolor(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void			draw_img(int xcor, int ycor, int color)
{
	if (ycor < g_height && xcor < g_width)
		g_pixels[ycor * g_width + xcor] = color;
}

void			rect_draw(int rect_width, int rect_height, int y, int color)
{
	int	len;
	int	mlen;

	len = rect_width;
	while (len-- != 0)
	{
		mlen = y + rect_height;
		while (mlen-- != y)
			draw_img(len, mlen, color);
	}
}

void			draw_heavens(void)
{
	if (g_up <= 0)
	{
		rect_draw(g_width, g_height / 2 - fabs(g_up)
				, 0, g_skycolor);
		rect_draw(g_width, g_height / 2 + fabs(g_up)
				, g_height / 2 - fabs(g_up), g_floorcolor);
	}
	else
	{
		rect_draw(g_width, g_height / 2 + fabs(g_up)
				, 0, g_skycolor);
		rect_draw(g_width, g_height / 2 - fabs(g_up)
				, g_height / 2 + fabs(g_up), g_floorcolor);
	}
}
