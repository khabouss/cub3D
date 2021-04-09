/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:41:09 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:17:12 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		isbigger(char *s)
{
	int		n;
	char	*s1;
	int		i;

	i = 0;
	while (s[i] == '0' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		s[--i] = '0';
	n = ft_atoi(s + i);
	s1 = ft_itoa(n);
	i = !ft_strncmp(s1, s + i, ft_strlen(s + i));
	free(s1);
	return (i);
}

void	conditions_a(int key, int *a)
{
	if (key == 126 && g_up <= (g_height) / 5)
		g_up += g_height / 6;
	if (key == 125 && g_up >= 0)
		g_up -= g_height / 6;
	if (key == 1 && g_map[a[0]][a[1]] != 1 && g_map[a[0]][a[1]] != 2)
	{
		g_x -= 1.5*(g_wallsize / 3 * cos(g_vision_alpha));
		g_y -= 1.5*(g_wallsize / 3 * sin(g_vision_alpha));
	}
	if (key == 13 && g_map[a[2]][a[3]] != 1 && g_map[a[2]][a[3]] != 2)
	{
		g_x += 1.5*(g_wallsize / 3 * cos(g_vision_alpha));
		g_y += 1.5*(g_wallsize / 3 * sin(g_vision_alpha));
	}
}

void	conditions_b(int key, int *a)
{
	if (key == 0 && g_map[a[4]][a[5]] != 1 && g_map[a[4]][a[5]] != 2)
	{
		g_x += 2*(g_wallsize / 3 * cos(M_PI / 2 - g_vision_alpha));
		g_y -= 2*(g_wallsize / 3 * sin(M_PI / 2 - g_vision_alpha));
	}
	if (key == 2 && g_map[a[6]][a[7]] != 1 && g_map[a[6]][a[7]] != 2)
	{
		g_x -= 2*(g_wallsize / 3 * cos(M_PI / 2 - g_vision_alpha));
		g_y += 2*(g_wallsize / 3 * sin(M_PI / 2 - g_vision_alpha));
	}
	if (key == 123)
		g_vision_alpha -= 0.05;
	if (key == 124)
		g_vision_alpha += 0.05;
	if (key == 53)
		clickdetecter();
}

void	conditions(int key, int *a)
{
	conditions_a(key, a);
	conditions_b(key, a);
}
