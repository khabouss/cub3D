/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:49:47 by tkhabous          #+#    #+#             */
/*   Updated: 2019/10/22 19:49:51 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int newvar;

	newvar = n;
	if (n < 0)
	{
		newvar = -n;
		ft_putchar_fd('-', fd);
	}
	if (newvar <= 9)
	{
		ft_putchar_fd(newvar + 48, fd);
	}
	if (newvar > 9)
	{
		ft_putnbr_fd(newvar / 10, fd);
		ft_putchar_fd(newvar % 10 + 48, fd);
	}
}
