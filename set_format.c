/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:24:52 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/15 20:09:05 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	set_format(char *str, int *i, va_list param)
{
	t_format	format;

	format = init_format();
	*i += 1;
	while (!specifier(str[*i]))
	{
		format.flags = set_flags(str, i);
		format.width = set_width(str, i, param);
		format.precision = set_precision(str, i, param);
		format.lengh = set_lengh(str, i);
		if (format.width == EMPTY && format.precision == EMPTY &&
		format.lengh == EMPTY && format.flags.minus == FALSE &&
		format.flags.plus == FALSE && format.flags.hash == FALSE &&
		format.flags.space == FALSE && format.flags.zero == FALSE)
		{
			format.specifier = EMPTY;
			return (format);
		}
	}
	format.specifier = set_specifier(str, i);
	return (format);
}

int			set_specifier(char *str, int *i)
{
	int		specifier;

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
	else if (str[*i] == '%')
		specifier = PERCENTAGE;
	*i += 1;
	return (specifier);
}

int			set_lengh(char *str, int *i)
{
	int		lengh;
	int		j;

	j = 0;
	lengh = EMPTY;
	if (str[*i] != 'h' && str[*i] != 'l' && str[*i] != 'L')
		return (lengh);
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

int			set_precision(char *str, int *i, va_list param)
{
	int		precision;
	int		lengh;

	precision = EMPTY;
	if (str[*i] != '.')
		return (precision);
	(*i)++;
	if (str[*i] == '*')
	{
		precision = va_arg(param, int);
		(*i)++;
	}
	else if (ft_isdigit(str[*i]))
	{
		precision = ft_atoi(&str[*i]);
		lengh = get_len_num_base(precision, 10);
		if (lengh == 0)
			(*i) += 1;
		(*i) += lengh;
	}
	return (precision);
}

int			set_width(char *str, int *i, va_list param)
{
	int		width;
	int		lengh;

	width = EMPTY;
	if (str[*i] == '*')
	{
		width = va_arg(param, int);
		*i += 1;
	}
	else if (ft_isdigit(str[*i]))
	{
		width = ft_atoi(&str[*i]);
		lengh = get_len_num_base(width, 10);
		*i += lengh;
	}
	if (str[*i] != '*' || !ft_isdigit(str[*i]))
		return (width);
	return (width);
}
