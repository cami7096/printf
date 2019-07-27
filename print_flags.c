/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:46:11 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 20:22:21 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hash(t_format format, int fd)
{
	int len;

	len = 0;
	if (format.specifier == HEXA_LOWER && !format.flags.zero)
	{
		write(fd, "0x", 2);
		len += 2;
	}
	else if (format.specifier == POINTER)
	{
		write(fd, "0x", 2);
		len += 2;
	}
	else if (format.specifier == HEXA_UPPER && !format.flags.zero)
	{
		write(fd, "0X", 2);
		len += 2;
	}
	else if (format.specifier == OCTAL && format.positive &&
				!format.flags.zero)
	{
		write(fd, "0", 1);
		len += 1;
	}
	return (len);
}

int		print_flags(t_format format, int fd)
{
	int len;

	len = 0;
	if (format.flags.hash)
		len += print_hash(format, fd);
	if (format.flags.plus && format.positive &&
		!format.flags.zero &&
		(format.specifier == INT || format.specifier == FLOAT))
		len += write(fd, "+", 1);
	if (format.flags.space && !format.flags.plus &&
		(format.specifier == INT || format.specifier == FLOAT))
		len += write(fd, " ", 1);
	return (len);
}

int		print_minus(t_format format, char *num, int len, int fd)
{
	len = 0;
	len += (format.specifier == CHAR || format.specifier == PERCENTAGE)
	? 1 : ft_strlen(num);
	len += print_flags(format, fd);
	if (format.specifier == STR && format.precision < (int)ft_strlen(num)
		&& format.precision != EMPTY)
		len = ft_putnchar_fd(num, fd, format.precision);
	else
		ft_putstr_fd(num, fd);
	if (format.specifier != CHAR && format.specifier != STR)
		len += print_precision(format.precision, len, fd);
	len += print_width(format, len, fd);
	return (len);
}
