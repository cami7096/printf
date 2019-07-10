/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:21:22 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/08 22:21:33 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_octal(va_list param, t_format format, int fd)
{
	long long int		nbr;
	char				*num;
	int					len;

	if (format.lengh == LOWER_L)
        nbr = (long long int)va_arg(param, long int);
    else if (format.lengh == LL)
        nbr = va_arg(param, long long int);
    else
	    nbr = (long long int)va_arg(param, int);
	num = ft_uitoa_base(nbr, 8, LOWER);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num);
	return (len);
}

int	print_hex(va_list param, t_format format, int fd, int lower)
{
	long long unsigned int	nbr;
	char					*num;
	int						len;

	if (format.lengh == LOWER_L)
        nbr = (long long unsigned int)va_arg(param, long unsigned int);
    else if (format.lengh == LL)
        nbr = va_arg(param, long long unsigned int);
    else
		nbr = (long long unsigned int)va_arg(param, unsigned int);
	num = ft_uitoa_base(nbr, 16, lower);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num);
	return (len);
}

int print_float(va_list param, t_format format, int fd)
{
	long double		nbr;
	long long int	nbr1;
	long double		nbr2;
	char			*num;
	int				len;

	if (format.lengh == UPPER_L)
		nbr = va_arg(param, long double);
	else
		nbr = (long double)va_arg(param, double);
	nbr1 = (long long int)nbr;
	num = ft_llitoa(nbr1);
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