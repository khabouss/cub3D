/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:01:14 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/22 20:01:17 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*t;

	i = 0;
	t = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			t = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return (t);
}

int		ft_strrchr_o(const char *s, int c)
{
	int			i;
	int			t;

	i = 0;
	t = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			t = 1;
		s++;
	}
	return (t);
}
