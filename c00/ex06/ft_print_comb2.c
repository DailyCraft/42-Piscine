/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:17 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 14:42:15 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int comb)
{
	char	c;

	c = comb / 10 + '0';
	write(1, &c, 1);
	c = comb % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;
	int	is_first_write;

	is_first_write = 1;
	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			if (!is_first_write)
				write(1, ", ", 2);
			is_first_write = 0;
			print_comb(first);
			write(1, " ", 1);
			print_comb(second);
			second++;
		}
		first++;
	}
}
