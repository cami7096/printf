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
		return (print_int(param, fd));
	else if (format.specifier == CHAR)
		return (print_char(param, fd));
	else if (format.specifier == STR)
		return (print_str(param, fd));
	else if (format.specifier == OCTAL)
		return (print_octal(param, fd));
	else if (format.specifier == POINTER)
		return (print_pointer(param, fd));
	else if (format.specifier == HEXA_LOWER)
		return (print_hex(param, fd, 1));
	else if (format.specifier == HEXA_UPPER)
		return (print_hex(param, fd, 0));
	return (0);
}

int	print_int(va_list param, int fd)
{
	int		nbr;
	char	*num;

	nbr = va_arg(param, int);
	num = ft_itoa_base((long)nbr, 10, 1);
	ft_putstr_fd(num, fd);
	return (ft_strlen(num));
}

int	print_char(va_list param, int fd)
{
	char c;

	c = va_arg(param, int);
	return (write(fd, &c, 1));
}

int	print_str(va_list param, int fd)
{
	char *str;

	str = va_arg(param, char*);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	print_octal(va_list param, int fd)
{
	int		nbr;
	char	*num;

	nbr = va_arg(param, int);
	num = ft_itoa_base(nbr, 8, 1);
	ft_putstr_fd(num, fd);
	return (ft_strlen(num));
}

int	print_pointer(va_list param, int fd)
{
	unsigned int	nbr;
	char			*num;

	nbr = (unsigned int)va_arg(param, unsigned int *);
	printf("%i\n", nbr);
	num = ft_itoa_base((int)nbr, 16, 1);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(num, fd);
	return ((ft_strlen(num) + 2));
}

int	print_hex(va_list param, int fd, int lower)
{
	unsigned int	nbr;
	char			*num;

	nbr = va_arg(param, unsigned int);
	num = ft_itoa_base((int)nbr, 16, lower);
	ft_putstr_fd(num, fd);
	return (ft_strlen(num));
}
