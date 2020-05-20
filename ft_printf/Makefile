# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <rofeldsp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#    Updated: 2020/02/27 18:06:44 by atammie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft_printf

SRC_DIR	:= ./srcs
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft


SRC =   main.c \
		initialization.c \
		f1.c \
		print_values.c \
		f2.c \
		flags.c \
		width.c \
		types_csp.c \
		types_dioux.c \
		mods.c \
		precision.c


OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

# libraries

# include $(LIB_DIR)/libft.h

.PHONY: all clean fclean re $(NAME)

all: $(NAME)

$(NAME):
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lft -I$(INC_DIR) -I$(LIB_DIR) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc  -I$(INC_DIR) -I$(LIB_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(LIB_DIR) re --no-print-directory
	@$(MAKE) re --no-print-directory
