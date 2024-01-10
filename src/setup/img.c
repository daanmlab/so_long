/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:15:54 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 00:35:46 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*create_img(t_game *game, char *img_name)
{
	char	*temp;
	char	*temp2;
	char	*file;
	t_img	*img;

	img = malloc(sizeof(t_img));
	temp = ft_strjoin("assets/", img_name);
	file = ft_strjoin(temp, "_");
	free(temp);
	temp2 = ft_itoa(game->size);
	temp = ft_strjoin(file, temp2);
	free(temp2);
	free(file);
	file = ft_strjoin(temp, ".xpm");
	free(temp);
	img->img = mlx_xpm_file_to_image(game->mlx, file, &img->x, &img->y);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	free(file);
	return (img);
}

void	setup_img_exit(t_game *game)
{
	game->exit_imgs = ft_calloc(7, sizeof(t_img *));
	game->exit_imgs[0] = create_img(game, "exit_1");
	game->exit_imgs[1] = create_img(game, "exit_2");
	game->exit_imgs[2] = create_img(game, "exit_3");
	game->exit_imgs[3] = create_img(game, "exit_4");
	game->exit_imgs[4] = create_img(game, "exit_5");
	game->exit_imgs[5] = create_img(game, "exit_6");
}

void	setup_img_player(t_game *game)
{
	game->player_imgs = ft_calloc(5, sizeof(t_img **));
	game->player_imgs[0] = ft_calloc(6, sizeof(t_img *));
	game->player_imgs[0][0] = create_img(game, "player_up");
	game->player_imgs[0][1] = create_img(game, "player_walking_up_1");
	game->player_imgs[0][2] = create_img(game, "player_walking_up_2");
	game->player_imgs[0][3] = create_img(game, "player_walking_up_3");
	game->player_imgs[0][4] = create_img(game, "player_walking_up_4");
	game->player_imgs[1] = ft_calloc(6, sizeof(t_img *));
	game->player_imgs[1][0] = create_img(game, "player_right");
	game->player_imgs[1][1] = create_img(game, "player_walking_right_1");
	game->player_imgs[1][2] = create_img(game, "player_walking_right_2");
	game->player_imgs[1][3] = create_img(game, "player_walking_right_3");
	game->player_imgs[1][4] = create_img(game, "player_walking_right_4");
	game->player_imgs[2] = ft_calloc(6, sizeof(t_img *));
	game->player_imgs[2][0] = create_img(game, "player_down");
	game->player_imgs[2][1] = create_img(game, "player_walking_down_1");
	game->player_imgs[2][2] = create_img(game, "player_walking_down_2");
	game->player_imgs[2][3] = create_img(game, "player_walking_down_3");
	game->player_imgs[2][4] = create_img(game, "player_walking_down_4");
	game->player_imgs[3] = ft_calloc(6, sizeof(t_img *));
	game->player_imgs[3][0] = create_img(game, "player_left");
	game->player_imgs[3][1] = create_img(game, "player_walking_left_1");
	game->player_imgs[3][2] = create_img(game, "player_walking_left_2");
	game->player_imgs[3][3] = create_img(game, "player_walking_left_3");
	game->player_imgs[3][4] = create_img(game, "player_walking_left_4");
}

void	setup_img_collectibles(t_game *game)
{
	game->collectible_imgs = ft_calloc(6, sizeof(t_img *));
	game->collectible_imgs[0] = create_img(game, "collectible_alive_1");
	game->collectible_imgs[1] = create_img(game, "collectible_2");
	game->collectible_imgs[2] = create_img(game, "collectible_3");
	game->collectible_imgs[3] = create_img(game, "collectible_4");
	game->collectible_imgs[4] = create_img(game, "collectible_dead_1");
}

void	setup_img(t_game *game)
{
	setup_img_collectibles(game);
	setup_img_player(game);
	setup_img_exit(game);
	game->wall_imgs = ft_calloc(13, sizeof(t_img *));
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
}
