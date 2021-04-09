/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:43:23 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/22 19:43:27 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	ptr = malloc(size * count);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
