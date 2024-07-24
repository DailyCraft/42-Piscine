/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:18:25 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/19 08:29:55 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				src_ended;

	i = 0;
	src_ended = 0;
	while (i < n)
	{
		if (src[i] == 0)
			src_ended = 1;
		if (!src_ended)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
