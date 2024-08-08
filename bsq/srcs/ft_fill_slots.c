/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_slots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:05:11 by gakarbou          #+#    #+#             */
/*   Updated: 2024/08/07 22:48:48 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_ultimate_realloc(char *addr, int size)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < (size - 10000))
		dest[i] = addr[i];
	return (dest);
}

char	*ft_get_first_row(int fd, t_map *map)
{
	char	*buffer;
	int		i;
	int		count;
	char	c;

	count = 1;
	buffer = malloc(10000 * sizeof(char));
	i = -1;
	while (read(fd, &buffer[++i], 1))
	{
		if ((i % 10001) == 10000)
		{
			c = buffer[i];
			buffer = ft_ultimate_realloc(buffer, 10000 * ++count);
			buffer[i] = c;
		}
		if (buffer[i] == '\n')
			break ;
	}
	map->width = i;
	buffer[i + 1] = 0;
	return (buffer);
}

int	see_error(t_map *map)
{
	int	i;
	int	size;

	if (map->width == 0)
		return (1);
	i = -1;
	size = map->height * (map->width + 1);
	while (++i < size)
	{
		if ((i % (map->width + 1)) == map->width)
		{
			if (map->slots[i] != '\n')
				return (1);
		}
		else
			if (map->slots[i] != map->empty
				&& map->slots[i] != map->wall)
				return (1);
	}
	return (0);
}

void	ft_str_add_temp(t_map *map, char *src)
{
	int	i;

	i = -1;
	while (++i < (map->width + 1))
		map->slots[i] = src[i];
}

int	ft_fill_slots(t_map *m, int fd)
{
	int		err;
	int		s;
	char	*temp;

	err = 0;
	temp = ft_get_first_row(fd, m);
	m->slots = malloc((2 + m->height * (m->width + 1)) * sizeof(char));
	s = read(fd, m->slots + m->width + 1, (m->width + 1) * (m->height - 1));
	m->slots[s + (m->width + 1)] = 0;
	ft_str_add_temp(m, temp);
	m->slots[((m->width + 1) * m->height) + 1] = 0;
	s = read(fd, temp, 1);
	free(temp);
	if (see_error(m))
		return (1);
	if (err == 1 || s)
		return (1);
	return (0);
}
