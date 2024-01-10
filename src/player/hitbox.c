/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:14:03 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 00:19:21 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_hitbox(t_game *game)
{
	game->player->hitbox->topleft.x = game->player->x - (game->size / 4);
	game->player->hitbox->topleft.y = game->player->y - (game->size / 4);
	game->player->hitbox->topright.x = game->player->x + (game->size / 4);
	game->player->hitbox->topright.y = game->player->y - (game->size / 4);
	game->player->hitbox->bottomleft.x = game->player->x - (game->size / 4);
	game->player->hitbox->bottomleft.y = game->player->y + (game->size / 4);
	game->player->hitbox->bottomright.x = game->player->x + (game->size / 4);
	game->player->hitbox->bottomright.y = game->player->y + (game->size / 4);
}
