# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 16:19:10 by mdovhopo          #+#    #+#              #
#    Updated: 2018/12/04 19:38:10 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC_C =ft_memset.c \
       ft_bzero.c \
	   ft_count_words.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_make_coffee.c \
	   ft_vec2.c \
	   ft_new_vec3.c \
       ft_add_vec2.c \
	   ft_add_vec3.c \
	   ft_new_intvec2.c \
	   ft_show_binary.c \
	   ft_atoi16.c \
	   get_next_line.c \

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

$(NAME): $(SRC_O)
	@ar rc $(NAME) $(SRC_O)
	@echo "\033[92m[$(NAME) Has been created.]\033[0m"

%.o: %.c
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
