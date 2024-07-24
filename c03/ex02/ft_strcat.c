/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:19:06 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/19 10:38:31 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char src[] = "monsieur";
	char dest[] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', 0,
		'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
	ft_strcat(dest, src);
	for (int i = 0; i < 18; i++)
		printf("%c,", dest[i]);
}*/
