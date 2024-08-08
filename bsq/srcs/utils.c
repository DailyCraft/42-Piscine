/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:49:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/06 21:16:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_realloc(char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = c;
	dest[i + 1] = 0;
	free(src);
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_reset_square(t_square *square, int val)
{
	square->x = val;
	square->y = val;
	square->size = 0;
}
