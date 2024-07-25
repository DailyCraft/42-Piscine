/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:24:58 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/21 17:31:17 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>
int main() {
	printf("%d - 8\n", ft_iterative_power(2, 3));
	printf("%d - 1\n", ft_iterative_power(0, 0));
	printf("%d - 1\n", ft_iterative_power(2, 0));
	printf("%d - 0\n", ft_iterative_power(0, 3));
	printf("%d - 81\n", ft_iterative_power(3, 4));
	printf("%d - 0", ft_iterative_power(3, -5));
}*/
