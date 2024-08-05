/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:13:48 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:14:00 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Compute the length of a string.
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Print the string on the standard output.
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

// Copy a string from src to dest.
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// A modified atoi that allows numbers with a lot of 0.
int	ft_atoi(char *str, int limit, int *zero_count)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	number = 0;
	neg = 1;
	while (i < limit && ft_isspace(str[i]))
		i++;
	while (i < limit && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i++] == '-')
			neg = -neg;
	}
	while (i < limit && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '0' && number == 1)
			(*zero_count)++;
		else if (*zero_count > 0)
			return (-1);
		else
			number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * neg);
}

// Return if the character is a white space.
t_bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
