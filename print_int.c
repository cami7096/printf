/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:09:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/08 20:09:05 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list param, t_format format, int fd)
{
	long long int   nbr;
	char            *num;
	int             len;

    if (format.lengh == LOWER_L)
        nbr = (long long int)va_arg(param, long int);
    else if (format.lengh == LL)
        nbr = va_arg(param, long long int);
    else
	    nbr = (long long int)va_arg(param, int);
	num = ft_llitoa(nbr);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num);
	return (len);
}

int print_unsigned(va_list param, t_format format, int fd)
{
	long long unsigned int	nbr;
	char			        *num;
	int				        len;

    if (format.lengh == LOWER_L)
        nbr = (long long int)va_arg(param, long int);
    else if (format.lengh == LL)
        nbr = va_arg(param, long long int);
    else
	    nbr = (long long unsigned int)va_arg(param, unsigned int);
	num = ft_uitoa_base(nbr, 10, LOWER);
	ft_putstr_fd(num, fd);
	len = ft_strlen(num);
	return (len);
}