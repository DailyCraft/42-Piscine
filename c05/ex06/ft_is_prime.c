/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:42:27 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 14:03:55 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb != 2 && nb % 2 == 0)
		return (0);
	i = 3;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
    printf("-1: %d\n", ft_is_prime(-1));
	printf("0: %d\n", ft_is_prime(0));
	printf("1: %d\n", ft_is_prime(1));
	printf("2: %d\n", ft_is_prime(2));
	printf("3: %d\n", ft_is_prime(3));
	printf("4: %d\n", ft_is_prime(4));
	printf("5: %d\n", ft_is_prime(5));
	printf("6: %d\n", ft_is_prime(6));
	printf("7: %d\n", ft_is_prime(7));
	printf("17: %d\n", ft_is_prime(17));
	printf("48: %d\n", ft_is_prime(48));
	printf("7 919: %d\n", ft_is_prime(7919));
	printf("2 147 483 647: %d\n", ft_is_prime(2147483647));
}*/
