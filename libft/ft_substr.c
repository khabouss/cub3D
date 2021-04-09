/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:01:46 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/22 20:01:50 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	p = malloc(len + 1);
	if (p == NULL)
		return (0);
	while (len--)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (char *)(p);
}
