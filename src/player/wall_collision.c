/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:18:53 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:51:48 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_move_up(t_game *game)
{
	int	move_distance;
	int	xleft;
	int	xright;
	int	y;

	move_distance = ceil(game->size * game->move_distance);
	xleft = (game->player->hitbox->topleft.x / game->size);
	xright = (game->player->hitbox->topright.x / game->size);
	y = (game->player->hitbox->topleft.y / game->size);
	if ((game->map->matrix[y - 1][xleft] == '1' || game->map->matrix[y
			- 1][xright] == '1') && (game->player->hitbox->topleft.y
			- move_distance) / game->size != y)
		return (0);
	game->player->y -= move_distance;
	game->player->distance_moved += move_distance;
	if (game->player->distance_moved
		/ game->size != (game->player->distance_moved - move_distance)
		/ game->size)
		ft_printf("moves: %d\n", game->player->distance_moved / game->size);
	return (1);
}

int	can_move_down(t_game *game)
{
	int	move_distance;
	int	xleft;
	int	xright;
	int	y;

	move_distance = ceil(game->size * game->move_distance);
	xleft = (game->player->hitbox->bottomleft.x / game->size);
	xright = (game->player->hitbox->bottomright.x / game->size);
	y = (game->player->hitbox->bottomleft.y / game->size);
	if ((game->map->matrix[y + 1][xleft] == '1' || game->map->matrix[y
			+ 1][xright] == '1') && (game->player->hitbox->bottomleft.y
			+ move_distance) / game->size != y)
		return (0);
	game->player->y += move_distance;
	game->player->distance_moved += move_distance;
	if (game->player->distance_moved
		/ game->size != (game->player->distance_moved - move_distance)
		/ game->size)
		ft_printf("moves: %d\n", game->player->distance_moved / game->size);
	return (1);
}

int	can_move_right(t_game *game)
{
	int	move_distance;
	int	ytop;
	int	ybottom;
	int	x;

	move_distance = ceil(game->size * game->move_distance);
	ytop = (game->player->hitbox->topright.y / game->size);
	ybottom = (game->player->hitbox->bottomright.y / game->size);
	x = (game->player->hitbox->topright.x / game->size);
	if ((game->map->matrix[ytop][x + 1] == '1' || game->map->matrix[ybottom][x
		+ 1] == '1') && (game->player->hitbox->topright.x + move_distance)
		/ game->size != x)
		return (0);
	game->player->x += move_distance;
	game->player->distance_moved += move_distance;
	if (game->player->distance_moved
		/ game->size != (game->player->distance_moved - move_distance)
		/ game->size)
		ft_printf("moves: %d\n", game->player->distance_moved / game->size);
	return (1);
}

int	can_move_left(t_game *game)
{
	int	move_distance;
	int	ytop;
	int	ybottom;
	int	x;

	move_distance = ceil(game->size * game->move_distance);
	ytop = (game->player->hitbox->topleft.y / game->size);
	ybottom = (game->player->hitbox->bottomleft.y / game->size);
	x = (game->player->hitbox->topleft.x / game->size);
	if ((game->map->matrix[ytop][x - 1] == '1' || game->map->matrix[ybottom][x
		- 1] == '1') && (game->player->hitbox->topleft.x - move_distance)
		/ game->size != x)
		return (0);
	game->player->x -= move_distance;
	game->player->distance_moved += move_distance;
	if (game->player->distance_moved
		/ game->size != (game->player->distance_moved - move_distance)
		/ game->size)
		ft_printf("moves: %d\n", game->player->distance_moved / game->size);
	return (1);
}
