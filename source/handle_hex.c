/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 00:19:42 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 14:21:41 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	fill_hex(char **hexadecimal_num, unsigned int decimal_num, \
	char specifier, int len)
{
	size_t	remainder;

	*hexadecimal_num = malloc(len + 1);
	(*hexadecimal_num)[len] = '\0';
	len -= 1;
	while (decimal_num != 0)
	{
		remainder = decimal_num % 16;
		if (remainder < 10)
			(*hexadecimal_num)[len] = remainder + 48;
		else
		{
			if (specifier == 'X')
				(*hexadecimal_num)[len] = remainder + 55;
			else
				(*hexadecimal_num)[len] = remainder + 87;
		}
		decimal_num /= 16;
		--len;
	}
}

static int	get_hex_len(unsigned int decimal_num)
{
	int	i;

	i = 0;
	while (decimal_num != 0)
	{
		++i;
		decimal_num /= 16;
	}
	return (i);
}

int	handle_hex(unsigned int decimal_num, char specifier)
{
	char	*hexadecimal_num;
	int		len;

	len = get_hex_len(decimal_num);
	fill_hex(&hexadecimal_num, decimal_num, specifier, len);
	if (decimal_num == 0)
		len += handle_nbr(0);
	else
		handle_s(hexadecimal_num);
	free(hexadecimal_num);
	return (len);
}
