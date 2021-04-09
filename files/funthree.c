/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funthree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:00 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:37:30 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clickdetecter(void)
{
	mlx_destroy_window(g_mlx_id, g_win_id);
	exit(0);
	return (0);
}

int	checksurround(char **mapp, int i, int j, char c)
{
	if (i != 0 && mapp[i - 1][j] == c)
		return (1);
	if (i != g_matrix_height - 1 && mapp[i + 1][j] == c)
		return (1);
	if (j + 1 < g_matrix_width && mapp[i][j + 1] == c)
		return (1);
	if (j != 0 && mapp[i][j - 1] == c)
		return (1);
	return (0);
}

int	oneclosed_h(int i, int j)
{
	int a;
	int closed;

	a = j - 1;
	closed = 0;
	while (a >= 0 && closed == 0)
	{
		if (g_map[i][a] == 1)
			closed++;
		if (g_map[i][a] == 8)
			return (0);
		a--;
	}
	a = j + 1;
	while (a < g_matrix_width && closed == 1)
	{
		if (g_map[i][a] == 1)
			closed++;
		a++;
	}
	if (closed == 2)
		return (1);
	else
		return (0);
}

int	oneclosed_v(int i, int j)
{
	int a;
	int closed;

	a = i - 1;
	closed = 0;
	while (a >= 0 && closed == 0)
	{
		if (g_map[a][j] == 1)
			closed++;
		if (g_map[a][j] == 8)
			return (0);
		a--;
	}
	a = i + 1;
	while (a < g_matrix_height && closed == 1)
	{
		if (g_map[a][j] == 1)
			closed++;
		a++;
	}
	if (closed == 2)
		return (1);
	else
		return (0);
}

int	playercount(void)
{
	int i;
	int j;
	int count;
	int count2;

	i = 0;
	count = 0;
	count2 = 0;
	while (i < g_matrix_height)
	{
		j = 0;
		while (j < g_matrix_width)
		{
			if (g_map[i][j] == 'W' || g_map[i][j] == 'S' ||
					g_map[i][j] == 'N' || g_map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (g_backslachn_index != -1 && g_backslachn_index < g_matrix_height)
		return (1);
	return (count > 1 || count2 > 1);
}
