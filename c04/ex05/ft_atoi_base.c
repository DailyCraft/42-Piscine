/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:22:47 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 17:03:18 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (-1);
		if (index_of(base, base[i]) != i)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_length;
	int	result;
	int	neg;

	base_length = check_base(base);
	if (base_length < 2)
		return (0);
	result = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (index_of(base, str[i]) != -1)
	{
		result = result * base_length + index_of(base, str[i]);
		i++;
	}
	return (result * neg);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi_base(" \n	-+--101010", "01"));
	printf("%d\n", ft_atoi_base("-2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("7FFFFFFF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-80000000", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("- -5", "0123456789"));
	printf("%d\n", ft_atoi_base("42", "012\n3456789"));
	printf("%d\n", ft_atoi_base("42", "012+3456789"));
	printf("%d\n", ft_atoi_base("42", "0123456799"));
	printf("%d\n", ft_atoi_base("42", "0"));
	printf("%d\n", ft_atoi_base("42", ""));
}*/