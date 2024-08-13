/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:27:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 15:52:33 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	to_hexa(char digit)
{
	if (digit < 10)
		return (digit + '0');
	else
		return (digit - 10 + 'a');
}

void	write_hexa(char c)
{
	char	hexa[2];

	write(1, "\\", 1);
	hexa[0] = to_hexa(c >> 4 & 0xf);
	hexa[1] = to_hexa(c & 0xf);
	write(1, hexa, 2);
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
int	main()
{
	//ft_putstr_non_printable("Coucou\ntu vas bien ?");
	//ft_putstr_non_printable("\x2d");
	//ft_putstr_non_printable("\200");
	ft_putstr_non_printable("\x80");
	return (0);
}*/