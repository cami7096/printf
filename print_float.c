/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 19:23:45 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DEFAULT_PRECISION 6

int		print_float(va_list param, t_format format, int fd)
{
	long double		nbr;
	int				len;

	if (format.lengh == UPPER_L)
		nbr = va_arg(param, long double);
	else
		nbr = va_arg(param, double);
	if (format.precision == EMPTY)
		format.precision = DEFAULT_PRECISION;
	format.positive = (nbr < 0) ? 0 : 1;
	len = write_float(format, fd, nbr);
	return (len);
}

int		write_float(t_format format, int fd, long double nbr)
{
	long long int	integer;
	char			*num;
	char			*num_float;
	char			*str;
	int				len;

	len = (format.flags.plus && format.positive) ? 1 : 0;
	if (format.flags.space && !format.flags.plus)
		len++;
	integer = (long long int)nbr;
	num = ft_llitoa(integer);
	nbr = nbr - integer + 1;
	integer = get_float(nbr, format.precision + 1);
	num_float = precision_float(format.precision, integer, nbr);
	str = join_float(num, num_float);
	if (format.flags.minus)
		return (p_minus_f(format, str, fd));
	len += print_all_float(format, str, len, fd);
	return (len);
}

int		p_minus_f(t_format format, char *str, int fd)
{
	int len;

	len = 0;
	len += ft_strlen(str);
	len += print_flags(format, fd);
	ft_putstr_fd(str, fd);
	len += print_width(format, len, fd);
	return (len);
}

int		print_all_float(t_format format, char *str, int len, int fd)
{
	int start;

	start = 0;
	if (format.flags.zero && !format.positive)
	{
		ft_putchar_fd(str[0], fd);
		start = 1;
	}
	if (format.flags.zero && format.flags.plus && format.positive)
		write(fd, "+", 1);
	len += ft_strlen(str);
	len += print_width(format, len, fd);
	len += print_flags(format, fd);
	ft_putstr_fd(&str[start], fd);
	return (len);
}
