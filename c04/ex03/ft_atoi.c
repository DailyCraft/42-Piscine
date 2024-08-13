/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:48:48 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 16:17:05 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	neg;

	result = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * neg);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("             \n	-----+--++++---++---+42qwe478"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483648"));
	printf("%d\n", ft_atoi("200000000000000000000"));
	printf("%d\n", ft_atoi(" - -42"));
}*/
