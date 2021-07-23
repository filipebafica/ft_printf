/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:24:54 by fbafica           #+#    #+#             */
/*   Updated: 2021/07/20 23:02:39 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static	int	get_factor(unsigned int n)
{
	int	factor;

	factor = 1;
	while (n > 9)
	{
		n /= 10;
		factor *= 10;
	}
	return (factor);
}

static	int	write_not_exception(unsigned int n)
{
	int		factor;
	char	c;
	int		i;

	factor = get_factor(n);
	i = 0;
	while (factor > 0)
	{
		c = (n / factor) + '0';
		write (1, &c, 1);
		n = n % factor;
		factor /= 10;
		++i;
	}
	return (i);
}

int	handle_uint(unsigned int n)
{
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		return (write_not_exception(n));
}
