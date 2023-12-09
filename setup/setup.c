/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:27 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/09 18:11:57 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*setup_map(char *file)
{
	t_map	*map;

	map = create_map(file);
	if (map)
		check_paths(map);
	return (map);
}

static void	setup_player(t_game *game)
{
	int	x;
	int	y;

	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_printf("handle error setup_player");
	game->player->hitbox = malloc(sizeof(t_hitbox));
	if (!game->player->hitbox)
		ft_printf("handle error setup_player");
	y = 0;
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
	game->player->direction = 'd';
	game->player->move = 0;
	game->player->moving = 0;
}

static void	setup_frame(t_game *game)
{
	game->frame = malloc(sizeof(t_img));
	if (!(game->frame))
	{
		ft_printf("handle error put_frame");
		exit(0);
	}
	game->frame->img = mlx_new_image(game->mlx, game->size * F_VIEW_WIDTH,
			game->size * F_VIEW_HEIGHT);
	game->frame->addr = mlx_get_data_addr(game->frame->img,
			&game->frame->bits_per_pixel, &game->frame->line_length,
			&game->frame->endian);
}

t_game	*setup(int argc, char *argv[])
{
	t_map	*map;
	t_game	*game;

	map = NULL;
	if (argc == 2)
		map = setup_map(argv[1]);
	if (!map)
	{
		ft_printf("handle error setup");
		exit(0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free(map);
		ft_printf("handle error setup");
		exit(0);
	}
	game->size = 128;
	ft_printf("Welcome to \"this is not a playground\"\n");
	ft_printf("window size: %dx%d blocks;\n", VIEW_HEIGHT, VIEW_HEIGHT);
	ft_printf("block size: %dpx;\n", game->size);
	ft_printf("map size: %dx%d;\n", game->map->width, game->map->height);
	game->map = map;
	game->mlx = mlx_init();
	setup_img(game);
	setup_player(game);
	setup_collectibles(game);
	setup_exit(game);
	setup_frame(game);
	game->mlx_win = mlx_new_window(game->mlx, game->size * VIEW_WIDTH,
			game->size * VIEW_HEIGHT, "this is not a playgound");
	return (game);
}
