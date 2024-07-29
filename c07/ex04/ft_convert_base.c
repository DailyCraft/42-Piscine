/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:59:10 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/29 09:11:38 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				index_of(char *str, char c);
unsigned int	ft_strlen(char *str);

int	check_base(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (index_of(base, base[i]) != i)
			return (0);
		i++;
	}
	return (1);
}

int	int_length(int nbr, char *base)
{
	int				length;
	unsigned int	u_nbr;

	if (nbr == 0)
		return (1);
	length = 0;
	if (nbr < 0)
	{
		u_nbr = -nbr;
		length++;
	}
	else
		u_nbr = nbr;
	while (u_nbr > 0)
	{
		u_nbr /= ft_strlen(base);
		length++;
	}
	return (length);
}

int	to_int(char *nbr, char *base)
{
	int	is_negative;
	int	result;

	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	is_negative = 0;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			is_negative = !is_negative;
		nbr++;
	}
	result = 0;
	while (index_of(base, *nbr) != -1)
	{
		result *= ft_strlen(base);
		result += index_of(base, *nbr);
		nbr++;
	}
	if (is_negative)
		result *= -1;
	return (result);
}

void	from_int(unsigned int nbr, char *base, char *result)
{
	if (nbr < ft_strlen(base))
		*result = base[nbr];
	else
	{
		from_int(nbr / ft_strlen(base), base, result - 1);
		from_int(nbr % ft_strlen(base), base, result);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				i_nbr;
	char			*result;
	int				size;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	i_nbr = to_int(nbr, base_from);
	size = int_length(i_nbr, base_to) + 1;
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	if (i_nbr < 0)
		result[0] = '-';
	result[size - 1] = 0;
	if (i_nbr < 0)
		from_int(-i_nbr, base_to, result + size - 2);
	else
		from_int(i_nbr, base_to, result + size - 2);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *result = ft_convert_base("-42", "0123456789", "0123456789ABCDEF");
	printf("%s", result);
	free(result);
}*/