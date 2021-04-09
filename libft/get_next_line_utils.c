/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:06:50 by tkhabous          #+#    #+#             */
/*   Updated: 2019/11/14 18:13:08 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	i = 0;
	p = malloc(sizeof(char *) * (l1 + ft_strlen(s2)));
	if (p == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		p[i + l1] = s2[i];
		i++;
	}
	p[i + l1] = '\0';
	return (p);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	const char *dest;

	if (!src)
		return ("");
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (NULL);
	ft_strcpy((char *)dest, (char *)src);
	return ((char *)dest);
}
