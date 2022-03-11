/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:51:56 by fbafica           #+#    #+#             */
/*   Updated: 2022/03/11 16:45:57 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	dhandle_s(int fd, char *s)
{
	int		i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		++i;
	}
	return (i);
}

int	handle_s(char *s)
{
	int		i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		++i;
	}
	return (i);
}
