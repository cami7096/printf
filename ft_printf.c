/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:33:49 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/09 23:06:23 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_fd(char *str, int *i)
{
	int		fd;
	int		j;

	j = 0;
	fd = 1;
	while (str[j] != '\0')
	{
		if (str[j] == '%' && str[j + 1] == 'j')
		{
			j += 2;
			fd = ft_atoi(&str[j]);
			j += get_len_num_base(fd, 10);
			*i += j;
			break ;
		}
		j++;
	}
	return (fd);
}

int		print(char *str, int *i, va_list param, int fd)
{
	int num_of_written_char;
	int len;

	len = 0;
	num_of_written_char = 0;
	if (str[*i] == '%')
	{
		len = print_format(str, i, param, fd);
		if (len == 0)
			*i += 1;
		else
			num_of_written_char += len;
	}
	else
	{
		ft_putchar_fd(str[*i], fd);
		num_of_written_char++;
		*i += 1;
	}
	return (num_of_written_char);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		num_of_written_char;
	va_list param;
	int		fd;

	num_of_written_char = 0;
	va_start(param, str);
	i = 0;
	fd = get_fd((char *)str, &i);
	while (str[i] != '\0')
	{
		num_of_written_char += print((char *)str, &i, param, fd);
	}
	va_end(param);
	return (num_of_written_char);
}
