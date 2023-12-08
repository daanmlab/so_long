/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:10:36 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/07 14:51:07 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_floor(char c)
{
	return (c == '0' || c == 'C' || c == 'E' || c == 'P');
}

void	add_wall_above(t_game *game)
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
			if (y > 0 && x >= 0 && is_floor(game->map->matrix[y][x])
				&& game->map->matrix[y + 1][x] == '1')
			{
				put_img(game, game->wall_imgs[0], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
				if (x < F_VIEW_WIDTH + frame_x_pos
					&& is_floor(game->map->matrix[y + 1][x - 1]))
					put_img(game, game->wall_imgs[1], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
				if (x < F_VIEW_WIDTH + frame_x_pos
					&& is_floor(game->map->matrix[y + 1][x + 1]))
					put_img(game, game->wall_imgs[2], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
			}
			x++;
		}
		y++;
	}
}

void	add_wall_beneath(t_game *game)
{
	int	y;
	int	x;
	int	frame_y_pos;
	int	frame_x_pos;

	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_y_pos;
	while (y < F_VIEW_HEIGHT + frame_y_pos && y < game->map->height - 1)
	{
		x = frame_x_pos;
		while (x < F_VIEW_WIDTH + frame_x_pos && x < game->map->width)
		{
			if (y >= 0 && x >= 0 && is_floor(game->map->matrix[y + 1][x])
				&& game->map->matrix[y][x] == '1')
			{
				put_img(game, game->wall_imgs[3], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
				if (x < F_VIEW_WIDTH + frame_x_pos
					&& is_floor(game->map->matrix[y][x - 1]))
					put_img(game, game->wall_imgs[4], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
				if (x < F_VIEW_WIDTH + frame_x_pos
					&& is_floor(game->map->matrix[y][x + 1]))
					put_img(game, game->wall_imgs[5], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
			}
			x++;
		}
		y++;
	}
}

void	add_wall_left(t_game *game)
{
	int	y;
	int	x;
	int	frame_y_pos;
	int	frame_x_pos;

	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_y_pos;
	while (y < F_VIEW_HEIGHT + frame_y_pos && y < game->map->height - 1)
	{
		x = frame_x_pos;
		while (x < F_VIEW_WIDTH + frame_x_pos && x < game->map->width)
		{
			if (y >= 0 && x >= 0 && is_floor(game->map->matrix[y][x + 1])
				&& game->map->matrix[y][x] == '1')
			{
				put_img(game, game->wall_imgs[6], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
				if (
					game->map->matrix[y + 1][x] == '1' &&
					game->map->matrix[y + 1][x + 1] == '1'
				)
					put_img(game, game->wall_imgs[8], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
			}
			
			if (
				y >= 0 && x >= 0 &&
				(y + 1) < game->map->height && 
				(x + 1) < game->map->width &&
				game->map->matrix[y][x] == '1' &&
				game->map->matrix[y][x + 1] == '1' &&
				game->map->matrix[y + 1][x] == '1' &&
				is_floor(game->map->matrix[y + 1][x + 1])
			)
				put_img(game, game->wall_imgs[7], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
			x++;
		}
		y++;
	}
}

void	add_wall_right(t_game *game)
{
	int	y;
	int	x;
	int	frame_y_pos;
	int	frame_x_pos;

	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_y_pos;
	while (y < F_VIEW_HEIGHT + frame_y_pos && y < game->map->height - 1)
	{
		x = frame_x_pos;
		while (x < F_VIEW_WIDTH + frame_x_pos && x < game->map->width)
		{
			if (y > 0 && x > 0 && is_floor(game->map->matrix[y][x - 1])
				&& game->map->matrix[y][x] == '1')
			{
				put_img(game, game->wall_imgs[9], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
				if (
					game->map->matrix[y + 1][x] == '1' && 
					game->map->matrix[y + 1][x - 1] == '1')
					put_img(game, game->wall_imgs[11], (x - frame_x_pos)
						* game->size, (y - frame_y_pos) * game->size);
			}
			if (
				y >= 0 && x > 0 &&
				(y + 1) < game->map->height && 
				(x) < game->map->width &&				
				game->map->matrix[y][x] == '1' &&
				game->map->matrix[y][x - 1] == '1' &&
				game->map->matrix[y + 1][x] == '1' &&
				is_floor(game->map->matrix[y + 1][x - 1])
			)
				put_img(game, game->wall_imgs[10], (x - frame_x_pos)
					* game->size, (y - frame_y_pos) * game->size);
			x++;
		}
		y++;
	}
}
