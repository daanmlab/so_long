/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:12:49 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:38:24 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	do_move_up(t_game *game)
{
	if (can_move_up(game))
	{
		kill_coll(game, &(game->player->hitbox->topleft),
			&(game->player->hitbox->topright));
		use_exit(game);
		game->player->move++;
	}
}

void	do_move_down(t_game *game)
{
	if (can_move_down(game))
	{
		use_exit(game);
		kill_coll(game, &(game->player->hitbox->bottomleft),
			&(game->player->hitbox->bottomright));
		game->player->move++;
	}
}

void	do_move_right(t_game *game)
{
	if (can_move_right(game))
	{
		use_exit(game);
		kill_coll(game, &(game->player->hitbox->bottomright),
			&(game->player->hitbox->topright));
		game->player->move++;
	}
}

void	do_move_left(t_game *game)
{
	if (can_move_left(game))
	{
		use_exit(game);
		kill_coll(game, &(game->player->hitbox->topleft),
			&(game->player->hitbox->bottomleft));
		game->player->move++;
	}
}

int	do_move(t_game *game)
{
	if (!game->player->moving)
		return (0);
	get_hitbox(game);
	if (game->player->direction == 'u')
		do_move_up(game);
	else if (game->player->direction == 'l')
		do_move_left(game);
	else if (game->player->direction == 'd')
		do_move_down(game);
	else if (game->player->direction == 'r')
		do_move_right(game);
	return (1);
}
