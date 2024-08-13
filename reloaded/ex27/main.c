/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:59:18 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 15:06:21 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	read_file(char *path)
{
	int		file;
	char	buf[1024];
	int		size;

	file = open(path, O_RDONLY);
	size = read(file, buf, 1024);
	write(1, buf, size);
	while (size > 0)
	{
		size = read(file, buf, 1024);
		write(1, buf, size);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		read_file(argv[1]);
}
