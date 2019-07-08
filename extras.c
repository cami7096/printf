/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:37:23 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/07 15:50:29 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_len_num_base(int num, int base)
{
	int		i;

	i = 0;
	if (num < 0 && base == 10)
		i++;
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(long value, int base, int lower)
{
	int		len;
	long	nbr;
	char	*num;
	char	*base_l;

	base_l = "0123456789abcef";
	if (value == 0)
		return ("0");
	nbr = (value < 0) ? (value * -1) : value;
	len = get_len_num_base(nbr, base);
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	num[len] = '\0';
	while (nbr)
	{
		num[--len] = (lower) ? base_l[nbr % base]
		: base_l[nbr % base] - 32;
		nbr /= base;
	}
	if (value < 0 && base == 10)
		num[0] = '-';
	return (num);
}
