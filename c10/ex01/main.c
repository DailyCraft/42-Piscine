/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:08:11 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/08 16:27:57 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

void	print_error(char *bin, char *path)
{
	char	*err;

	write(2, bin, ft_strlen(bin));
	write(2, ": ", 2);
	write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	err = strerror(errno);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}

void	print_file(char *bin, char *path)
{
	int		file;
	char	buf[1024];
	int		count;

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		print_error(bin, path);
		return ;
	}
	count = read(file, buf, 1024);
	while (count > 0)
	{
		write(1, buf, count);
		count = read(file, buf, 1024);
	}
	if (count == -1)
	{
		print_error(bin, path);
		return ;
	}
	close(file);
}

void	no_args(void)
{
	char	buf[1024];
	int		count;

	count = read(0, buf, 1024);
	while (count > 0)
	{
		write(1, buf, count);
		count = read(0, buf, 1024);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			print_file(basename(argv[0]), argv[i]);
			i++;
		}
	}
	else
		no_args();
	return (0);
}
