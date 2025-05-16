# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 15:12:33 by kebris-c          #+#    #+#              #
#    Updated: 2025/05/12 18:52:58 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
EXTRAFLAGS	= -MMD -std=c17 -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-align -Wunreachable-code -Winit-self -Wswitch-enum -Wfloat-equal -Wformat=2 -Wmissing-prototypes -Wmissing-declarations -Wdouble-promotion -Wundef -Wbad-function-cast -Winline -Wvla -Wno-missing-field-initializers -O3 -fstrict-aliasing -fstack-protector-strong -D_FORTIFY_SOURCE=2 -g3 -fsanitize=address -Wno-unused-result
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

compile: fclean main.c
	$(CC) $(CFLAGS) -I$(LIB) $(SRCS) main.c -o test
	@./test

test_val: fclean main.c
	$(CC) $(CFLAGS) -I$(LIB) *c -o test
	valgrind ./test

test_sanit: fclean main.c
	$(CC) $(CFLAGS) -g3 -fsanitize=address -I$(LIB) *.c -o test
	@./test

normal: fclean
	$(CC) $(CFLAGS) -c $(SRCS) -I$(LIB)

strict: fclean
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -c $(SRCS) -I$(LIB)

.PHONY: all clean fclean re compile test_val test_sanit normal strict
