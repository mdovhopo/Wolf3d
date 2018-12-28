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

INC =	-I inc \
		-I frameworks/SDL2_image.framework/Versions/A/Headers \
		-I frameworks/SDL2_mixer.framework/Versions/A/Headers

SRC = src

f = -Wall -Wextra -Werror

FLAGS = 

SRC_C = $(addprefix $(SRC)/, main.c \
							line.c \
							setters.c \
							event_manager.c \
							load_map.c \
							error.c \
							cleaners.c \
							mini_map.c \
							engine.c \
							ray_caster.c \
							move.c \
							turn_camera.c \
							load_texture.c \
							play_music.c)

FRAMEWORKS = -F frameworks \
			-rpath frameworks \
			-framework SDL2 \
			-framework SDL2_image \
			-framework SDL2_mixer

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

libft/libft.a:
	@make -C $(LIBFT)

$(NAME): libft/libft.a $(SRC_O) inc/wolf3d.h
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) $(INC) -o $(NAME) $(SRC_O) -L $(LIBFT) -lft $(FRAMEWORKS) -lpthread
	@echo "\033[92m[$(NAME) Has been created]\033[0m\nrun ./$@ <map>"

$(SRC)/%.o: $(SRC)/%.c 
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) $(INC) -I . -c $< -o $@

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

