# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 15:12:33 by kebris-c          #+#    #+#              #
#    Updated: 2025/05/20 12:29:39 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= ft_printf.c conversions.c conversions2.c utils.c
LIB			= printf.h
OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.d test

re: fclean all

.PHONY: all clean fclean re
