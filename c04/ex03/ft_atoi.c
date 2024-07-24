/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:48:48 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 11:08:22 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (is_negative)
		result *= -1;
	return (result);
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
