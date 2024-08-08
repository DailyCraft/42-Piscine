/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:02:54 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/08 16:34:21 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include <stdlib.h>

int		ft_strlen(char *str);
size_t	ft_atollu(char *str, int *err);
size_t	get_min(size_t a, size_t b);
void	print_errno(void);
int		check_file(int file, char *path, int file_args, int is_first_file);
void	no_args(size_t bytes);

size_t	get_bytes(int ac, char **av, int *options_count, int *err)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == 'c')
		{
			if (av[i][2] == 0)
			{
			}
			else
			{
			}
			result = ft_atollu(av[i] + 2, err);
			if (*err)
				return (0);
			(*options_count)++;
		}
		i++;
	}
	return (result);
}

size_t	compute_size(char *path)
{
	int		file;
	char	buf[1024];
	int		count;
	size_t	size;

	file = open(path, O_RDONLY);
	count = read(file, buf, 1024);
	size = count;
	while (count > 0)
	{
		count = read(file, buf, 1024);
		size += count;
	}
	close(file);
	return (size);
}

int	read_file(size_t bytes, char *path, int file_args, int is_first_file)
{
	int		file;
	size_t	total_size;
	int		count;
	char	*buf;

	buf = malloc(bytes);
	total_size = compute_size(path) - bytes;
	file = open(path, O_RDONLY);
	if (!check_file(file, path, file_args, is_first_file))
	{
		free(buf);
		return (0);
	}
	errno = 0;
	while (total_size > 0)
		total_size -= read(file, buf, get_min(bytes, total_size));
	count = read(file, buf, bytes);
	(void) count;
	write(1, buf, count);
	close(file);
	free(buf);
	return (1);
}

void	read_args(char *arg, size_t bytes, int file_args)
{
	static int	is_first_file = 1;
	int			read_file_result;

	if (arg[0] != '-' && arg[1] != 'c')
	{
		read_file_result = read_file(get_min(bytes, compute_size(arg)),
				arg, file_args, is_first_file);
		if (!read_file_result)
			return ;
		else
			is_first_file = 0;
	}
}

int	main(int argc, char **argv)
{
	size_t	bytes;
	int		i;
	int		options_count;
	int		err;

	options_count = 0;
	err = 0;
	bytes = get_bytes(argc, argv, &options_count, &err);
	if (!err)
	{
		if (bytes == 0)
			return (0);
		if (argc < 3)
		{
			no_args(bytes);
			return (0);
		}
		i = 0;
		while (++i < argc)
			read_args(argv[i], bytes, argc - 1 - options_count);
	}
	return (0);
}
