# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:19:14 by epham             #+#    #+#              #
#    Updated: 2019/04/08 11:10:58 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

CC			= 	gcc

NAME		= 	libftprintf.a

FLAGS		= 	-Wall -Wextra -Werror

LIBFT		= 	libft

DIR_S		= 	srcs

DIR_O		= 	obj

HEADER		= 	includes

SOURCES		=	ft_printf.c 		\
				parse_flags.c 		\
				parse_type.c 		\
				correct_cast_flags.c\
				handle_int.c 		\
				handle_unsigned.c	\
				handle_floats.c 	\
				handle_char.c 		\
				handle_strings.c 	\
				ft_uitoa_base.c 	\
				ft_ftoa.c 

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a successfully created"

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "libftprintf clean OK"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "libftprintf fclean OK"

re: fclean all