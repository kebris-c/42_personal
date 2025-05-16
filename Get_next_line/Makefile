# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 10:45:00 by kebris-c          #+#    #+#              #
#    Updated: 2025/05/16 10:45:11 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiladores y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos
MANDATORY_SRC = get_next_line.c get_next_line_utils.c main.c
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Nombres de los ejecutables
MANDATORY_NAME = test_gnl
BONUS_NAME = test_gnl_bonus

# Buffer size por defecto
BUFFER_SIZE = 42

# Targets
all: $(MANDATORY_NAME)

bonus: $(BONUS_NAME)

# Compilación parte obligatoria
$(MANDATORY_NAME): $(MANDATORY_SRC)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(MANDATORY_SRC) -o $@

# Compilación parte bonus
$(BONUS_NAME): $(BONUS_SRC)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D BONUS $(BONUS_SRC) -o $@

# Tests con diferentes tamaños de buffer
test_sizes: clean
	@echo "\n== Testing with BUFFER_SIZE=1 =="
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(MANDATORY_SRC) -o $(MANDATORY_NAME)_1
	./$(MANDATORY_NAME)_1

	@echo "\n== Testing with BUFFER_SIZE=9999 =="
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(MANDATORY_SRC) -o $(MANDATORY_NAME)_9999
	./$(MANDATORY_NAME)_9999

	@echo "\n== Testing bonus with BUFFER_SIZE=42 =="
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -D BONUS $(BONUS_SRC) -o $(BONUS_NAME)
	./$(BONUS_NAME)

	@echo "\n== Testing with BUFFER_SIZE=42 (default) =="
	$(CC) $(CFLAGS) $(MANDATORY_SRC) -o $(MANDATORY_NAME)_42
	./$(MANDATORY_NAME)_42

# Clean
clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)
	rm -f test_*.txt

fclean: clean
	rm -f $(MANDATORY_NAME) $(BONUS_NAME) $(MANDATORY_NAME)_* $(BONUS_NAME)_*

re: fclean all

.PHONY: all bonus test_sizes clean fclean re
