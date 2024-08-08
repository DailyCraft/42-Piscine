/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:33:42 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 09:24:45 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			result++;
		i++;
	}
	return (result);
}
/*
int contains_k(char *str)
{
	while (*str)
	{
		if (*str == 'k')
			return 1;
		str++;
	}
	return 0;
}

#include <stdio.h>
int main()
{
	char *tab[] = {"Bob", "Mkchkl", "Jkan"};
	printf("%d", ft_count_if(tab, 3, contains_k));
}*/