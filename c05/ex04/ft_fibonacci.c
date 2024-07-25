/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:40:56 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 07:54:48 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int main()
{
	printf("-3: %d\n", ft_fibonacci(-3));
	printf("0: %d\n", ft_fibonacci(0));
	printf("1: %d\n", ft_fibonacci(1));
	printf("2: %d\n", ft_fibonacci(2));
	printf("3: %d\n", ft_fibonacci(3));
	printf("4: %d\n", ft_fibonacci(4));
	printf("5: %d\n", ft_fibonacci(5));
	printf("10: %d\n", ft_fibonacci(10));
}*/