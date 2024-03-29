/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:47:02 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/15 20:02:36 by cbernabo         ###   ########.fr       */
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
	int		len;
	int		str_len;

	len = 0;
	str = va_arg(param, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	str_len = ft_strlen(str);
	// if (format.width != EMPTY && format.width < str_len)
	// 	return (ft_putnchar_fd(str, fd, format.width));
	if (format.flags.minus)
		return (print_minus(format, str, len, fd));
	len = (format.precision == EMPTY || format.precision > str_len)
		? str_len : format.precision;
	len += print_width(format, len, fd);
	if (format.precision != EMPTY && format.precision < str_len)
		ft_putnstr(str, format.precision, fd);
	else
		ft_putstr_fd(str, fd);
	return (len);
}
