/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:21:51 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 18:06:45 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char *str, int *i, va_list param, int fd)
{
	t_format format;

	format = set_format(str, i, param);
	if (format.specifier == INT)
		return (print_int(param, format, fd));
	else if (format.specifier == CHAR)
		return (print_char(param, fd));
	else if (format.specifier == STR)
		return (print_str(param, fd, format));
	else if (format.specifier == OCTAL)
		return (print_octal(param, format, fd));
	else if (format.specifier == POINTER)
		return (print_pointer(param, fd));
	else if (format.specifier == HEXA_LOWER)
		return (print_hex(param, format, fd, LOWER));
	else if (format.specifier == HEXA_UPPER)
		return (print_hex(param, format, fd, UPPER));
	else if (format.specifier == UNSIGNED_INT)
		return (print_unsigned(param, format, fd));
	else if (format.specifier == FLOAT)
		return (print_float(param, format, fd));
	else if (format.specifier == PERCENTAGE)
		return (write(1, "%", fd));
	return (0);
}

int	print_char(va_list param, int fd)
{
	char c;

	c = va_arg(param, int);
	return (write(fd, &c, 1));
}

int	print_pointer(va_list param, int fd)
{
	long long unsigned int	nbr;
	char					*num;
	int						len;

	nbr = (long long unsigned int)va_arg(param, long unsigned int);
	num = ft_uitoa_base(nbr, 16, LOWER);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num) + 2;
	return (len);
}
