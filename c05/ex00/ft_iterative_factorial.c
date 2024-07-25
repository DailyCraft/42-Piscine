/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:10:01 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 07:48:07 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	value;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	value = nb;
	nb--;
	while (nb > 1)
	{
		value *= nb;
		nb--;
	}
	return (value);
}
/*
#include <stdio.h>

int main()
{
	printf("%d", ft_iterative_factorial(3));
}*/
