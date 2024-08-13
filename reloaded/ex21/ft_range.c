/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:25:33 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 14:30:17 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = malloc((max - min) * sizeof(int));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int *range = ft_range(-5, 5);
	for (int i = 0; i < 10; i++)
		printf("%d\n", range[i]);
}*/