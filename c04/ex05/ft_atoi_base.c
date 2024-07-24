/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:22:47 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 10:07:18 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nb, int pow)
{
	int	result;

	if (pow == 0)
		return (1);
	result = nb;
	while (pow > 1)
	{
		result *= nb;
		pow--;
	}
	return (result);
}

char	*skip_useless(char str[], int *is_negative)
{
	int	i;
	int	condition;

	*is_negative = 0;
	i = 0;
	while (str[i] != 0)
	{
		condition = (str[i] != '\t' && str[i] != '\n' && str[i] != '\v');
		condition = (condition && str[i] != '\f' && str[i] != '\r');
		condition = (condition && str[i] != ' ');
		if (condition)
			break ;
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_negative = *is_negative == 0;
		i++;
	}
	return (str + i);
}

int	index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	check_base_and_str_len(char *base, char *str, int *length)
{
	int	i;

	i = 0;
	length[0] = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			length[0] = -1;
		if (index_of(base, base[i]) != i)
			length[0] = -1;
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			length[0] = -1;
		i++;
	}
	if (length[0] != -1)
		length[0] = i;
	i = 0;
	while (index_of(base, str[i]) != -1)
		i++;
	length[1] = i;
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	result;
	int	is_negative;
	int	lengths[2];

	result = 0;
	str = skip_useless(str, &is_negative);
	check_base_and_str_len(base, str, lengths);
	if (lengths[0] < 2)
		return (0);
	i = 0;
	j = index_of(base, str[i]);
	while (j != -1)
	{
		result += j * ft_pow(lengths[0], lengths[1] - i - 1);
		i++;
		j = index_of(base, str[i]);
	}
	if (is_negative)
		result *= -1;
	return (result);
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