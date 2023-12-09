# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:23:07 by dabalm            #+#    #+#              #
#    Updated: 2023/12/09 18:12:26 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	map/map.c \
		map/floodfill.c \
		setup/setup.c \
		setup/img.c \
		setup/collectibles.c \
		setup/exit.c \
		render/render.c \
		render/put_img.c \
		render/walls.c \
		render/collectibles.c \
		render/exit.c \
		player/hitbox.c \
		player/move.c \
		player/kill_coll.c \
		player/wall_collision.c \
		main.c
INCS = so_long.h
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./libft
	$(CC) $(OBJS) -Lminilibx-linux \
				-Iminilibx-linux \
				-L/usr/lib \
				-Iminilibx-linux \
				-lXext \
				-lX11 \
				-lm \
				-lz \
				-o $(NAME) \
				minilibx-linux/libmlx.a \
				libft/libft.a

test: $(NAME)
	clear
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes ./$(NAME) maze.ber

clean:
	@$(MAKE) clean -C ./minilibx-linux
	@$(MAKE) clean -C ./libft
	rm $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

fcount:
	@cat $(SRCS) | wc -l

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) ./so_long.h
	norminette $(SRCS) ./so_long.h

re : fclean all

.PHONY : clean fclean fnorm re all bonus
