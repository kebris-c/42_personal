NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror.

SRCS	= ft_printf.c conversions.c utils.c
OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME) main.c
	$(CC) $(CFLAGS) -I main.c $(NAME) -o test
	./test
	@rm -rf test

.PHONY: all clean fclean re test
