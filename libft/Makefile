# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:39:57 by cbernabo          #+#    #+#              #
#    Updated: 2019/04/29 14:50:56 by cbernabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstiter.c ft_putendl_fd.c ft_strdup.c ft_strnstr.c \
	  ft_lstmap.c ft_putnbr.c ft_strequ.c ft_strrchr.c \
	  ft_atoi.c	ft_lstnew.c	ft_putnbr_fd.c ft_striter.c ft_strsplit.c \
	  ft_bzero.c ft_memalloc.c ft_putstr.c ft_striteri.c ft_strstr.c \
	  ft_isalnum.c ft_memccpy.c ft_putstr_fd.c ft_strjoin.c ft_strsub.c \
	  ft_isalpha.c ft_memchr.c ft_separator.c ft_strlcat.c ft_strtrim.c \
	  ft_isascii.c ft_memcmp.c ft_size.c ft_strlen.c ft_tolower.c \
	  ft_isaspace.c	ft_memcpy.c	ft_spliter.c ft_strmap.c ft_toupper.c \
	  ft_isdigit.c ft_memdel.c ft_strcat.c ft_strmapi.c ft_words.c \
	  ft_isprint.c ft_memmove.c	ft_strchr.c	ft_strncat.c \
	  ft_itoa.c ft_memset.c ft_strclr.c ft_strncmp.c \
	  ft_lstadd.c ft_putchar.c ft_strcmp.c ft_strncpy.c \
	  ft_lstdel.c ft_putchar_fd.c ft_strcpy.c ft_strnequ.c \
	  ft_lstdelone.c ft_putendl.c ft_strdel.c ft_strnew.c ft_spliter.c 

OBJECTS = ft_lstiter.o ft_putendl_fd.o ft_strdup.o ft_strnstr.o \
	  ft_lstmap.o ft_putnbr.o ft_strequ.o ft_strrchr.o \
	  ft_atoi.o	ft_lstnew.o	ft_putnbr_fd.o ft_striter.o ft_strsplit.o \
	  ft_bzero.o ft_memalloc.o ft_putstr.o ft_striteri.o ft_strstr.o \
	  ft_isalnum.o ft_memccpy.o ft_putstr_fd.o ft_strjoin.o ft_strsub.o \
	  ft_isalpha.o ft_memchr.o ft_separator.o ft_strlcat.o ft_strtrim.o \
	  ft_isascii.o ft_memcmp.o ft_size.o ft_strlen.o ft_tolower.o \
	  ft_isaspace.o ft_memcpy.o ft_spliter.o ft_strmap.o ft_toupper.o \
	  ft_isdigit.o ft_memdel.o ft_strcat.o ft_strmapi.o ft_words.o \
	  ft_isprint.o ft_memmove.o ft_strchr.o ft_strncat.o \
	  ft_itoa.o ft_memset.o ft_strclr.o ft_strncmp.o \
	  ft_lstadd.o ft_putchar.o ft_strcmp.o ft_strncpy.o \
	  ft_lstdel.o ft_putchar_fd.o ft_strcpy.o ft_strnequ.o \
	  ft_lstdelone.o ft_putendl.o ft_strdel.o ft_strnew.o

HEADER = includes

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

