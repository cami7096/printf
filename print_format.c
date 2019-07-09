/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:21:51 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/07 17:25:15 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char *str, int *i, va_list param, int fd)
{
	t_format format;

	format = set_format(str, i);
	if (format.specifier == INT)
		return (print_int(param, format, fd));
	else if (format.specifier == CHAR)
		return (print_char(param, fd));
	else if (format.specifier == STR)
		return (print_str(param, fd));
	else if (format.specifier == OCTAL)
		return (print_octal(param, fd));
	else if (format.specifier == POINTER)
		return (print_pointer(param, fd));
	else if (format.specifier == HEXA_LOWER)
		return (print_hex(param, fd, LOWER));
	else if (format.specifier == HEXA_UPPER)
		return (print_hex(param, fd, UPPER));
	else if (format.specifier == UNSIGNED_INT)
		return (print_unsigned(param, format, fd));
	else if (format.specifier == FLOAT)
		return (print_float(param, fd));
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

int	print_str(va_list param, int fd)
{
	char 	*str;
	int		len;

	str = va_arg(param, char*);
	ft_putstr_fd(str, fd);
	len = ft_strlen(str);
	return (len);
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

int	print_hex(va_list param, int fd, int lower)
{
	long unsigned int	nbr;
	char				*num;
	int					len;

	nbr = va_arg(param, long unsigned int);
	num = ft_uitoa_base(nbr, 16, lower);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num);
	return (len);
}

int print_float(va_list param, int fd)
{
	long double		nbr;
	long int		nbr1;
	long double		nbr2;
	char			*num;
	int				len;

	nbr = (long double)va_arg(param, double);
	nbr1 = (long int)nbr;
	num = ft_itoa(nbr1);
	ft_putstr_fd(num, fd);
	ft_putchar_fd('.', fd);
	len = ft_strlen(num) + 1;
	nbr2 = nbr - nbr1 + 1;
	nbr1 = get_float(nbr2, 6);
	if (get_float(nbr2, 6 + 1) % nbr1 >= 5)
		nbr1 += 1;
	num = ft_itoa(nbr1);
	ft_putstr_fd((num + 1), fd);
	len += ft_strlen(num);
	return (len);
}
