# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:19:14 by epham             #+#    #+#              #
#    Updated: 2019/03/25 14:47:40 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

NAME		=	libftprintf.a

FLAGS		= 	-Wall -Wextra -Werror

SRCS 		= 	ft_printf.c 					\
				srcs/parser.c 					\
				srcs/handle_int.c

SRCS_LIBFT	=	libft/ft_atoi.c 				\
				libft/ft_bzero.c 				\
				libft/ft_isalnum.c 				\
				libft/ft_isalpha.c 				\
				libft/ft_isascii.c 				\
				libft/ft_isdigit.c 				\
				libft/ft_isprint.c 				\
				libft/ft_itoa.c 				\
				libft/ft_itoa_base.c 			\
				libft/ft_lstadd.c 				\
				libft/ft_lstdel.c 				\
				libft/ft_lstdelone.c 			\
				libft/ft_lstiter.c 				\
				libft/ft_lstmap.c 				\
				libft/ft_lstnew.c 				\
				libft/ft_memalloc.c 			\
				libft/ft_memccpy.c 				\
				libft/ft_memchr.c 				\
				libft/ft_memcmp.c 				\
				libft/ft_memcpy.c 				\
				libft/ft_memdel.c 				\
				libft/ft_memmove.c 				\
				libft/ft_memset.c 				\
				libft/ft_putchar_fd.c 			\
				libft/ft_putchar.c 				\
				libft/ft_putendl_fd.c 			\
				libft/ft_putnbr_fd.c 			\
				libft/ft_putnbr.c 				\
				libft/ft_putstr_fd.c 			\
				libft/ft_putstr.c 				\
				libft/ft_putendl.c 				\
				libft/ft_strcat.c 				\
				libft/ft_strchr.c 				\
				libft/ft_strclr.c 				\
				libft/ft_strcmp.c 				\
				libft/ft_strcpy.c 				\
				libft/ft_strdel.c 				\
				libft/ft_strdup.c 				\
				libft/ft_strequ.c 				\
				libft/ft_striter.c 				\
				libft/ft_striteri.c 			\
				libft/ft_strjoin.c 				\
				libft/ft_strlcat.c 				\
				libft/ft_strlen.c 				\
				libft/ft_strmap.c 				\
				libft/ft_strmapi.c 				\
				libft/ft_strncat.c 				\
				libft/ft_strncmp.c 				\
				libft/ft_strncpy.c 				\
				libft/ft_strnequ.c 				\
				libft/ft_strnew.c 				\
				libft/ft_strnstr.c 				\
				libft/ft_strrchr.c 				\
				libft/ft_strsplit.c 			\
				libft/ft_strstr.c 				\
				libft/ft_strsub.c 				\
				libft/ft_strtrim.c 				\
				libft/ft_tolower.c 				\
				libft/ft_toupper.c 				\
				libft/ft_add_list.c 			\
				libft/ft_count_words.c 			\
				libft/ft_create_list.c 			\
				libft/ft_isspace.c 				\
				libft/ft_len_list.c 			\
				libft/ft_putlst.c 				\
				libft/ft_strrev.c 				\
				libft/ft_swap.c 				\
				libft/ft_word_len.c 			\
				libft/ft_printtab.c 			\
				libft/ft_printtabdl.c 			\
				libft/get_next_line.c 			\
				libft/ft_init_tab.c 			\
				libft/ft_tablen.c 				\
				libft/ft_triple_tablen.c 		\
				libft/ft_tabdup.c 				\
				libft/ft_init_triple_tab.c 		\
				libft/ft_sqrt.c 				\
				libft/ft_tabdel.c 				\
				libft/ft_triple_tabdel.c

OBJS 		= 	$(SRCS:.c=.o)

OBJS_LIBFT 	=	$(SRCS_LIBFT:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I libft/ -o $@ -c $<

$(NAME): $(OBJS)
	@make -C libft/
	@ar rc $(NAME) $(OBJS) $(OBJS_LIBFT) $?
	@ranlib $(NAME)
	@echo "libftprintf.a has been successfully created"

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "libftprintf clean OK"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "libftprintf fclean OK"

re: fclean all
	@echo "libftprintf re OK"
