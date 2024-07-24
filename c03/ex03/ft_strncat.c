/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:19:06 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/20 08:33:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				dest_i;
	unsigned int	src_i;

	dest_i = 0;
	while (dest[dest_i] != 0)
		dest_i++;
	src_i = 0;
	while (src[src_i] != 0 && src_i < nb)
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
	ft_strncat(dest, src, 5);
	for (int i = 0; i < 18; i++)
		printf("%c,", dest[i]);
}*/
