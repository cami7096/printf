# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:39:57 by cbernabo          #+#    #+#              #
#    Updated: 2019/07/15 20:13:12 by cbernabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	print_format.c \
		set_format.c \
		extras.c \
		ft_printf.c \
		print_int.c \
		print_base.c \
		extras2.c \
		print_float.c \
		print_str.c \
		print_flags.c \
		extras3.c \
		libft/*.c

OBJECTS = *.o \

HEADER = libft/libft.h \
			ft_printf.h

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -g $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o ft_printf.h.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2019/07/11 16:14:16 by cbernabo          #+#    #+#              #
# #    Updated: 2019/07/14 19:08:54 by cbernabo         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# CC          =   gcc
# CFLAGS      =   -Wall -Wextra -Werror -g

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# LIB =   libftprintf.a

# SRC_LIB = 	print_format.c \
# 				set_format.c \
# 				extras.c \
# 				ft_printf.c \
# 				print_int.c \
# 				print_base.c \
# 				extras2.c \
# 				print_float.c \
# 				print_str.c \
# 				print_flags.c \
# 				extras3.c \
# 				libft/*.c

# OBJ_LIB     =   *.o \

# HEADER      =   libft/libft.h \
#				  ft_printf.h

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

# NAME        =   printf

# LIBRARY     =   libft/libft.a

# SOURCES     =   main.c \
# 				print_format.c \
# 				set_format.c \
# 				extras.c \
# 				ft_printf.c \
# 				print_int.c \
# 				print_base.c \
# 				extras2.c \
# 				print_float.c \
# 				print_str.c \
# 				print_flags.c \
# 				extras3.c

# OBJECTS     =   $(SOURCES:.c=.o)

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

# all: $(NAME)

# $(NAME): $(LIBRARY) $(OBJECTS)
# 	@$(CC) $(CFLAGS) $^ -o $@ -I ft_printf.h -fsanitize=address
# 	@echo && echo $(GREEN) "[√]     [Program Successfully Compiled!]" && echo

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo $(WHITE) "Compiling => " $<

# $(LIBRARY):
# 	@make -C libft/

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# DEL  =  /bin/rm -rf

# clean:
# 	@$(DEL) $(shell find . -name '*.[oa]')

# fclean: clean
# 	@$(DEL) $(NAME) ft_printf.h.gch

# re: fclean all

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

# nc:
# 	@echo && echo $(GREEN) "Checking Norme -- Source Files:" && echo $(WHITE);
# 	@norminette $(shell find . -name '*.c')

# nh:
# 	@echo && echo $(GREEN) "Checking Norme -- Header Files:" && echo $(WHITE);
# 	@norminette $(shell find . -name '*.h')

# na: nh nc

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# GREEN =  "\033[1;32m"
# WHITE =  "\033[1;37m"

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# .PHONY: all clean fclean re nc nh na

# # — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

# all_lib : $(LIB)

# $(LIB):
# 	gcc -Wall -Wextra -Werror -c $(SRC_LIB) -I $(HEADER)
# 		ar rc $(LIB) $(OBJ_LIB)
# 		ranlib $(LIB)

# clean_lib:
# 	/bin/rm -f *.o

# fclean_lib: clean_lib
# 	/bin/rm -f $(LIB) ft_printf.h.gch

# re_lib: fclean_lib all_lib
