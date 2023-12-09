/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:46:52 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/09 18:45:20 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void get_exit_position(t_game *game, t_position *pos)
{
    
    if ((pos->x + 1) == game->map->width)
    {
        pos->x = 0;
        pos->y++;
    } else
        pos->x++;
    while (pos->y < game->map->height)
    {
        while (pos->x < game->map->width)
        {
            if (game->map->matrix[pos->y][pos->x] == 'E')
                return ;
            pos->x++;
        }
        pos->x = 0;
        pos->y++;
    }
}

t_collectible *create_exit(t_game *game, int y, int x)
{
    t_collectible *coll;

    (void)game;
    coll = malloc(sizeof(t_collectible));
    if (!coll)
        return NULL;
    coll->position.y = y;
    coll->position.x = x;
    coll->dead = 0;
    coll->frame = 0;
    return coll;
}

static void set_hitbox(t_game *game)
{
    game->exit->hitbox.topleft.x = game->exit->position.x - (game->size / 4);
    game->exit->hitbox.topleft.y = game->exit->position.y;
    game->exit->hitbox.topright.x = game->exit->position.x + (game->size / 4);
    game->exit->hitbox.topright.y = game->exit->position.y;
    game->exit->hitbox.bottomleft.x = game->exit->position.x - (game->size / 4);
    game->exit->hitbox.bottomleft.y = game->exit->position.y + (game->size / 2);
    game->exit->hitbox.bottomright.x = game->exit->position.x + (game->size / 4);
    game->exit->hitbox.bottomright.y = game->exit->position.y + (game->size / 2);
}

void setup_exit(t_game *game)
{
    int temp;
    game->exit = create_exit(game, 0, 0);
    get_exit_position(game, &(game->exit->position));

    srand(rand() + game->map->height / game->map->width + game->size + game->player->x);
    if (game->map->matrix[game->exit->position.y + 1][game->exit->position.x] == '1')
        temp = 0;
    else
        temp = (rand() % (game->size - (game->size / 4))) ;
    game->exit->position.x *= game->size;
    game->exit->position.y *= game->size;
    game->exit->position.x += (rand() % (2 * (game->size / 3))) + (game->size / 6);
    game->exit->position.y += temp;
    set_hitbox(game);
}
