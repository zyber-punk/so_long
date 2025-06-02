# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 19:14:28 by ulyssezyber       #+#    #+#              #
#    Updated: 2025/04/09 18:20:13 by uzyberaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

# Detect OS
ifeq ($(shell uname), Linux)
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -lXext -lX11 -lm -lz
else
	MLX_DIR = minilibx_opengl_20191021
	MLX_FLAGS = -framework OpenGL -framework AppKit
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
MLX = -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

# Mandatory sources
MANDATORY_SRCS = mandatory/main.c \
	mandatory/game/draw.c \
	mandatory/game/error_free.c \
	mandatory/game/game.c \
	mandatory/game/player_movement.c \
	mandatory/game/render.c \
	mandatory/game/free_game_utils.c \
	mandatory/init/init_game.c \
	mandatory/init/init_maps.c \
	mandatory/init/init_tex.c \
	mandatory/load/load_textures.c \
	mandatory/load/load_walls.c \
	mandatory/map/map.c \
	mandatory/map/map_characters.c \
	mandatory/map/map_elements.c \
	mandatory/map/map_rectangular.c \
	mandatory/map/map_valid_path.c \
	mandatory/map/map_walls.c \
	mandatory/map/map_utils.c \
	mandatory/utils/utils.c \
	mandatory/utils/utils_split.c \
	mandatory/utils/utils_str.c

# Bonus sources
BONUS_SRCS = bonus/main.c \
	bonus/game/draw.c \
	bonus/game/enemies.c \
	bonus/game/enemies_movement.c \
	bonus/game/error_free.c \
	bonus/game/game.c \
	bonus/game/player_movement.c \
	bonus/game/render.c \
	bonus/game/render_moves.c \
	bonus/game/free_utils.c \
	bonus/game/destroy_textures_utils.c \
	bonus/game/animations_utils.c \
	bonus/game/destroy_utils.c \
	bonus/game/destroy_tex_utils.c \
	bonus/init/init_enemies.c \
	bonus/init/init_game.c \
	bonus/init/init_maps.c \
	bonus/init/init_tex.c \
	bonus/load/load_animated_copy_utils.c \
	bonus/load/load_animated_player_utils.c \
	bonus/load/load_enemy.c \
	bonus/load/load_enemy_utils.c \
	bonus/load/load_outlines.c \
	bonus/load/load_player.c \
	bonus/load/load_player_utils.c \
	bonus/load/load_static_copy_utils.c \
	bonus/load/load_static_player_utils.c \
	bonus/load/load_textures.c \
	bonus/load/load_walls.c \
	bonus/load/load_tex_utils.c \
	bonus/map/map.c \
	bonus/map/map_characters.c \
	bonus/map/map_elements.c \
	bonus/map/map_rectangular.c \
	bonus/map/map_valid_path.c \
	bonus/map/map_walls.c \
	bonus/map/map_utils.c \
	bonus/utils/utils.c \
	bonus/utils/utils_split.c \
	bonus/utils/utils_str.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLX) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
