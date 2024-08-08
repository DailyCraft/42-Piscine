/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:38:21 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/07 00:47:10 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	populate_map_walls(t_map *map, int count)
{
	int	x;
	int	y;

	map->walls = malloc((map->height) * sizeof(int *));
	map->wall_count = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->slots[(map->width + 1) * y + x] == map->wall)
			{
				map->wall_count++;
				count++;
			}
		}
		map->walls[y] = malloc((count + 1) * sizeof(int));
		x = -1;
		count = 0;
		while (++x < map->width)
			if (map->slots[(map->width + 1) * y + x] == map->wall)
				map->walls[y][count++] = x;
		map->walls[y][count] = -1;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->walls[i]);
	free(map->slots);
	free(map->walls);
}
