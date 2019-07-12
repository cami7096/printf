/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:40:17 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 19:48:41 by cbernabo         ###   ########.fr       */
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
