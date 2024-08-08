/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:38:45 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/05 09:05:07 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, int nb)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && i < nb)
		i++;
	if (i == 16)
		return (0);
	return (s1[i] - s2[i]);
}
