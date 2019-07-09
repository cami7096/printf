# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 20:38:15 by cbernabo          #+#    #+#              #
#    Updated: 2019/07/03 20:38:55 by cbernabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -g

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   printf

LIBRARY     =   libft/libft.a

SOURCES     =   main.c      \
                print_format.c \
                set_format.c    \
                extras.c     \
				ft_printf.c  \
				print_int.c  \
				print_octal.c

OBJECTS     =   $(SOURCES:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@ -I ft_printf.h -fsanitize=address
	@echo && echo $(GREEN) "[√]     [Program Successfully Compiled!]" && echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

$(LIBRARY):
	@make -C libft/

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL  =  /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.[oa]')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

nc:
	@echo && echo $(GREEN) "Checking Norme -- Source Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.c')

nh:
	@echo && echo $(GREEN) "Checking Norme -- Header Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.h')

na: nh nc

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN =  "\033[1;32m"
WHITE =  "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na