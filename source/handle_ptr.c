/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 00:19:42 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 14:22:00 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	fill_hex(char **hexadecimal_num, size_t decimal_num, int len)
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
			(*hexadecimal_num)[len] = remainder + 87;
		}
		decimal_num /= 16;
		--len;
	}
}

static	int	get_hex_len(size_t decimal_num)
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

int	handle_ptr(size_t decimal_num)
{
	char	*hexadecimal_num;
	int		len;

	len = get_hex_len(decimal_num);
	fill_hex(&hexadecimal_num, decimal_num, len);
	handle_s("0x");
	if (decimal_num == 0)
		len += handle_nbr(0);
	else
		handle_s(hexadecimal_num);
	free(hexadecimal_num);
	return (len + 2);
}
