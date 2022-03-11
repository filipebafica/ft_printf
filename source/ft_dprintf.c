/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:06:55 by fbafica           #+#    #+#             */
/*   Updated: 2022/03/11 17:26:38 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	dprint_wo_specifier(int fd, const char *c)
{
	write (fd, c, 1);
	return (1);
}

static int	dprint_w_specifier(int fd, const char c, va_list args)
{
	if (c == 'c')
		return (dhandle_c(fd, va_arg(args, int)));
	if (c == 's')
		return (dhandle_s(fd, va_arg(args, char *)));
	if (c == 'p')
		return (dhandle_ptr(fd, va_arg(args, size_t)));
	if (c == 'd' || c == 'i')
		return (dhandle_nbr(fd, va_arg(args, unsigned int)));
	if (c == 'u')
		return (dhandle_uint(fd, va_arg(args, size_t)));
	if (c == 'x' || c == 'X')
		return (dhandle_hex(fd, va_arg(args, size_t), c));
	if (c == '%')
		return (dhandle_pct(fd));
	return (0);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		k;

	va_start(args, format);
	i = 0;
	j = 0;
	k = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			j += dprint_w_specifier(fd, format[i + 1], args);
			++i;
		}
		else
			k += dprint_wo_specifier(fd, &format[i]);
		++i;
	}
	va_end(args);
	return (j + k);
}
