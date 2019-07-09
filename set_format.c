/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:24:52 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/07 16:00:07 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		set_format(char *str, int *i)
{
	t_format	format;

	*i += 1;
	if (str[*i] == '%')
	{
		format.specifier = PERCENTAGE;
		*i += 1;
		format.lengh = EMPTY;
		return (format);
	}
	while (!specifier(str[*i]))
	{
		format.lengh = set_lengh(str, i);
	}
	format.specifier = set_specifier(str, i);
	return (format);
}

int				set_specifier(char *str, int *i)
{
	int			specifier;

	specifier = EMPTY;
	if (str[*i] == 'i' || str[*i] == 'd')
		specifier = INT;
	else if (str[*i] == 'c')
		specifier = CHAR;
	else if (str[*i] == 's')
		specifier = STR;
	else if (str[*i] == 'o')
		specifier = OCTAL;
	else if (str[*i] == 'p')
		specifier = POINTER;
	else if (str[*i] == 'x' || str[*i] == 'X')
		specifier = (str[*i] == 'x') ? HEXA_LOWER : HEXA_UPPER;
	else if (str[*i] == 'u')
		specifier = UNSIGNED_INT;
	else if (str[*i] == 'f')
		specifier = FLOAT;
	*i += 1;
	return (specifier);
}

int 			set_lengh(char *str, int *i)
{
	int 		lengh;
	int			j;

	j = 0;
	lengh = EMPTY;
	if (str[*i] == 'h' && str[*i + 1] == 'h')
		lengh = HH;
	else if (str[*i] == 'h' && str[*i + 1] != 'h')
		lengh = H;
	else if (str[*i] == 'l' && str[*i + 1] == 'l')
		lengh = LL;
	else if (str[*i] == 'l' && str[*i + 1] != 'l')
		lengh = LOWER_L;
	else if (str[*i] == 'L')
		lengh = UPPER_L;
	if (lengh != EMPTY)
		j = (lengh == HH || lengh == LL) ? 2 : 1;
	*i += j;
	return (lengh);
}
