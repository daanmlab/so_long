/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:31:10 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 00:31:49 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_player_imgs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->player_imgs[i])
	{
		j = 0;
		while (game->player_imgs[i][j])
		{
			mlx_destroy_image(game->mlx, game->player_imgs[i][j]->img);
			free(game->player_imgs[i][j]);
			j++;
		}
		free(game->player_imgs[i]);
		i++;
	}
	free(game->player_imgs);
}

void	free_wall_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (game->wall_imgs[i])
	{
		mlx_destroy_image(game->mlx, game->wall_imgs[i]->img);
		free(game->wall_imgs[i]);
		i++;
	}
	free(game->wall_imgs);
}

void	free_collectible_imgs(t_game *game)
{
	int	i;

	i = 0;
	if (!game->collectible_imgs)
		return ;
	while (game->collectible_imgs[i])
	{
		mlx_destroy_image(game->mlx, game->collectible_imgs[i]->img);
		free(game->collectible_imgs[i]);
		i++;
	}
	free(game->collectible_imgs);
}

void	free_exit_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (game->exit_imgs[i])
	{
		mlx_destroy_image(game->mlx, game->exit_imgs[i]->img);
		free(game->exit_imgs[i]);
		i++;
	}
	free(game->exit_imgs);
}

void	free_imgs(t_game *game)
{
	free_player_imgs(game);
	free_wall_imgs(game);
	free_collectible_imgs(game);
	free_exit_imgs(game);
	if (game->floor_img)
	{
		if (game->floor_img->img)
			mlx_destroy_image(game->mlx, game->floor_img->img);
		free(game->floor_img);
	}
	if (game->frame)
	{
		if (game->frame->img)
			mlx_destroy_image(game->mlx, game->frame->img);
		free(game->frame);
	}
}
