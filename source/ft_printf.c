/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:06:55 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 14:21:32 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_wo_specifier(const char *c)
{
	write (1, c, 1);
	return (1);
}

static int	print_w_specifier(const char c, va_list args)
{
	if (c == 'c')
		return (handle_c(va_arg(args, int)));
	if (c == 's')
		return (handle_s(va_arg(args, char *)));
	if (c == 'p')
		return (handle_ptr(va_arg(args, size_t)));
	if (c == 'd' || c == 'i')
		return (handle_nbr(va_arg(args, unsigned int)));
	if (c == 'u')
		return (handle_uint(va_arg(args, size_t)));
	if (c == 'x' || c == 'X')
		return (handle_hex(va_arg(args, size_t), c));
	if (c == '%')
		return (handle_pct());
	return (0);
}

int	ft_printf(const char *format, ...)
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
			j += print_w_specifier(format[i + 1], args);
			++i;
		}
		else
			k += print_wo_specifier(&format[i]);
		++i;
	}
	va_end(args);
	return (j + k);
}
