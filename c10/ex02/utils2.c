/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:25:34 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/08 16:01:41 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void	print_errno(void);
int		ft_strlen(char *str);

void	write_file_name(int is_first_file, char *path)
{
	if (!is_first_file)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, path, ft_strlen(path));
	write(1, " <==\n", 5);
}

int	check_file(int file, char *path, int file_args, int is_first_file)
{
	if (file == -1)
	{
		if (errno == 2 || errno == 13)
		{
			write(2, "tail: cannot open '", 19);
			write(2, path, ft_strlen(path));
			write(2, "' for reading: ", 15);
			print_errno();
		}
		write(2, "\n", 1);
		return (0);
	}
	else if (file_args > 1)
		write_file_name(is_first_file, path);
	if (errno == 21)
	{
		write(2, "tail: error reading '", 21);
		write(2, path, ft_strlen(path));
		write(2, "': ", 3);
		print_errno();
		write(2, "\n", 1);
	}
	return (1);
}

char	*ft_strncpy(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_realloc(char *buf, char c, size_t *size, size_t max_size)
{
	char	*result;

	if (*size < max_size)
	{
		(*size)++;
		result = malloc(*size);
		ft_strncpy(result, buf, *size - 1);
	}
	else
	{
		result = malloc(*size);
		ft_strncpy(result, buf + 1, *size - 1);
	}
	result[*size - 1] = c;
	free(buf);
	return (result);
}

void	no_args(size_t bytes)
{
	char	*buf;
	size_t	size;
	char	c;

	size = 0;
	buf = malloc(1);
	while (read(0, &c, 1) > 0)
		buf = ft_realloc(buf, c, &size, bytes);
	write(1, buf, size);
	free(buf);
}
