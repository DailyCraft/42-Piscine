/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:11:10 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 15:27:29 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	while (src[length] != 0)
		length++;
	if (size == 0)
		return (length);
	i = 0;
	while (i < size - 1)
	{
		if (src[i] == 0)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (length);
}
/*
#include <stdio.h>
int main()
{
	char dest[5] = "cccc";
	printf("Return: %d\n", ft_strlcpy(dest, "Bonjour", 5));
	printf("%s", dest);
}*/