/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:46:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/07 11:40:30 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_empty_high_density(t_map *map, int size, int tx, int ty)
{
	int	i;
	int	j;

	i = size - 1;
	while (i >= 0)
	{
		j = i;
		while (j >= 0)
		{
			if (map->slots[(ty + i) * (map->width + 1) + (tx + j)] == map->wall)
				return (j);
			if (map->slots[(ty + j) * (map->width + 1) + (tx + i)] == map->wall)
				return (i);
			j--;
		}
		i--;
	}
	return (-1);
}

int	is_empty_low_density(t_map *map, t_square *square)
{
	int	y;
	int	i;

	y = square->y;
	while (y < square->y + square->size)
	{
		i = 0;
		while (map->walls[y][i] != -1
			&& map->walls[y][i] < square->x + square->size)
		{
			if (map->walls[y][i] >= square->x)
				return (map->walls[y][i]);
			i++;
		}
		y++;
	}
	return (-1);
}

int	find_empty_space(t_map *map, t_square *square)
{
	int	wall;

	square->y = 0;
	while (square->y <= map->height - square->size)
	{
		square->x = 0;
		while (square->x <= map->width - square->size)
		{
			wall = is_empty_low_density(map, square);
			if (wall == -1)
				return (1);
			square->x = wall + 1;
		}
		square->y++;
	}
	return (0);
}

void	ultimate_solve(t_map *map, t_square *square)
{
	int			size;
	int			x;
	int			y;

	ft_reset_square(square, -1);
	y = -1;
	while (++y <= map->height - (square->size + 1))
	{
		x = -1;
		while (++x <= map->width - (square->size + 1))
		{
			size = square->size + 1;
			while ((size + x) <= map->width
				&& (size + y) <= map->height
				&& is_empty_high_density(map, size, x, y) == -1)
			{
				square->size = size++;
				square->x = x;
				square->y = y;
			}
		}
	}
	if (square->x == -1)
		ft_reset_square(square, 0);
}

t_square	solve(t_map *map)
{
	t_square	square;

	if (map->wall_count < map->height * map->width / 160)
	{
		square.size = get_min(map->width, map->height);
		while (!find_empty_space(map, &square))
			square.size--;
	}
	else
		ultimate_solve(map, &square);
	return (square);
}
