/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:15:54 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/07 16:01:38 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*create_img(t_game *game, char *img_name)
{
	char	*temp;
	char	*file;
	t_img	*img;

	img = malloc(sizeof(t_img));
	temp = ft_strjoin("assets/", img_name);
	file = ft_strjoin(temp, "_");
	free(temp);
	temp = ft_strjoin(file, ft_itoa(game->size));
	free(file);
	file = ft_strjoin(temp, ".xpm");
	free(temp);
	img->img = mlx_xpm_file_to_image(game->mlx, file, &img->x, &img->y);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (img);
}

void	setup_img_player(t_game *game)
{
	game->player_imgs = ft_calloc(4, sizeof(t_img **));
	game->player_imgs[0] = ft_calloc(5, sizeof(t_img *));
	game->player_imgs[0][0] = create_img(game, "player_up");
	game->player_imgs[0][1] = create_img(game, "player_walking_up_1");
	game->player_imgs[0][2] = create_img(game, "player_walking_up_2");
	game->player_imgs[0][3] = create_img(game, "player_walking_up_3");
	game->player_imgs[0][4] = create_img(game, "player_walking_up_4");
	game->player_imgs[1] = ft_calloc(5, sizeof(t_img *));
	game->player_imgs[1][0] = create_img(game, "player_right");
	game->player_imgs[1][1] = create_img(game, "player_walking_right_1");
	game->player_imgs[1][2] = create_img(game, "player_walking_right_2");
	game->player_imgs[1][3] = create_img(game, "player_walking_right_3");
	game->player_imgs[1][4] = create_img(game, "player_walking_right_4");
	game->player_imgs[2] = ft_calloc(5, sizeof(t_img *));
	game->player_imgs[2][0] = create_img(game, "player_down");
	game->player_imgs[2][1] = create_img(game, "player_walking_down_1");
	game->player_imgs[2][2] = create_img(game, "player_walking_down_2");
	game->player_imgs[2][3] = create_img(game, "player_walking_down_3");
	game->player_imgs[2][4] = create_img(game, "player_walking_down_4");
	game->player_imgs[3] = ft_calloc(5, sizeof(t_img *));
	game->player_imgs[3][0] = create_img(game, "player_left");
	game->player_imgs[3][1] = create_img(game, "player_walking_left_1");
	game->player_imgs[3][2] = create_img(game, "player_walking_left_2");
	game->player_imgs[3][3] = create_img(game, "player_walking_left_3");
	game->player_imgs[3][4] = create_img(game, "player_walking_left_4");
}

void setup_img_collectibles(t_game *game)
{
	game->collectible_imgs = ft_calloc(2, sizeof(t_img *));
	game->collectible_imgs[0] = create_img(game, "collectible_alive_1");   
	game->collectible_imgs[1] = create_img(game, "collectible_dead_1");
}

void	setup_img(t_game *game)
{
	setup_img_collectibles(game);
	setup_img_player(game);
	game->wall_imgs = ft_calloc(12, sizeof(t_img *));
	game->wall_imgs[0] = create_img(game, "wall_top");
	game->wall_imgs[1] = create_img(game, "wall_top_corner_left");
	game->wall_imgs[2] = create_img(game, "wall_top_corner_right");
	game->wall_imgs[3] = create_img(game, "wall_bottom");
	game->wall_imgs[4] = create_img(game, "wall_bottom_corner_left");
	game->wall_imgs[5] = create_img(game, "wall_bottom_corner_right");
	game->wall_imgs[6] = create_img(game, "wall_left");
	game->wall_imgs[7] = create_img(game, "wall_left_corner_top");
	game->wall_imgs[8] = create_img(game, "wall_left_corner_bottom");
	game->wall_imgs[9] = create_img(game, "wall_right");
	game->wall_imgs[10] = create_img(game, "wall_right_corner_top");
	game->wall_imgs[11] = create_img(game, "wall_right_corner_bottom");
	game->floor_img = create_img(game, "floor");
	// game->wall_img = create_img(game, "wall");
	// game->item_img = create_img(game, "item");
	// game->exit_img = create_img(game, "exit");
	// if (!game->player_imgs || !game->floor_img || !game->wall_img
	// || !game->item_img || !game->exit_img)
	//     ft_printf("handle error setup_img");
}