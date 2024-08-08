/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:42:09 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/07 10:45:38 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

void	err(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	read_file(char *path)
{
	int		file;
	char	buf[1024];
	int		count;

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		err("Cannot read file.");
		return ;
	}
	count = read(file, buf, 1024);
	while (count > 0)
	{
		write(1, buf, count);
		count = read(file, buf, 1024);
	}
	if (count == -1)
		err("Cannot read file.");
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		err("File name missing.");
	else if (argc > 2)
		err("Too many arguments.");
	else
		read_file(argv[1]);
}
