# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchhabra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 11:11:15 by nchhabra          #+#    #+#              #
#    Updated: 2022/08/05 16:44:48 by nchhabra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_convert_uxxp.c \
		ft_nbr.c \
		ft_printf.c \
		ft_putchar_len.c \
		ft_str.c \
		printf.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:  
	rm -f $(NAME) $(OBJS)

fclean: 
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re

