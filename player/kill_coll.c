/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_coll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:39:45 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/09 18:44:46 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void set_hitboxes(t_game *game)
{
    t_collectible *coll;
    int i;

    i = 0;
    while (game->collectibles[i])
    {
        coll = game->collectibles[i];
        coll->hitbox.topleft.x = coll->position.x - (game->size / 4);
        coll->hitbox.topleft.y = coll->position.y - (game->size / 4);
        coll->hitbox.topright.x = coll->position.x + (game->size / 4);
        coll->hitbox.topright.y = coll->position.y - (game->size / 4);
        coll->hitbox.bottomleft.x = coll->position.x - (game->size / 4);
        coll->hitbox.bottomleft.y = coll->position.y + (game->size / 4);
        coll->hitbox.bottomright.x = coll->position.x + (game->size / 4);
        coll->hitbox.bottomright.y = coll->position.y + (game->size / 4);
        i++;
    }
}

static t_collectible *get_coll(t_game *game, t_position *pos)
{
    t_collectible *coll;
    int i;

    i = 0;
    while (game->collectibles[i])
    {
        coll = game->collectibles[i];
        if (
            pos->x > coll->hitbox.bottomleft.x &&
            pos->x < coll->hitbox.bottomright.x &&
            pos->y < coll->hitbox.bottomleft.y &&
            pos->y > coll->hitbox.topleft.y
        ){
            ft_printf("i: %d;\n", i);
            return coll;
        }
        i++;
    }
    return NULL;
}

void use_exit(t_game *game)
{
    ft_printf("leave\n");
    ft_printf("game->exit->hitbox.bottomleft.x: %d;\n", game->exit->hitbox.bottomleft.x);
    ft_printf("game->exit->hitbox.bottomright.x: %d;\n", game->exit->hitbox.bottomright.x);
    ft_printf("game->exit->hitbox.bottomleft.y: %d;\n", game->exit->hitbox.bottomleft.y);
    ft_printf("game->exit->hitbox.topleft.y: %d;\n", game->exit->hitbox.topleft.y);
    ft_printf("game->player->x: %d;\n", game->exit->hitbox.bottomleft.x);
    ft_printf("game->player->y: %d;\n", game->exit->hitbox.bottomright.x);
    if (
        game->exit->dead &&
        game->player->x > game->exit->hitbox.bottomleft.x &&
        game->player->x < game->exit->hitbox.bottomright.x &&
        game->player->y < game->exit->hitbox.bottomleft.y &&
        game->player->y > game->exit->hitbox.topleft.y
    ){
        ft_printf("good job champ");
        exit(1);
    }
}

int all_dead(t_game *game)
{
    int i;

    i = 0;
    while(game->collectibles[i] && game->collectibles[i]->dead)
        i++;
    return !game->collectibles[i];
}

void kill_coll(t_game *game, t_position *pos1, t_position *pos2)
{
    t_collectible *coll1;
    t_collectible *coll2;
    set_hitboxes(game);

    coll1 = get_coll(game, pos1);
    coll2 = get_coll(game, pos2);
    
    if (coll1)
        coll1->dead = 1;
    if (coll2)
        coll2->dead = 1;
    if ((coll1 || coll2) && all_dead(game))
    {
        ft_printf("all clear\n");
        game->exit->dead = 1;
    }
}
