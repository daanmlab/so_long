/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:27 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/19 20:50:30 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_collectibles(t_game *game)
{
	int	i;
	int	frame_y_pos;
	int	frame_x_pos;

	i = 0;
	frame_y_pos = (game->player->y / game->size) - (F_VIEW_HEIGHT / 2);
	frame_x_pos = (game->player->x / game->size) - (F_VIEW_WIDTH / 2);
	while (game->collectibles[i])
	{
		if ((game->collectibles[i]->position.x / game->size) >= frame_x_pos
			&& (game->collectibles[i]->position.y / game->size) >= frame_y_pos
			&& (game->collectibles[i]->position.x / game->size) < frame_x_pos
			+ F_VIEW_WIDTH && (game->collectibles[i]->position.y
				/ game->size) < frame_y_pos + F_VIEW_HEIGHT)
		{
			put_img(game, game->collectible_imgs[game->collectibles[i]->frame],
				(game->collectibles[i]->position.x - ((frame_x_pos * game->size)
						+ game->size / 2)), (game->collectibles[i]->position.y
					- ((frame_y_pos * game->size) + game->size / 2)));
			if (game->collectibles[i]->dead && game->collectibles[i]->frame < 4)
				game->collectibles[i]->frame++;
		}
		i++;
	}
}
