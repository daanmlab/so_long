/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:46:52 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:41:16 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_collectibles(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->matrix[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	get_collectible_position(t_game *game, t_position *pos)
{
	if ((pos->x + 1) == game->map->width)
	{
		pos->x = 0;
		pos->y++;
	}
	else
		pos->x++;
	while (pos->y < game->map->height)
	{
		while (pos->x < game->map->width)
		{
			if (game->map->matrix[pos->y][pos->x] == 'C')
				return ;
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
}

t_collectible	*create_collectible(t_game *game, int y, int x)
{
	t_collectible	*coll;

	(void)game;
	coll = malloc(sizeof(t_collectible));
	if (!coll)
		return (NULL);
	coll->position.y = y;
	coll->position.x = x;
	coll->dead = 0;
	coll->frame = 0;
	return (coll);
}

void	set_random_positions(t_game *game)
{
	int	i;
	int	temp;

	i = 0;
	while (game->collectibles[i])
	{
		srand(rand() + game->map->height / game->map->width + game->size
			+ game->player->x);
		if (game->map->matrix[game->collectibles[i]->position.y
				+ 1][game->collectibles[i]->position.x] == '1')
			temp = (game->size / 4);
		else
			temp = (rand() % (game->size - (game->size / 4)));
		game->collectibles[i]->position.x *= game->size;
		game->collectibles[i]->position.y *= game->size;
		game->collectibles[i]->position.x += (rand() % (2 * (game->size / 3)))
			+ (game->size / 6);
		game->collectibles[i]->position.y += temp;
		i++;
	}
}

void	setup_collectibles(t_game *game)
{
	int	count;
	int	i;

	count = count_collectibles(game);
	game->collectibles = ft_calloc(count + 1, sizeof(t_collectible *));
	if (!count)
		free_all(game, "No collectibles found.");
	game->collectibles[count] = NULL;
	game->collectibles[0] = create_collectible(game, 0, 0);
	i = 0;
	while (i < count)
	{
		get_collectible_position(game, &(game->collectibles[i]->position));
		i++;
		if (i < count)
			game->collectibles[i] = create_collectible(game,
					game->collectibles[i - 1]->position.y, game->collectibles[i
					- 1]->position.x);
	}
	i--;
	set_random_positions(game);
}
