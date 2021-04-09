/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:41:09 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 18:13:27 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freearr(char **arr, int i)
{
	int	j;

	j = -1;
	if (g_width > 2560)
		g_width = 2560;
	if (g_height > 1440)
		g_height = 1440;
	while (++j < i)
		free(arr[j]);
}

int		ismapline(char *line, int i)
{
	int a;

	a = i;
	while (line[a] != '\0')
	{
		if (!ft_strrchr_o("102WSNE ", line[a]))
			return (0);
		a++;
	}
	return (1);
}
