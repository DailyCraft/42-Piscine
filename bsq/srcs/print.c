/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:07:07 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/06 23:18:16 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print(t_map *map, t_square *s)
{
	int			x;
	int			y;

	y = 0;
	while (y < s->size)
	{
		x = 0;
		while (x < s->size)
		{
			map->slots[(map->width + 1) * (y + s->y) + (x + s->x)] = map->fill;
			x++;
		}
		y++;
	}
	write(1, map->slots, map->height * (map->width + 1));
}
