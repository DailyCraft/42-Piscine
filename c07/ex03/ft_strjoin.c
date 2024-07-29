/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:20:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/25 08:54:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_i;
	int	src_i;

	dest_i = 0;
	while (dest[dest_i] != 0)
		dest_i++;
	src_i = 0;
	while (src[src_i] != 0)
	{
		dest[dest_i++] = src[src_i];
		src_i++;
	}
	dest[dest_i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *step)
{
	int		i;
	int		length;
	char	*result;

	i = 0;
	length = 1;
	while (i < size)
	{
		if (i > 0)
			length += ft_strlen(step);
		length += ft_strlen(strs[i++]);
	}
	result = malloc(length);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	i = 0;
	while (i < size)
	{
		if (i > 0)
			ft_strcat(result, step);
		ft_strcat(result, strs[i++]);
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *names[] = {"John", "Jean", "Bob"};
	char *result = ft_strjoin(3, names, ", ");
	printf("%s", result);
	free(result);
}*/