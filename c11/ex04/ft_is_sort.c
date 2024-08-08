/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:36:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 09:25:03 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int is_sort(int i, int j)
{
	return i - j;
}

#include <stdio.h>
int main()
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d", ft_is_sort(tab, 10, is_sort));
}*/