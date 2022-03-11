/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:24:54 by fbafica           #+#    #+#             */
/*   Updated: 2022/03/11 16:52:27 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_factor(int n)
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

static	int	write_not_exception(int n)
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

int	handle_nbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
		return (write_not_exception(n) + 1);
	}
	else if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		return (write_not_exception(n));
}

static	int	dwrite_not_exception(int fd, int n)
{
	int		factor;
	char	c;
	int		i;

	factor = get_factor(n);
	i = 0;
	while (factor > 0)
	{
		c = (n / factor) + '0';
		write (fd, &c, 1);
		n = n % factor;
		factor /= 10;
		++i;
	}
	return (i);
}

int	dhandle_nbr(int fd, int n)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		return (dwrite_not_exception(fd, n) + 1);
	}
	else if (n == 0)
	{
		write (fd, "0", 1);
		return (1);
	}
	else
		return (dwrite_not_exception(fd, n));
}
