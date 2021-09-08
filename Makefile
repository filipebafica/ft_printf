# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 15:01:33 by fbafica           #+#    #+#              #
#    Updated: 2021/07/22 21:45:34 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

C_SOURCES = ft_printf.c handle_c.c handle_hex.c handle_pct.c handle_s.c \
			handle_ptr.c handle_nbr.c handle_uint.c

C_PATH = ./source/

INCLUDES_PATH = ./includes/

OBJ = $(C_SOURCES:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@ar rcs $@ $^ 

$(OBJ): $(addprefix $(C_PATH), $(C_SOURCES))
	@gcc -c -I$(INCLUDES_PATH) $^ -Wall -Wextra -Werror -D BUFFER_SIZE=42

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
