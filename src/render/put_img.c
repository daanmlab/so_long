/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:40:31 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/20 15:39:26 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned int	*pixel_get(t_img *img, int x, int y)
{
	return ((unsigned int *)((img->addr) + (y * img->line_length + x
			* (img->bits_per_pixel / 8))));
}

void	pixel_put(t_game *game, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(game->frame->addr + (y * game->frame->line_length + x
				* (game->frame->bits_per_pixel / 8)));
	*dst = color;
}

void	put_img(t_game *game, t_img *img, double x, double y)
{
	int				i;
	int				j;
	unsigned int	*temp;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			temp = pixel_get(img, j, i);
			if (*temp != 0xff000000)
				pixel_put(game, x + j, y + i, *(temp));
			j++;
		}
		i++;
	}
}
