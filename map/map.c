/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:15:17 by dabalm            #+#    #+#             */
/*   Updated: 2023/12/09 17:10:37 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_line(char *line)
{
	int	i;
	static int has_player = 0;
	static int has_exit = 0;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01CEP", line[i]))
			return (0);
		if (line[i] == 'P' && has_player)
			return (0);
		if (line[i] == 'P')
			has_player = 1;
		if (line[i] == 'E' && has_exit)
			return (0);
		if (line[i] == 'E')
			has_exit = 1;
		i++;
	}
	return (1);
}


/**

	* @returns height of map or 0 if not rectangular or if it has invalid characters
*/
int	get_map_height(char *file)
{
	struct s_map	map;
	char			*line;
	int				i;

	map.fd = open(file, O_RDONLY);
	line = get_next_line(map.fd);
	map.width = -1;
	map.height = 0;
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (map.width == -1)
			map.width = i;
		else if (map.width != i || !is_valid_line(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(map.fd);
		map.height++;
	}
	return (map.height);
}

t_map	*create_map(char *file)
{
	t_map	*map;
	char	*line;
	int		i;

	map = malloc(sizeof(t_map));
	map->height = get_map_height(file);
	if (!map->height)
	{
		free(map);
		ft_printf("invalid map\n");
		return (NULL);
	}
	map->matrix = ft_calloc(map->height + 1, sizeof(char *));
	map->fd = open(file, O_RDONLY);
	line = get_next_line(map->fd);
	i = 0;
	while (line)
	{
		map->matrix[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
		line = get_next_line(map->fd);
	}
	map->width = ft_strlen(map->matrix[0]);
	return (map);
}
