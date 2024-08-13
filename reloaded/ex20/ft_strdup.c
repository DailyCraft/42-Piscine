/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:19:26 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 14:25:03 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	result = malloc((ft_strlen(src) + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strdup("Hello world!"));
}*/