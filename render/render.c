/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:44:40 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/09 18:13:33 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	black(t_game *game)
{
	int	y;
	int	x;

	y = F_VIEW_HEIGHT * game->size;
	while (y--)
	{
		x = F_VIEW_WIDTH * game->size;
		while (x--)
		{
			pixel_put(game, x, y, 0x00000000);
		}
	}
}

static void	add_floor(t_game *game)
{
	int	y;
	int	x;
	int	frame_y_pos;
	int	frame_x_pos;

	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_y_pos;
	while (y < F_VIEW_HEIGHT + frame_y_pos && y < game->map->height)
	{
		x = frame_x_pos;
		while (x < F_VIEW_WIDTH + frame_x_pos && x < game->map->width)
		{
			if (y >= 0 && x >= 0 && (game->map->matrix[y][x] == '0'
					|| game->map->matrix[y][x] == 'C'
					|| game->map->matrix[y][x] == 'E'
					|| game->map->matrix[y][x] == 'P'))
				put_img(game, game->floor_img, (x - frame_x_pos) * game->size,
					(y - frame_y_pos) * game->size);
			x++;
		}
		y++;
	}
}

static void	add_player(t_game *game)
{
	t_img	*img;

	img = NULL;
	if (game->player->move == 0)
	{
		if (game->player->direction == 'u')
			img = game->player_imgs[0][0];
		else if (game->player->direction == 'r')
			img = game->player_imgs[1][0];
		else if (game->player->direction == 'd')
			img = game->player_imgs[2][0];
		else if (game->player->direction == 'l')
			img = game->player_imgs[3][0];
	}
	else if (game->player->direction == 'u')
		img = game->player_imgs[0][(game->player->move % 3) + 1];
	else if (game->player->direction == 'r')
		img = game->player_imgs[1][(game->player->move % 3) + 1];
	else if (game->player->direction == 'd')
		img = game->player_imgs[2][(game->player->move % 3) + 1];
	else if (game->player->direction == 'l')
		img = game->player_imgs[3][(game->player->move % 3) + 1];
	put_img(game, img, ((VIEW_WIDTH * game->size) / 2) - (game->size / 2)
		+ (game->player->x % game->size), ((VIEW_HEIGHT * game->size) / 2)
		- (game->size / 2) + (game->player->y % game->size));
}

void	add_test(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	get_hitbox(game);
	y = ((VIEW_HEIGHT * game->size) / 2) - (game->size / 2)
		+ (game->player->hitbox->bottomright.y % game->size);
	while (x < (F_VIEW_WIDTH * game->size))
	{
		pixel_put(game, x, y, 0x00ff0000);
		x++;
	}
}

int	render(t_game *game)
{
	do_move(game);
	black(game);
	add_floor(game);
	add_wall_left(game);
	add_wall_right(game);
	add_wall_beneath(game);
	add_collectibles(game);
	add_exit(game);
	add_player(game);
	// add_test(game);
	add_wall_above(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame->img,
		-(game->player->x % game->size), -(game->player->y % game->size));
	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame->img,
	// 	0, 0);
	return (1);
}
