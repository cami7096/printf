/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:21:22 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/12 19:52:22 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_octal(va_list param, t_format format, int fd)
{
	long long int		nbr;
	char				*num;
	int					len;

	len = 0;
	if (format.lengh == LOWER_L)
		nbr = (long long int)va_arg(param, long int);
	else if (format.lengh == LL)
		nbr = va_arg(param, long long int);
	else
		nbr = (long long int)va_arg(param, int);
	if (format.flags.hash && nbr != 0)
		len++;
	num = ft_uitoa_base(nbr, 8, LOWER);
	len = ft_strlen(num);
	len += print_width(format.width, len, fd);
	len += print_flags(format.flags, format.specifier, fd);
	len += print_precision(format.precision, len, fd);
	ft_putstr_fd(num, fd);
	return (len);
}

int	print_hex(va_list param, t_format format, int fd, int lower)
{
	long long unsigned int	nbr;
	char					*num;
	int						len;

	len = 0;
	if (format.lengh == LOWER_L)
		nbr = (long long unsigned int)va_arg(param, long unsigned int);
	else if (format.lengh == LL)
		nbr = va_arg(param, long long unsigned int);
	else
		nbr = (long long unsigned int)va_arg(param, unsigned int);
	if (format.flags.hash && nbr != 0)
		len += 2;
	num = ft_uitoa_base(nbr, 16, lower);
	len += ft_strlen(num);
	len += print_width(format.width, len, fd);
	len += print_flags(format.flags, format.specifier, fd);
	len += print_precision(format.precision, len, fd);
	ft_putstr_fd(num, fd);
	return (len);
}
