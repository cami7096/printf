/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 22:18:24 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list param, int fd, t_format format)
{
	char	*str;
	int		char_written;
	int		i;
	int		len;

	i = -1;
	char_written = 0;
	str = va_arg(param, char*);
	len = ft_strlen(str);
    if (format.precision != EMPTY && format.precision < len)
	{
		while (++i < format.precision)
        	ft_putchar_fd(str[i], fd);
		char_written += i;
	}
	else
	{
		ft_putstr_fd(str, fd);
		char_written += len;
	}
	return (char_written);
}

