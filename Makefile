# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 21:33:48 by kebris-c          #+#    #+#              #
#    Updated: 2025/04/30 19:12:35 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------#
#   VARIABLES                                    #
#------------------------------------------------#

# 📚 Basic project variables
#
NAME = libft.a
PROJECT = $(notdir $(shell pwd))
MYLIB = $(HOME)/Desktop/mylibs
COMMON_CORE = $(HOME)/Desktop/common_core

# 🔧 Compiler and flags
#
CC = cc
CFLAGS = -Wall \
		 -Wextra \
		 -Werror

# 🛡️ Extra flags for the paranoid developer!
#
CEXTRAFLAGS = $(CFLAGS) \
			  -MMD \
			  -std=c17 \
			  -Wpedantic \
			  -Wconversion \
			  -Wsign-conversion \
			  -Wshadow \
			  -Wstrict-prototypes \
			  -Wpointer-arith \
			  -Wcast-align \
			  -Wunreachable-code \
			  -Winit-self \
			  -Wswitch-enum \
			  -Wfloat-equal \
			  -Wformat=2 \
			  -Wmissing-prototypes \
			  -Wmissing-declarations \
			  -Wdouble-promotion \
			  -Wundef \
			  -Wbad-function-cast \
			  -Winline -Wvla \
			  -Wno-unused-parameter \
			  -Wno-missing-field-initializers \
			  -O3 \
			  -fstrict-aliasing \
			  -fstack-protector-strong \
			  -D_FORTIFY_SOURCE=2 \
			  -g3 \
			  -fsanitize=address

# 🔨 Tools
#
AR = ar rcs
RM = rm -rf
NORM = norminette

# 📂 Files
#
SRC_PATH = ./src
INCLUDE_PATH = ./include
MYLIB_SRC = $(MYLIB)/src
MYLIB_INCLUDE = $(MYLIB)/include

# Determinate if we are on MYLIB
#
IS_MYLIB = $(shell if [ "$(shell pwd)" = "$(MYLIB)" ]; then echo "yes"; else echo "no"; fi)

