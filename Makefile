# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 15:01:33 by fbafica           #+#    #+#              #
#    Updated: 2022/03/11 17:26:57 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
SOURCES = ft_printf.c ft_dprintf.c handle_c.c handle_hex.c handle_pct.c handle_s.c \
			handle_ptr.c handle_nbr.c handle_uint.c
INCLUDES_PATH = ./includes/
OBJ_DIR = ./objects/
OBJ = $(SOURCES:%.c=$(OBJ_DIR)%.o)
VPATH = ./source/

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ) 

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) -c $< -I$(INCLUDES_PATH) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
