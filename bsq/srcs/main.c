/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:42:40 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/07 11:18:01 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	return_error(int fd)
{
	write(2, "map error\n", 10);
	close(fd);
	return (1);
}

int	process(char *path)
{
	int			fd;
	t_map		map;
	t_square	square;

	if (path == NULL)
		fd = STDIN_FILENO;
	else
		fd = open(path, O_RDONLY);
	if (get_map_info(fd, &map))
		return (return_error(fd));
	if (ft_fill_slots(&map, fd))
	{
		free(map.slots);
		return (return_error(fd));
	}
	populate_map_walls(&map, 0);
	square = solve(&map);
	print(&map, &square);
	if (fd >= 1)
	{
		close(fd);
		free_map(&map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (process(NULL));
	i = 0;
	while (++i < argc)
	{
		process(argv[i]);
		if (i != (argc - 1))
			write(1, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
