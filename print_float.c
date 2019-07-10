/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 22:18:24 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_float(va_list param, t_format format, int fd)
{
	long double		nbr;
	long long int	integer;
	long double		decimal;
	char			*num;
	int				len;

	if (format.lengh == UPPER_L)
		nbr = va_arg(param, long double);
	else
		nbr = (long double)va_arg(param, double);
	integer = (long long int)nbr;
	num = ft_llitoa(integer);
	ft_putstr_fd(num, fd);
	ft_putchar_fd('.', fd);
	len = ft_strlen(num) + 1;
	decimal = nbr - integer + 1;
	integer = get_float(decimal, 6);
	num = precision_float(format.precision, integer, decimal);
	ft_putstr_fd((num + 1), fd);
	len += ft_strlen(num);
	return (len);
}

char	*precision_float(int p, long long int i, long double d)
{
	char	*num;

	if (get_float(d, p + 1) % i >= 5)
		i += 1;
	if (get_len_num_base(i, 10) > p)
	{
		while (--p >= 0)
			i /= 10;
	}
	num = ft_llitoa(i);
	return (num);
}