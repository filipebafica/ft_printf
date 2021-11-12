# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 15:01:33 by fbafica           #+#    #+#              #
#    Updated: 2021/11/12 14:14:20 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

C_SOURCES = ft_printf.c handle_c.c handle_hex.c handle_pct.c handle_s.c \
			handle_ptr.c handle_nbr.c handle_uint.c

C_PATH = ./source/

INCLUDES_PATH = ./includes/

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(C_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^ 

$(OBJ): $(addprefix $(C_PATH), $(C_SOURCES))
	@$(CC) -c $^ $(FLAGS) -I$(INCLUDES_PATH)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
