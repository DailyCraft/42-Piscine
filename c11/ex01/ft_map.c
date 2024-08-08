/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:20:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 08:27:17 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	result = malloc(length * sizeof(int));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*
int plus_plus(int i)
{
	return i + 1;
}

#include <stdio.h>
int main()
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *mapped = ft_map(tab, 10, plus_plus);
	for (int i = 0; i < 10; i++)
		printf("%d -> %d\n", tab[i], mapped[i]);
	free(mapped);
}*/