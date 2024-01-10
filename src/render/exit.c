/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:02:32 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 00:21:58 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_exit(t_game *game)
{
	int	frame_y_pos;
	int	frame_x_pos;

	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	if ((game->exit->position.x / game->size) >= frame_x_pos
		&& (game->exit->position.y / game->size) >= frame_y_pos
		&& (game->exit->position.x / game->size) < frame_x_pos + F_VIEW_WIDTH
		&& (game->exit->position.y / game->size) < frame_y_pos + F_VIEW_HEIGHT)
	{
		put_img(game, game->exit_imgs[game->exit->frame],
			(game->exit->position.x - ((frame_x_pos * game->size) + game->size
					/ 2)), (game->exit->position.y - ((frame_y_pos * game->size)
					+ game->size / 2)));
		if (game->exit->dead && game->exit->frame < 4)
			game->exit->frame++;
	}
}
