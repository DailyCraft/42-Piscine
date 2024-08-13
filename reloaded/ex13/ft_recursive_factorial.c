/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:48:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 13:51:23 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_factorial(-2));
	printf("%d\n", ft_recursive_factorial(0));
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(3));
}*/