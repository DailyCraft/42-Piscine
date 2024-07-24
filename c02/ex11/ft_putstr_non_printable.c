/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:27:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 08:39:26 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*display_hexa(char *letter)
{
	if (*letter < 10)
		*letter += '0';
	else
		*letter += 'a' - 10;
	return (letter);
}

void	write_hexa(char c)
{
	char	letter;

	write(1, "\\", 1);
	letter = c >> 4 & 0xf;
	write(1, display_hexa(&letter), 1);
	letter = c & 0xf;
	write(1, display_hexa(&letter), 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
			write_hexa(str[i]);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	//ft_putstr_non_printable("Coucou\ntu vas bien ?");
	//ft_putstr_non_printable("\x2d");
	//ft_putstr_non_printable("\200");
	ft_putstr_non_printable("\x80");
	return (0);
}*/