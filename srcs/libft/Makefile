# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 09:05:15 by anradix           #+#    #+#              #
#    Updated: 2019/03/22 08:58:32 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_add_list.c\
		ft_count_words.c\
		ft_create_list.c\
		ft_isspace.c\
		ft_len_list.c\
		ft_putlst.c\
		ft_strrev.c\
		ft_swap.c\
		ft_word_len.c\
		ft_printtab.c\
		ft_printtabdl.c\
		get_next_line.c\
		ft_init_tab.c\
		ft_tablen.c\
		ft_triple_tablen.c\
		ft_tabdup.c\
		ft_init_triple_tab.c\
		ft_sqrt.c\
		ft_tabdel.c\
		ft_triple_tabdel.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $?
		@ranlib $(NAME)
		@echo "libftprintf.a has been successfully created"

%.o: %.c
		@gcc $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJ)
		@echo "libftprintf clean OK"

fclean: clean
		@rm -f $(NAME)
		@echo "libftprintf fclean OK"


re: fclean all
		@echo "libftprintf re OK"
