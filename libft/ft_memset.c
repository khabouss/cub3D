/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:49:05 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/22 19:49:09 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;
	unsigned int	i;

	i = 0;
	t = b;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
