/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:51:56 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 13:55:37 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("-3: %d\n", ft_sqrt(-3));
	printf("0: %d\n", ft_sqrt(0));
	printf("1: %d\n", ft_sqrt(1));
	printf("2: %d\n", ft_sqrt(2));
	printf("9: %d\n", ft_sqrt(9));
	printf("2 145 542 400: %d\n", ft_sqrt(2145542400));
}*/