/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:11:35 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/07 15:49:42 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# define HH 1
# define H 2
# define LL 3
# define LOWER_L 4
# define UPPER_L 5
# define INT 1
# define CHAR 2
# define STR 3
# define POINTER 4
# define OCTAL 5
# define UNSIGNED_INT 6
# define HEXA_LOWER 7
# define HEXA_UPPER 8
# define FLOAT 9
# define PERCENTAGE 10
# define EMPTY -1

typedef struct	s_format
{
	int			specifier;
}				t_format;

int				ft_printf(const char *str, ...);
int				print_format(char *str, int *i, va_list param, int fd);
t_format		set_format(char *str, int *i);
int				print_int(va_list param, int fd);
int				get_len_num_base(int num, int base);
int				set_specifier(char *str, int *i);
int				get_fd(char *str, int *i);
int				print_char(va_list parameters, int fd);
int				print_str(va_list param, int fd);
int				print_hex(va_list param, int fd, int lower);
char			*ft_itoa_base(long value, int base, int lower);
int				print_octal(va_list param, int fd);
int				print_pointer(va_list param, int fd);

#endif
