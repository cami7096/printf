/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/12 18:44:28 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int end, int fd)
{
	int i;

	i = -1;
	while (++i != end)
		ft_putchar_fd(str[i], fd);
}

int		print_str(va_list param, int fd, t_format format)
{
	char	*str;
	int		char_written;
	int		len;

	char_written = 0;
	str = va_arg(param, char*);
	len = ft_strlen(str);
	len += print_width(format.width, len, fd);
	if (format.precision != EMPTY && format.precision < len)
		ft_putnstr(str, format.precision, fd);
	else
	{
		ft_putstr_fd(str, fd);
		char_written += len;
	}
	return (char_written);
}
