/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:58:57 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/21 13:26:29 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Print a character in the console.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * Convert a string into an integer.
 *
 * -1: Cannot be < 0
 * -2: Too big
 * -3: Cannot be parsed
 */
int	ft_atoi(char *str)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i] != 0)
	{
		if (str[i] == '-')
			return (-1);
		if (str[i] < '0' || str[i] > '9')
		{
			if (value == 0)
				return (-3);
			break ;
		}
		else
		{
			value *= 10;
			value += str[i] - '0';
			if (value < 0)
				return (-2);
		}
		i++;
	}
	return (value);
}

/**
 * Copy the src string in the dest string.
 */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * Compare two string.
 *
 * Returns: the parsed number
 *   OR
 * <0: s1 < s2
 *  0: s1 == s2
 * >0: s1 > s2
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

/**
 * Print an error.
 */
void	error(char *error)
{
	int	length;

	length = 0;
	while (error[length] != 0)
		length++;
	write(2, "\033[31m", 5);
	write(2, error, length);
}
