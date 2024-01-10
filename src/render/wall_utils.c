/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:09 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:40:36 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_floor(char c)
{
	return (c == '0' || c == 'C' || c == 'E' || c == 'P');
}

void	add_one_wall_above(t_game *game, int x, int y, t_position *pos)
{
	int	x_frame_pos;
	int	y_frame_pos;

	x_frame_pos = pos->x;
	y_frame_pos = pos->y;
	if (y > 0 && x >= 0 && is_floor(game->map->matrix[y][x])
		&& game->map->matrix[y + 1][x] == '1')
	{
		put_img(game, game->wall_imgs[0], (x - x_frame_pos) * game->size, (y
				- y_frame_pos) * game->size);
		if (x < F_VIEW_WIDTH + x_frame_pos && is_floor(game->map->matrix[y
					+ 1][x - 1]))
			put_img(game, game->wall_imgs[1], (x - x_frame_pos) * game->size, (y
					- y_frame_pos) * game->size);
		if (x < F_VIEW_WIDTH + x_frame_pos && is_floor(game->map->matrix[y
					+ 1][x + 1]))
			put_img(game, game->wall_imgs[2], (x - x_frame_pos) * game->size, (y
					- y_frame_pos) * game->size);
	}
}

void	add_one_wall_beneath(t_game *game, int x, int y, t_position *pos)
{
	int	frame_x_pos;
	int	frame_y_pos;

	frame_x_pos = pos->x;
	frame_y_pos = pos->y;
	if (y >= 0 && x >= 0 && is_floor(game->map->matrix[y + 1][x])
		&& game->map->matrix[y][x] == '1')
	{
		put_img(game, game->wall_imgs[3], (x - frame_x_pos) * game->size, (y
				- frame_y_pos) * game->size);
		if (x < F_VIEW_WIDTH + frame_x_pos && is_floor(game->map->matrix[y][x
				- 1]))
			put_img(game, game->wall_imgs[4], (x - frame_x_pos) * game->size, (y
					- frame_y_pos) * game->size);
		if (x < F_VIEW_WIDTH + frame_x_pos && is_floor(game->map->matrix[y][x
				+ 1]))
			put_img(game, game->wall_imgs[5], (x - frame_x_pos) * game->size, (y
					- frame_y_pos) * game->size);
	}
}

void	add_one_wall_left(t_game *game, int x, int y, t_position *pos)
{
	if (y >= 0 && x >= 0 && is_floor(game->map->matrix[y][x + 1])
		&& game->map->matrix[y][x] == '1')
	{
		put_img(game, game->wall_imgs[6], (x - pos->x) * game->size, (y
				- pos->y) * game->size);
		if (game->map->matrix[y + 1][x] == '1' && game->map->matrix[y + 1][x
			+ 1] == '1')
			put_img(game, game->wall_imgs[8], (x - pos->x) * game->size, (y
					- pos->y) * game->size);
	}
	if (y >= 0 && x >= 0 && (y + 1) < game->map->height && (x
			+ 1) < game->map->width && game->map->matrix[y][x] == '1'
		&& game->map->matrix[y][x + 1] == '1' && game->map->matrix[y
		+ 1][x] == '1' && is_floor(game->map->matrix[y + 1][x + 1]))
		put_img(game, game->wall_imgs[7], (x - pos->x) * game->size, (y
				- pos->y) * game->size);
}

void	add_one_wall_right(t_game *game, int x, int y, t_position *pos)
{
	if (y >= 0 && x >= 0 && is_floor(game->map->matrix[y][x - 1])
		&& game->map->matrix[y][x] == '1')
	{
		put_img(game, game->wall_imgs[9], (x - pos->x) * game->size, (y
				- pos->y) * game->size);
		if (game->map->matrix[y + 1][x] == '1' && game->map->matrix[y + 1][x
			- 1] == '1')
			put_img(game, game->wall_imgs[11], (x - pos->x) * game->size, (y
					- pos->y) * game->size);
	}
	if (y >= 0 && x >= 0 && (y + 1) < game->map->height && (x
			+ 1) < game->map->width && game->map->matrix[y][x] == '1'
		&& game->map->matrix[y][x - 1] == '1' && game->map->matrix[y
		+ 1][x] == '1' && is_floor(game->map->matrix[y + 1][x - 1]))
		put_img(game, game->wall_imgs[10], (x - pos->x) * game->size, (y
				- pos->y) * game->size);
}
