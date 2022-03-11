/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:11:28 by fbafica           #+#    #+#             */
/*   Updated: 2022/03/11 16:43:30 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dhandle_pct(int fd)
{
	char	c;

	c = '%';
	write(fd, &c, 1);
	return (1);
}

int	handle_pct(void)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}
