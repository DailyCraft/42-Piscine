/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/25 08:56:06 by dvan-hum         ###   ########.fr       */
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
	int		length;
	char	*result;
	int		i;

	length = ft_strlen(src);
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
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
	char *str = ft_strdup("salut");
	printf("%s", str);
	free(str);
}*/