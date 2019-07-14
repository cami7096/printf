/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:37:23 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/13 22:48:06 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'c' ||
			c == 'p' || c == 'o' || c == 'u' || c == 'x' ||
				c == 'X' || c == 'f')
		return (1);
	return (0);
}

int			get_len_num_base(long long unsigned int num, int base)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char		*ft_uitoa_base(long long unsigned int value, int base, int lower)
{
	int		len;
	char	*num;
	char	*base_l;
	char	*base_u;

	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	len = get_len_num_base(value, base);
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	num[len] = '\0';
	while (value)
	{
		num[--len] = (lower) ? base_l[value % base]
		: base_u[value % base];
		value /= base;
	}
	return (num);
}

int			get_float(long double nbr, int precision)
{
	int		i;

	i = 0;

	while (i < precision)
	{
		nbr *= 10;
		i++;
	}
	return (nbr);
}

char		*ft_llitoa(long long int n)
{
	char	*str;
	int		str_len;
	int		sign;

	sign = 0;
	str_len = (n < 0) ? get_len_num_base(n * -1, 10) :
				get_len_num_base(n, 10);
	if (n < 0)
	{
		sign = 1;
		str_len++;
		n *= -1;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n % 10 + '0';
	while (n /= 10)
		str[--str_len] = n % 10 + '0';
	if (sign)
		*(str + 0) = '-';
	return (str);
}
