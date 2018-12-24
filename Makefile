# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 12:58:19 by mdovhopo          #+#    #+#              #
#    Updated: 2018/12/09 12:58:20 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBFT = libft

INC = inc

SRC = src

MLX = /usr/local/lib

f = -Wall -Wextra -Werror

FLAGS = 

SRC_C = $(addprefix $(SRC)/, \
main.c \
clear_img.c \
render.c \
setters.c \
ft_color_rgb.c \
line.c \
motion_mouse.c \
deal_key.c \
scavenger.c)

FRAMEWORKS = -framework OpenGL -framework Appkit

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

libft/libft.a:
	@make -C $(LIBFT)

$(NAME): libft/libft.a $(SRC_O) inc/wolf3d.h
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(SRC_O) -L $(LIBFT) -lft \
	-L $(MLX) -lmlx $(FRAMEWORKS) -lpthread
	@echo "\033[92mmake[$(NAME) Has been created]\033[0m\nrun ./$@"

$(SRC)/%.o: $(SRC)/%.c 
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) -I $(INC) -I . -c $< -o $@

clean:	
	@/bin/rm -f $(SRC_O)

lclean:
	@make -C $(LIBFT) fclean
	@make fclean

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

magic:
	clear
	@echo "*making magic*"
	@echo " 	.∧＿∧"
	@echo " 	( ･ω･｡)つ━☆・*。"
	@echo "	⊂　 ノ 　　　・゜+."
	@echo "	しーＪ　　　°。+ *´¨)"
	@echo "                 .· ´¸.·*´¨) ¸.·*¨)"
	@echo "　　　　　　　　(¸.·´ (¸.·'* ☆"

