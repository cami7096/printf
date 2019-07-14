/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/13 23:57:59 by cbernabo         ###   ########.fr       */
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

	len = (format.flags.plus) ? 1 : 0;
	integer = (long long int)nbr;
	num = ft_llitoa(integer);
	nbr = nbr - integer + 1;
	integer = get_float(nbr, format.precision + 1);
	num_float = precision_float(format.precision, integer, nbr);
	str = join_float(num, num_float);
	if (format.flags.minus)
		return (p_minus_f(format, str, fd));
	len += ft_strlen(str + 0);
	len += print_width(format.width, len, fd);
	len += print_flags(format, fd);
	ft_putstr_fd(str, fd);
	return (len);
}

char	*precision_float(int p, long long int i, long double d)
{
	char	*num;
	int		lengh_num;
	int		j;

	j = 0;
	lengh_num = get_len_num_base(i, 10);
	while (get_float(d, j++ + 1) % i >= 5 && j < p)
		i += 1;
	if (lengh_num > p)
	{
		p = lengh_num - p;
		while (--p > 0)
			i /= 10;
	}
	else if (lengh_num < p)
	{
		while (p-- > 0)
			i *= 10;
		i += 1;
	}
	num = ft_llitoa(i);
	return (num);
}

int		p_minus_f(t_format format, char *str, int fd)
{
	int len;

	len = ft_strlen(str);
	len += print_flags(format, fd);
	ft_putstr_fd(str, fd);
	len += print_width(format.width, len, fd);
	return (len);
}

char	*join_float(char *num, char *num_float)
{
	char *res;
	char *final;

	res = ft_strjoin(num, ".");
	final = ft_strjoin(res, num_float + 1);
	return (final);
}
