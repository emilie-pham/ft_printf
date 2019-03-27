# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:19:14 by epham             #+#    #+#              #
#    Updated: 2019/03/26 16:10:34 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

NAME		=	libftprintf.a

FLAGS		=	-Wall -Wextra -Werror

SRC			=	ft_printf.c 		\
				parser.c     		\
				handle_int.c 		\
				handle_oct.c 		\
				ft_uitoa_base.c

OBJ			=	$(SRC:.c=.o)

LIBFT_H		=	-Ilibft/

LIB_O		=	$(addprefix ./libft/, *.o)

all: $(NAME)

%.o : %.c
	@gcc $(CFLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	@make -C libft/
	@ar rc libftprintf.a $(OBJ) $(LIB_O)
	@ranlib $(NAME)
	@echo "libftprintf.a has been successfully created"

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)
	@echo "libftprintf clean OK"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "libftprintf fclean OK"

re: fclean all
	@echo "libftprintf re OK"
