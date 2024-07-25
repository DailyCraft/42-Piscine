/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:45:52 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 07:53:57 by dvan-hum         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
#include <stdio.h>
int main()
{
    printf("-6: %d\n", ft_find_next_prime(-6));
	printf("2: %d\n", ft_find_next_prime(2));
	printf("3: %d\n", ft_find_next_prime(3));
	printf("4: %d\n", ft_find_next_prime(4));
	printf("5: %d\n", ft_find_next_prime(5));
	printf("2 147 458 172: %d", ft_find_next_prime(2147458172));
}*/