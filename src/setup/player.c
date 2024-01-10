/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:44:58 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:18:40 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->matrix[y][x] == 'P')
				break ;
			x++;
		}
		if (game->map->matrix[y][x] == 'P')
			break ;
		y++;
	}
	game->player->x = (x * game->size) + (game->size / 2);
	game->player->y = (y * game->size) + (game->size / 2);
}

void	setup_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("error setup_player");
		exit(0);
	}
	game->player->hitbox = malloc(sizeof(t_hitbox));
	if (!game->player->hitbox)
	{
		ft_printf("error setup_player");
		exit(0);
	}
	find_player(game);
	game->player->direction = 'd';
	game->player->distance_moved = 0;
	game->player->move = 0;
	game->player->moving = 0;
}
