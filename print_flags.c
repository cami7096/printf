/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:46:11 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/13 14:23:34 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hash(int specifier, int fd)
{
	int len;

	len = 0;
	if (specifier == HEXA_LOWER || specifier == POINTER)
	{
		write(fd, "0x", 2);
		len += 2;
	}
	else if (specifier == HEXA_UPPER)
	{
		write(fd, "0X", 2);
		len += 2;
	}
	else if (specifier == OCTAL)
	{
		write(fd, "0", 1);
		len += 1;
	}
	return (len);
}

int		print_flags(t_flags flags, int specifier, int fd)
{
	int len;

	len = 0;
	if (flags.hash)
		len += print_hash(specifier, fd);
	return (len);
}
