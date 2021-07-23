/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:49:52 by fbafica           #+#    #+#             */
/*   Updated: 2021/07/20 22:47:35 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_s(char *s);
int	handle_c(char c);
int	handle_pct(void);
int	handle_hex(unsigned int decimal_num, char specifier);
int	handle_ptr(size_t decimal_num);
int	handle_nbr(int n);
int	handle_uint(unsigned int n);

#endif