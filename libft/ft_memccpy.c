/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:48:01 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/23 21:31:50 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)src)[i] == (char)c)
		{
			((char*)dest)[i] = ((char *)src)[i];
			return (&((char *)dest)[i + 1]);
		}
		else
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (NULL);
}
