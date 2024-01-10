/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:24:07 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:17:03 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# define VIEW_HEIGHT 4
# define VIEW_WIDTH 4

# define F_VIEW_HEIGHT 5
# define F_VIEW_WIDTH 5

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				endian;
	int				line_length;
	int				x;
	int				y;
}					t_img;

typedef struct s_hitbox
{
	t_position		topright;
	t_position		topleft;
	t_position		bottomright;
	t_position		bottomleft;
}					t_hitbox;

typedef struct s_player
{
	int				x;
	int				y;
	char			direction;
	int				move;
	int				moving;
	int				distance_moved;
	t_hitbox		*hitbox;
	t_img			*img;
}					t_player;

typedef struct s_collectible
{
	t_position		position;
	int				frame;
	int				dead;
	t_hitbox		hitbox;
}					t_collectible;

typedef struct s_map
{
	int				width;
	int				height;
	int				fd;
	char			**matrix;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_map			*map;
	int				size;
	t_player		*player;
	t_collectible	**collectibles;
	t_collectible	*exit;
	t_img			***player_imgs;
	t_img			**collectible_imgs;
	t_img			*floor_img;
	t_img			**wall_imgs;
	t_img			*item_img;
	t_img			**exit_imgs;
	t_img			*frame;
	float			move_distance;
}					t_game;

int					get_map_height(char *file);
int					do_move(t_game *game);
void				pixel_put(t_game *game, int x, int y, int color);

// player
int					can_move_up(t_game *game);
int					can_move_down(t_game *game);
int					can_move_left(t_game *game);
int					can_move_right(t_game *game);
void				kill_coll(t_game *game, t_position *pos1, t_position *pos2);
void				use_exit(t_game *game);

// setup
void				setup_img(t_game *game);
void				setup_collectibles(t_game *game);
void				setup_exit(t_game *game);
void				setup_player(t_game *game);
t_game				*setup(int argc, char *argv[]);
void				setup_sigint(t_game *game);

// map
int					get_map_height(char *file);
void				check_paths(t_map *map);
t_map				*create_map(char *file);

// render
void				put_img(t_game *game, t_img *img, double x, double y);
int					render(t_game *game);
void				add_wall_above(t_game *game);
void				add_wall_beneath(t_game *game);
void				add_wall_left(t_game *game);
void				add_wall_right(t_game *game);
void				add_collectibles(t_game *game);
void				add_exit(t_game *game);
void				get_hitbox(t_game *game);
void				add_one_wall_above(t_game *game, int x, int y,
						t_position *pos);
void				add_one_wall_beneath(t_game *game, int x, int y,
						t_position *pos);
void				add_one_wall_left(t_game *game, int x, int y,
						t_position *pos);
void				add_one_wall_right(t_game *game, int x, int y,
						t_position *pos);
// free
void				*free_all(t_game *game, char *msg);
void				free_imgs(t_game *game);
void				free_map(t_map *map);

#endif