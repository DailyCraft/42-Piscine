/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:17 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/17 16:04:49 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	plus_combs(char comb1[], char comb2[])
{
	if (comb2[1] < '9')
		comb2[1]++;
	else
	{
		comb2[1] = '0';
		if (comb2[0] < '9')
			comb2[0]++;
		else
		{
			comb2[0] = '0';
			if (comb1[1] < '9')
				comb1[1]++;
			else
			{
				comb1[1] = '0';
				comb1[0]++;
			}
		}
	}
}

void	ft_print_comb2(void)
{
	char	comb1[2];
	char	comb2[2];

	comb1[0] = '0';
	comb1[1] = '0';
	comb2[0] = '0';
	comb2[1] = '1';
	while (comb1[0] != '9' || comb1[1] != '8'
		|| comb2[0] != '9' || comb2[1] != '9')
	{
		if (comb1[0] * 10 + comb1[1] < comb2[0] * 10 + comb2[1])
		{
			write(1, comb1, 2);
			write(1, " ", 1);
			write(1, comb2, 2);
			write(1, ", ", 2);
		}
		plus_combs(comb1, comb2);
	}
	write(1, "98 99", 5);
}
