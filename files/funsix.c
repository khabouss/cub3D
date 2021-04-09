/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funsix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:01:53 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:43:37 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	num_of_params(char *line)
{
	int i;
	int params;

	i = 1;
	params = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i - 1] == ' ')
			params++;
		i++;
	}
	return (params);
}

int	is_digit(char *s)
{
	int i;
	int dig;

	i = 0;
	dig = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ')
		{
			return (0);
		}
		if (ft_isdigit(s[i]))
		{
			dig++;
		}
		i++;
	}
	if (dig == 0)
		return (0);
	return (1);
}

int	is_all_space(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	count(char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

int	get_resolution(char *line, int i)
{
	char	**data;

	if (line[i] != '\0' && line[i] == 'R'
			&& line[i + 1] == ' ' && num_of_params(line + i) == 2)
	{
		data = ft_split(line + i, ' ');
		if (g_width != -1 || g_height != -1 ||
				!is_digit(data[1]) || !is_digit(data[2]))
			return (0);
		if (isbigger(data[1]))
			g_width = 2560;
		else
			g_width = ft_atoi(data[1]);
		if (isbigger(data[2]))
			g_height = 1440;
		else
			g_height = ft_atoi(data[2]);
		freearr(data, 3);
		return (1);
	}
	return (0);
}
