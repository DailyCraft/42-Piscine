/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:59:08 by gakarbou          #+#    #+#             */
/*   Updated: 2024/08/05 20:23:22 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*get_first_line(int fd)
{
	char	c;
	char	*dest;

	dest = malloc(1);
	dest[0] = 0;
	while (read(fd, &c, sizeof(c)))
	{
		if (c == '\n')
			break ;
		dest = ft_realloc(dest, c);
	}
	return (dest);
}

void	mini_atoi(t_map *map, char *line, char *err)
{
	int	len;
	int	i;

	i = -1;
	map->height = 0;
	len = ft_strlen(line);
	while (++i < (len - 3))
	{
		if (line[i] < '0' || line[i] > '9')
			*err = 1;
		map->height = map->height * 10 + (line[i] - 48);
	}
	map->empty = line[i];
	map->wall = line[i + 1];
	map->fill = line[i + 2];
	if (line[i] == line[i + 1] || line[i] == line[i + 2]
		|| line[i + 1] == line[i + 2])
		*err = 1;
	while (i < len)
		if (!ft_char_is_printable(line[i++]))
			*err = 1;
	if (map->height == 0)
		*err = 1;
}

char	get_map_info(int fd, t_map *map)
{
	char	*first_line;
	char	err;

	err = 0;
	if (fd < 0)
		err = 1;
	if (!err)
	{
		first_line = get_first_line(fd);
		mini_atoi(map, first_line, &err);
		free(first_line);
	}
	return (err);
}
