/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:38:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/08 09:30:59 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

char	*ft_strncpy(char *dest, char *src, int nb);
int		ft_strncmp(char *s1, char *s2, int nb);

void	print_hex(int nbr, int length)
{
	char	c;

	c = nbr >> (4 * (length - 1)) & 0xf;
	if (c > 9)
		c += 'a' - 10;
	else
		c += '0';
	write(1, &c, 1);
	if (length > 1)
		print_hex(nbr, length - 1);
}

void	print_line(int total_count, char *line, int max, int is_c)
{
	int	i;

	print_hex(total_count, 7 + is_c);
	i = 0;
	write(1, "  ", 1 + is_c);
	while (i < 16)
	{
		if (i < max)
		{
			if (is_c)
				print_hex(line[i], 2);
			else if (i % 2 == 0)
			{
				if (i + 1 < max)
				{
					print_hex(line[i] | (line[i + 1] << 8), 4);
				}
				else
					print_hex(line[i], 4);
			}
		}
		else
			write(1, "  ", 2);
		if ((is_c || i % 2 == 1) && i != 15)
			write(1, " ", 1);
		if ((i == 7 || i == 15) && is_c)
			write(1, " ", 1);
		i++;
	}
	if (is_c)
	{
		write(1, " |", 2);
		i = 0;
		while (i < max)
		{
			if (line[i] >= 32 && line[i] <= 126)
				write(1, line + i, 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "|", 1);
	}
	write(1, "\n", 1);
}

void	add_to_line(char c, int end, int is_c)
{
	static int	total_count = 0;
	static char	old_line[16] = {};
	static char	line[16] = {};
	static int	current = 0;
	static int	printed_star = 0;

	if (!end)
	{
		line[current] = c;
		current++;
	}
	if (current < 16 && !end)
		return ;
	if (ft_strncmp(old_line, line, current) == 0)
	{
		if (!printed_star)
		{
			write(1, "*\n", 2);
			printed_star = 1;
		}
	}
	else
	{
		print_line(total_count * 16, line, current, is_c);
		printed_star = 0;
	}
	if (end)
	{
		print_hex(total_count * 16 + current, 7 + is_c);
		write(1, "\n", 1);
	}
	total_count++;
	ft_strncpy(old_line, line, 16);
	current = 0;
}

void	read_file(char *path, int is_c)
{
	int		file;
	char	buf[1];

	file = open(path, O_RDONLY);
	while (read(file, buf, 1) > 0)
	{
		add_to_line(buf[0], 0, is_c);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		read_file(argv[i], 1);
		i++;
	}
	add_to_line(0, 1, 1);
	return (0);
}
