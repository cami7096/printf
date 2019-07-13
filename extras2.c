/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:40:17 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/12 19:07:51 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		init_format(void)
{
	t_format	format;

	format.flags.hash = EMPTY;
	format.flags.minus = EMPTY;
	format.flags.plus = EMPTY;
	format.flags.space = EMPTY;
	format.flags.zero = EMPTY;
	format.lengh = EMPTY;
	format.precision = EMPTY;
	format.specifier = EMPTY;
	format.width = EMPTY;
	return (format);
}

int	print_precision(int precision, int num_lengh, int fd)
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

int	print_width(int width, int num_lengh, int fd)
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

t_flags	set_flags(char *str, int *i)
{
	t_flags flags;

	flags.hash = EMPTY;
	flags.minus = EMPTY;
	flags.plus = EMPTY;
	flags.space = EMPTY;
	flags.zero = EMPTY;
	while (str[*i] == '#' || str[*i] == '-' || str[*i] == ' '
	|| str[*i] == '0' || str[*i] == '+')
	{
		if (str[*i] == '#')
			flags.hash = 1;
		else if (str[*i] == '-')
			flags.minus = 1;
		else if (str[*i] == '+')
			flags.plus = 1;
		else if (str[*i] == ' ')
			flags.space = 1;
		else if (str[*i] == '0')
			flags.zero = 1;
		*i += 1;
	}
	return (flags);
}
