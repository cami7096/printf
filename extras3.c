/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:07:49 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 20:44:38 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*join_float(char *num, char *num_float)
{
	char *res;
	char *final;

	res = ft_strjoin(num, ".");
	final = ft_strjoin(res, num_float + 1);
	return (final);
}

int		special_cases(t_format format, int result, int fd)
{
	if (format.flags.plus && format.positive &&
		(format.specifier == INT || format.specifier == FLOAT))
	{
		if (format.flags.zero)
			ft_putchar_fd('+', fd);
		result++;
	}
	if (format.flags.zero && format.flags.hash &&
		(format.specifier == HEXA_LOWER || format.specifier == HEXA_UPPER
		|| format.specifier == OCTAL))
	{
		if (format.specifier == HEXA_LOWER)
			result += write(fd, "0x", 2);
		else if (format.specifier == HEXA_UPPER)
			result += write(fd, "0X", 2);
		else
			result += write(fd, "0", 1);
	}
	if (format.flags.space && !format.flags.plus &&
		(format.specifier == INT || format.specifier == FLOAT))
		result++;
	return (result);
}

int		ft_putnchar_fd(char *str, int fd, int precision)
{
	int i;

	i = -1;
	while (++i < precision)
		ft_putchar_fd(str[i], fd);
	return (precision);
}
