/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:49:52 by fbafica           #+#    #+#             */
/*   Updated: 2022/03/11 16:50:47 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	handle_s(char *s);
int	handle_c(char c);
int	handle_pct(void);
int	handle_hex(unsigned int decimal_num, char specifier);
int	handle_ptr(size_t decimal_num);
int	handle_nbr(int n);
int	handle_uint(unsigned int n);
int	dhandle_s(int fd, char *s);
int	dhandle_c(int fd, char c);
int	dhandle_pct(int fd);
int	dhandle_hex(int fd, unsigned int decimal_num, char specifier);
int	dhandle_ptr(int fd, size_t decimal_num);
int	dhandle_nbr(int fd, int n);
int	dhandle_uint(int fd, unsigned int n);

#endif