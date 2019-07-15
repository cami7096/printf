/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:11:35 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 20:44:48 by cbernabo         ###   ########.fr       */
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
# define SIGNED_CHAR 11

# define EMPTY -1
# define LOWER 1
# define UPPER 0

# define TRUE 1
# define FALSE 0

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			hash;
}				t_flags;

typedef struct	s_format
{
	t_flags		flags;
	int			lengh;
	int			specifier;
	int			precision;
	int			width;
	int			positive;
}				t_format;

int				ft_printf(const char *str, ...);
int				print_format(char *str, int *i, va_list param, int fd);
t_format		set_format(char *str, int *i, va_list param);
int				print_int(va_list param, t_format format, int fd);
int				get_len_num_base(long long unsigned int num, int base);
int				set_specifier(char *str, int *i);
int				get_fd(char *str, int *i);
int				print_char(va_list param, int fd, t_format format);
int				print_str(va_list param, int fd, t_format format);
int				print_hex(va_list param, t_format format, int fd, int lower);
int				print_octal(va_list param, t_format format, int fd);
int				print_pointer(va_list param, int fd, t_format format);
char			*ft_uitoa_base(long long unsigned int value,
										int base, int lower);
int				print_unsigned(va_list param, t_format format, int fd);
int				print_float(va_list param, t_format format, int fd);
int				get_float(long double nbr, int precision);
char			*ft_llitoa(long long int n);
int				set_lengh(char *str, int *i);
int				specifier(char c);
int				set_precision(char *str, int *i, va_list param);
t_format		init_format(void);
int				print_precision(int precision, int num_lengh, int fd);
char			*precision_float(int p, long long int i, long double d);
int				set_width(char *str, int *i, va_list param);
int				print_width(t_format format, int num_lengh, int fd);
int				write_float(t_format format, int fd, long double nbr);
t_flags			set_flags(char *str, int *i);
int				print_flags(t_format format, int fd);
int				print_minus(t_format format, char *num, int len, int fd);
int				p_minus_f(t_format format, char *str, int fd);
char			*join_float(char *num, char *num_float);
int				print_all(t_format format, char *num, int len, int fd);
int				print_all_float(t_format format, char *str, int len, int fd);
int				special_cases(t_format format, int result, int fd);

#endif
