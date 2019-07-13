/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:40:17 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/13 14:20:45 by cbernabo         ###   ########.fr       */
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

int			print_width(int width, int num_lengh, int fd)
{
	int i;
	int char_written;

	i = width;
	char_written = 0;
	if (num_lengh < width)
	{
		while (--i >= num_lengh)
			ft_putchar_fd(' ', fd);
		char_written = width - num_lengh;
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

int			print_minus(t_format format, char *num, int len, int fd)
{
	len = 0;
	len += (format.specifier == CHAR) ? 1 : ft_strlen(num);
	len += print_flags(format.flags, format.specifier, fd);
	ft_putstr_fd(num, fd);
	len += print_precision(format.precision, len, fd);
	len += print_width(format.width, len, fd);
	return (len);
}
