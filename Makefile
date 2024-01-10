# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:23:07 by dabalm            #+#    #+#              #
#    Updated: 2023/12/20 15:59:01 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
SRC_DIR = src
HEADER_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
MLX_DIR = mlx
SRC_FILES = src/free/free_all.c src/free/free_images.c src/map/floodfill.c src/map/map.c src/player/hitbox.c src/player/kill_coll.c src/player/move.c src/player/wall_collision.c src/render/collectibles.c src/render/exit.c src/render/put_img.c src/render/render.c src/render/walls.c src/render/wall_utils.c src/setup/collectibles.c src/setup/exit.c src/setup/img.c src/setup/player.c src/setup/setup.c src/main.c
OBJ_FILES = obj/free/free_all.o obj/free/free_images.o obj/map/floodfill.o obj/map/map.o obj/player/hitbox.o obj/player/kill_coll.o obj/player/move.o obj/player/wall_collision.o obj/render/collectibles.o obj/render/exit.o obj/render/put_img.o obj/render/render.o obj/render/walls.o obj/render/wall_utils.o obj/setup/collectibles.o obj/setup/exit.o obj/setup/img.o obj/setup/player.o obj/setup/setup.o obj/main.o
TARGET = so_long

all: $(TARGET)
$(TARGET): $(OBJ_FILES)
	echo $(OBJ_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) -Iheaders/ -Ilibft/ $^ ./libft/libft.a minilibx-linux/libmlx_Linux.a -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(TARGET)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Iheaders/ -ILibft/ -Iminilibx-linux -c $< -o $@
test: re
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) test_map_big.ber
clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(TARGET)
re: fclean all

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRC_DIR)/$(SRCS) $(HEADER_DIR)/*.h
	norminette $(SRCS) $(HEADER_DIR)/*.h
	
.PHONY: all clean fclean re
