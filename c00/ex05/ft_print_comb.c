/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:57:19 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 14:24:34 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];
	int		is_first_write;

	is_first_write = 1;
	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				if (!is_first_write)
					write(1, ", ", 2);
				is_first_write = 0;
				write(1, comb, 3);
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
/*
int main()
{
	ft_print_comb();
}*/
