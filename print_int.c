/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:09:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 22:57:40 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list param, t_format format, int fd)
{
	long long int	nbr;
	char			*num;
	int				len;

	if (format.lengh == LOWER_L)
		nbr = (long long int)va_arg(param, long int);
	else if (format.lengh == LL)
		nbr = va_arg(param, long long int);
	else
		nbr = (long long int)va_arg(param, int);
	if (format.precision == 0 && nbr == 0)
		return (0);
	num = ft_llitoa(nbr);
	len = ft_strlen(num);
	len += print_width(format.width, len, fd);
	len += print_precision(format.precision, len, fd);
	ft_putstr_fd(num, fd);
	return (len);
}

int	print_unsigned(va_list param, t_format format, int fd)
{
	long long unsigned int	nbr;
	char					*num;
	int						len;

	len = 0;
	if (format.lengh == LOWER_L)
		nbr = (long long int)va_arg(param, long int);
	else if (format.lengh == LL)
		nbr = va_arg(param, long long int);
	else
		nbr = (long long unsigned int)va_arg(param, unsigned int);
	num = ft_uitoa_base(nbr, 10, LOWER);
	len = ft_strlen(num);
	len += print_width(format.width, len, fd);
	len += print_precision(format.precision, len, fd);
	ft_putstr_fd(num, fd);
	return (len);
}