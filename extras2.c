/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:40:17 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 20:44:53 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TRUE 1
#define FALSE 0

t_format	init_format(void)
{
	t_format	format;

	format.flags.hash = FALSE;
	format.flags.minus = FALSE;
	format.flags.plus = FALSE;
	format.flags.space = FALSE;
	format.flags.zero = FALSE;
	format.lengh = EMPTY;
	format.precision = EMPTY;
	format.specifier = EMPTY;
	format.width = EMPTY;
	format.positive = TRUE;
	return (format);
}

int			print_precision(int precision, int num_lengh, int fd)
{
	int i;
	int char_written;

	i = precision;
	char_written = 0;
	if (num_lengh < precision)
	{
		while (--i >= num_lengh)
			ft_putchar_fd('0', fd);
		char_written = precision - num_lengh;
	}
	return (char_written);
}

int			print_width(t_format format, int num_lengh, int fd)
{
	int i;
	int char_written;

	i = format.width;
	char_written = 0;
	if (num_lengh < format.width)
	{
		while (--i >= num_lengh)
		{
			if (format.flags.zero && !format.flags.minus)
				ft_putchar_fd('0', fd);
			else
				ft_putchar_fd(' ', fd);
		}
		char_written = format.width - num_lengh;
	}
	return (char_written);
}

t_flags		set_flags(char *str, int *i)
{
	t_flags flags;

	flags.hash = FALSE;
	flags.minus = FALSE;
	flags.plus = FALSE;
	flags.space = FALSE;
	flags.zero = FALSE;
	while (str[*i] == '#' || str[*i] == '-' || str[*i] == ' '
	|| str[*i] == '0' || str[*i] == '+')
	{
		if (str[*i] == '#')
			flags.hash = TRUE;
		else if (str[*i] == '-')
			flags.minus = TRUE;
		else if (str[*i] == '+')
			flags.plus = TRUE;
		else if (str[*i] == ' ')
			flags.space = TRUE;
		else if (str[*i] == '0')
			flags.zero = TRUE;
		*i += 1;
	}
	return (flags);
}

int			print_all(t_format format, char *num, int len, int fd)
{
	if (format.flags.hash && !format.flags.zero && (format.specifier == OCTAL ||
		format.specifier == HEXA_LOWER || format.specifier == HEXA_UPPER))
		len = (format.specifier == OCTAL) ? 1 : 2;
	len += special_cases(format, 0, fd);
	len += ft_strlen(num);
	len += print_width(format, len, fd);
	len += print_flags(format, fd);
	len += print_precision(format.precision, len, fd);
	ft_putstr_fd(num, fd);
	return (len);
}
