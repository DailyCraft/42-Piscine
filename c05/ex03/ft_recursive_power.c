/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:33:33 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 07:54:31 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int main() {
	printf("%d - 8\n", ft_recursive_power(2, 3));
	printf("%d - 1\n", ft_recursive_power(0, 0));
	printf("%d - 1\n", ft_recursive_power(2, 0));
	printf("%d - 0\n", ft_recursive_power(0, 3));
	printf("%d - 81\n", ft_recursive_power(3, 4));
	printf("%d - 0", ft_recursive_power(3, -5));
}*/
