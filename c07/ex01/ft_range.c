/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:24:58 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/25 10:06:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = malloc((max - min) * 4);
	if (result == NULL)
		return (result);
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
/*
#include <stdio.h>
int main() {
	int *array = ft_range(4, 2);
	for (int i = 0; i < 2; i++)
		printf("%d,", array[i]);
	free(array);
}*/