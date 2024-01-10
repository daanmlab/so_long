/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:27 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 14:30:23 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*setup_map(char *file)
{
	t_map	*map;

	map = create_map(file);
	check_paths(map);
	return (map);
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
	if (!game->frame->img)
		free_all(game, "mlx fail :(");
	game->frame->addr = mlx_get_data_addr(game->frame->img,
			&game->frame->bits_per_pixel, &game->frame->line_length,
			&game->frame->endian);
}

/**
 * @brief sets the map and game
 */
void	tiny_setup(t_game *game)
{
	game->size = 128;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->size * VIEW_WIDTH,
			game->size * VIEW_HEIGHT, "this is not a playgound");
	game->exit = NULL;
	setup_frame(game);
	setup_img(game);
	setup_player(game);
	setup_collectibles(game);
	setup_exit(game);
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
		ft_printf("Error: invalid map.\n");
		exit(0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free(map);
		ft_printf("Error: invalid map.\n");
		exit(0);
	}
	game->map = map;
	game->size = 128;
	tiny_setup(game);
	return (game);
}
