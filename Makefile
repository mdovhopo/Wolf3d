# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 12:58:19 by mdovhopo          #+#    #+#              #
#    Updated: 2018/12/28 19:20:51 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBFT_DIR = libft

SRC_DIR = src

INC =	-I inc \
		-I libft \
		-I frameworks/SDL2_image.framework/Versions/A/Headers \
		-I frameworks/SDL2_mixer.framework/Versions/A/Headers \
		-I frameworks/SDL2.framework/Versions/A/Headers \

FRAMEWORKS = -F frameworks \
			-rpath frameworks \
			-framework SDL2 \
			-framework SDL2_image \
			-framework SDL2_mixer \

FLAGS = -Wall -Wextra -Werror -O2

SRC_C = $(addprefix $(SRC_DIR)/, main.c \
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
							play_music.c \
							infinite_rotate.c)


SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

libft/libft.a:
	@make -C $(LIBFT_DIR)

$(NAME): libft/libft.a $(SRC_O) inc/wolf3d.h
	@echo "[Compiling] $@"
	@$(CC) $(FLAGS) -o $(NAME) $(SRC_O) -L $(LIBFT_DIR) -lft $(FRAMEWORKS)
	@echo "\033[92m[$(NAME) Has been created]\033[0m\nrun ./$@ <map>"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo "[Compiling] $(@:.o=.c)"
	@$(CC) $(FLAGS) $(INC) -I . -c $< -o $@

clean:	
	@/bin/rm -f $(SRC_O)

lclean:
	@make -C $(LIBFT_DIR) fclean
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

