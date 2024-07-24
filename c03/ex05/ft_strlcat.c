/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:33:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 09:41:32 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strnlen(char *str, int n)
{
	int	i;

	i = 0;
	while ((n == -1 || i < n) && str[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length;

	length = ft_strnlen(dest, size) + ft_strnlen(src, -1);
	while (*dest)
	{
		dest++;
		if (size > 0)
			size--;
	}
	if (size > 0)
	{
		while (*src && size - 1 > 0)
		{
			*dest = *src;
			dest++;
			src++;
			size--;
		}
	}
	*dest = 0;
	return (length);
}
/*
#include <stdio.h>
int main() {
	char dest[20] = "Bonjour \0ccccccccc";
	char src[] = "iiiiiiiiiiiiiiiiiiiiiii";
	printf("Length: %d\n", ft_strlcat(dest, src, 15));
	for (int i = 0; i < 20; i++)
		printf("%c,", dest[i]);
}*/