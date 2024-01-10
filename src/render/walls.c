/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:10:36 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:01:38 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_wall_above(t_game *game)
{
	int			y;
	int			x;
	t_position	frame_pos;

	frame_pos.y = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_pos.x = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_pos.y;
	while (y < F_VIEW_HEIGHT + frame_pos.y && y < game->map->height - 1)
	{
		x = frame_pos.x;
		while (x < F_VIEW_WIDTH + frame_pos.x && x < game->map->width)
		{
			add_one_wall_above(game, x, y, &frame_pos);
			x++;
		}
		y++;
	}
}

void	add_wall_beneath(t_game *game)
{
	int			y;
	int			x;
	t_position	frame_pos;

	frame_pos.y = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_pos.x = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_pos.y;
	while (y < F_VIEW_HEIGHT + frame_pos.y && y < game->map->height - 1)
	{
		x = frame_pos.x;
		while (x < F_VIEW_WIDTH + frame_pos.x && x < game->map->width)
		{
			add_one_wall_beneath(game, x, y, &frame_pos);
			x++;
		}
		y++;
	}
}

void	add_wall_left(t_game *game)
{
	int			y;
	int			x;
	t_position	frame_pos;

	frame_pos.y = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_pos.x = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_pos.y;
	while (y < F_VIEW_HEIGHT + frame_pos.y && y < game->map->height - 1)
	{
		x = frame_pos.x;
		while (x < F_VIEW_WIDTH + frame_pos.x && x < game->map->width)
		{
			add_one_wall_left(game, x, y, &frame_pos);
			x++;
		}
		y++;
	}
}

void	add_wall_right(t_game *game)
{
	int			y;
	int			x;
	t_position	frame_pos;

	frame_pos.y = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_pos.x = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	y = frame_pos.y;
	while (y < F_VIEW_HEIGHT + frame_pos.y && y < game->map->height - 1)
	{
		x = frame_pos.x;
		while (x < F_VIEW_WIDTH + frame_pos.x && x < game->map->width)
		{
			add_one_wall_right(game, x, y, &frame_pos);
			x++;
		}
		y++;
	}
}
