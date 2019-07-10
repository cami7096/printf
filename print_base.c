/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:21:22 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 21:48:01 by cbernabo         ###   ########.fr       */
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