# Select the correct src dir
#
ifeq ($(IS_MYLIB),yes)
    SRC = $(wildcard $(MYLIB_SRC)/*.c)
    INCLUDE_DIR = $(MYLIB_INCLUDE)
else
    SRC = $(wildcard *.c)
    INCLUDE_DIR = .
endif

BONUS_SRC = $(wildcard *_bonus.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
BONUS_OBJ = $(patsubst %.c,%.o,$(BONUS_SRC))
DEPS = $(SRC:.c=.d) $(BONUS_SRC:.c=.d)

#------------------------------------------------#
#   Defines                                      #
#------------------------------------------------#

define COMPILE_PROJECT
	@if $(NORM) $(SRC) 2>/dev/null; then \
		$(CC) $(2) $(SRC) -o $(PROJECT); \
	else \
		exit 1; \
	fi
endef

#------------------------------------------------#
#   BASIC RULES / LIBRARY COMMANDS               #
#------------------------------------------------#

all: help_hint fclean $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@if [ ! -d $(MYLIB_SRC) ]; then \
		mkdir -p $(MYLIB_SRC); \
	fi
	@cp $(NAME) $(MYLIB_SRC)/

bonus: $(OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@if [ ! -d $(MYLIB_SRC) ]; then \
		mkdir -p $(MYLIB_SRC); \
	fi
	@cp $(NAME) $(MYLIB_SRC)/

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ) $(DEPS)

fclean: clean
	@$(RM) $(NAME) $(PROJECT)

re: fclean all

#------------------------------------------------#
#   PROJECT COMPILATION                          #
#------------------------------------------------#

$(PROJECT):
	$(call COMPILE_PROJECT,$(CEXTRAFLAGS))

unlinked:
	@$(CC) $(CEXTRAFLAGS) -c $(BONUS_SRC)

normal:
	$(call COMPILE_PROJECT,$(CFLAGS))

force:
	@$(CC) $(SRC) -o $(PROJECT)

gnl: clean
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 \
		get_next_line.c \
		get_next_line_bonus.c \
		main.c \
		-I$(HOME)/.local/include \
		-L$(HOME)/.local/lib -lft \
		-o $(PROJECT)

exec:
	@if [ -x ./$(PROJECT) ]; then \
		./$(PROJECT); \
	else \
		exit 1; \
	fi

#------------------------------------------------#
#   NORMINETTE & DEBUGGING                       #
#------------------------------------------------#

norm:
	@if $(NORM) $(SRC) 2>/dev/null; then \
		exit 0; \
	else \
		exit 1; \
	fi

debug: CFLAGS += -g3
debug: re

leak-check: $(PROJECT)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(PROJECT) || true

diff-test: $(PROJECT)
	@./$(PROJECT) > output.txt
	@if [ -f reference.txt ]; then \
		diff -u reference.txt output.txt; \
	fi

#------------------------------------------------#
#   LIBRARY REPLICATION                          #
#------------------------------------------------#

global_lib: $(NAME)
	@mkdir -p $(HOME)/.local/lib
	@mkdir -p $(HOME)/.local/include
	@cp $(MYLIB_SRC)/$(NAME) $(HOME)/.local/lib/
	@if [ -d $(INCLUDE_DIR) ]; then \
		cp $(INCLUDE_DIR)/*.h $(HOME)/.local/include/; \
	else \
		cp *.h $(HOME)/.local/include/ 2>/dev/null || true; \
	fi

local_lib:
	@$(CC) $(CEXTRAFLAGS) -c *.c
	@$(AR) $(NAME) *.o
	@$(RM) *.o
	@if [ ! -d $(MYLIB_SRC) ]; then \
		mkdir -p $(MYLIB_SRC); \
	fi
	@cp $(NAME) $(MYLIB_SRC)

auto-replicant:
	@find $(COMMON_CORE) -type d -not -path "*/\.*" | while read dir; do \
		if [ ! -e $$dir/Makefile ]; then \
			cp $(lastword $(MAKEFILE_LIST)) $$dir/Makefile; \
		fi; \
	done

lib-replicant: $(NAME)
	@find $(COMMON_CORE) -type d -not -path "*/\.*" | while read dir; do \
		if [ ! -f "$$dir/$(NAME)" ]; then \
			if [ -d "$$dir/src" ] && [ -d "$$dir/include" ]; then \
				(cd "$$dir" && \
				find src -name "*.c" -exec $(CC) $(CFLAGS) -Iinclude -c {} \; && \
				$(AR) $(NAME) *.o && \
				rm -f *.o); \
			else \
				if [ ! -f "$(MYLIB_SRC)/$(NAME)" ]; then \
					make global_lib; \
				fi; \
				cp "$(MYLIB_SRC)/$(NAME)" "$$dir/"; \
			fi; \
		fi; \
	done

replicant-supremacy: auto-replicant lib-replicant

#------------------------------------------------#
#   GIT AUTOMATION                               #
#------------------------------------------------#

git-add:
	@git add .

git-commit:
	@read -p "Enter commit message (or press Enter for default): " msg; \
	if [ -z "$$msg" ]; then \
		git commit -m "Update $(PROJECT) $(shell date +%Y-%m-%d) - Made with ❤️  and coffee"; \
	else \
		git commit -m "$$msg"; \
	fi

git-push:
	@git push

git-all: git-add git-commit git-push

git-status:
	@git status

git-clean: fclean
	@git clean -fdX || true

#------------------------------------------------#
#   SPECIAL OPERATIONS                           #
#------------------------------------------------#

archive: fclean
	@tar -czvf $(PROJECT)-$(shell date +%Y%m%d).tar.gz *.[ch] Makefile

suicide: fclean
	@$(RM) $(lastword $(MAKEFILE_LIST))

# Include dependency files if they exist
#
-include $(DEPS)
-include $(MYLIB)/utils/help.mk

.PHONY: all bonus global_lib auto-replicant lib-replicant replicant-supremacy unlinked normal norm exec clean fclean re help \
	help_hint suicide git-clean leak-check debug diff-test archive git-add git-commit git-push git-all git-status

