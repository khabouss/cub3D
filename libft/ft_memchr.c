/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:48:14 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/23 21:40:15 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (void *)s;
	while (i < n)
	{
		if (st[i] == (char)c)
			return (&st[i]);
		i++;
	}
	return (NULL);
}
