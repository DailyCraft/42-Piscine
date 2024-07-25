/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:39:54 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 07:53:40 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
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