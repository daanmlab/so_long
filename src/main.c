/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:16:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:46:19 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_all(game, "bye bye");
	if (keycode == 'w')
	{
		game->player->direction = 'u';
		game->player->moving = 1;
	}
	else if (keycode == 'a')
	{
		game->player->direction = 'l';
		game->player->moving = 1;
	}
	else if (keycode == 's')
	{
		game->player->direction = 'd';
		game->player->moving = 1;
	}
	else if (keycode == 'd')
	{
		game->player->direction = 'r';
		game->player->moving = 1;
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 'w' && game->player->direction == 'u')
	{
		game->player->moving = 0;
		game->player->move = 0;
	}
	else if (keycode == 'a' && game->player->direction == 'l')
	{
		game->player->moving = 0;
		game->player->move = 0;
	}
	else if (keycode == 's' && game->player->direction == 'd')
	{
		game->player->moving = 0;
		game->player->move = 0;
	}
	else if (keycode == 'd' && game->player->direction == 'r')
	{
		game->player->moving = 0;
		game->player->move = 0;
	}
	return (1);
}

int	destroy_hook(t_game *game)
{
	free_all(game, "bye bye");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = setup(argc, argv);
	game->move_distance = .08;
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, &key_hook, game);
	mlx_hook(game->mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		game);
	mlx_hook(game->mlx_win, DestroyNotify, StructureNotifyMask, &destroy_hook,
		game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
