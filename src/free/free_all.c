/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:37:20 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:03:59 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
}

void	free_mlx(t_game *game)
{
	if (game->mlx_win != NULL)
		mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_player(t_game *game)
{
	free(game->player->hitbox);
	free(game->player);
}

void	free_collectibles(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (!&(game->collectibles))
		return ;
	while (game && game->collectibles && game->collectibles[i])
	{
		free(game->collectibles[i]);
		i++;
	}
	free(game->collectibles);
}

void	*free_all(t_game *game, char *msg)
{
	free_imgs(game);
	free_map(game->map);
	free_player(game);
	free_collectibles(game);
	free_mlx(game);
	if (game->exit)
		free(game->exit);
	free(game);
	ft_printf("%s\n", msg);
	exit(0);
}
