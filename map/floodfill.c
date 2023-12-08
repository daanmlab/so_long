/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:31:41 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/28 14:33:35 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**create_been_matrix(t_map *map)
{
	int	**been;
	int	i;

	been = ft_calloc(map->height, sizeof(int *));
	if (!been)
		ft_printf("Handle create_been_matrix");
	i = 0;
	while (i < map->height)
	{
		been[i] = ft_calloc(map->width, sizeof(int));
		i++;
	}
	return (been);
}

/**
 * @details goes through entire map and fills been,
	also exits program when it hits the side of the map
*/
void	floodfill(t_map *map, int **been, int x, int y)
{
	if (map->matrix[y][x] == '1' || been[y][x] == 1)
		return ;
	if (x <= 0 || y <= 0 || x >= map->width - 1 || y >= map->height - 1)
	{
		ft_printf("invalid map\n");
		exit(1);
	}
	been[y][x] = 1;
	floodfill(map, been, x + 1, y);
	floodfill(map, been, x - 1, y);
	floodfill(map, been, x, y + 1);
	floodfill(map, been, x, y - 1);
}

void	check_coll_and_exit(t_map *map, int **been)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((map->matrix[y][x] == 'E' || map->matrix[y][x] == 'C')
				&& been[y][x] == 0)
			{
				ft_printf("handle invalid map");
				exit(1);
			}
			if (map->matrix[y][x] == '0' && been[y][x] == 0)
				map->matrix[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	free_been_matrix(int **been, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(been[i]);
		i++;
	}
	free(been);
}

void	check_paths(t_map *map)
{
	int	**been;
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] == 'P')
				break ;
			x++;
		}
		if (map->matrix[y][x] == 'P')
			break ;
		y++;
	}
	been = create_been_matrix(map);
	floodfill(map, been, x, y);
	check_coll_and_exit(map, been);
	free_been_matrix(been, map);
}
