/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:57:19 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 18:32:03 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb_plus(char comb[])
{
	if (comb[2] < '9')
		comb[2]++;
	else
	{
		comb[2] = '0';
		if (comb[1] < '9')
			comb[1]++;
		else
		{
			comb[1] = '0';
			comb[0]++;
		}
	}
}

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	comb[1] = '1';
	comb[2] = '2';
	while (comb[0] < '7' || (comb[0] == '7' && comb[1] < '8' && comb[2] < '9'))
	{
		if (comb[0] < comb[1] && comb[1] < comb[2])
		{
			write(1, &comb, 3);
			write(1, ", ", 2);
		}
		comb_plus(comb);
	}
	write(1, "789", 3);
}
/*
int main()
{
	ft_print_comb();
}*/
