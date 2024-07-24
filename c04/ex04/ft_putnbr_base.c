/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:12:04 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 13:30:28 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pow(int nbr, int pow)
{
	int	result;

	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nbr);
	result = nbr;
	while (pow > 1)
	{
		result *= nbr;
		pow--;
	}
	return (result);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*start;

	if (!*to_find)
		return (str);
	while (*str)
	{
		i = 0;
		start = str;
		while (*str == to_find[i])
		{
			if (to_find[i] == 0 || to_find[i + 1] == 0)
				return (start);
			i++;
			str++;
		}
		if (str == start)
			str++;
	}
	return (0);
}

int	check_base(char *base)
{
	int		i;
	char	to_find[2];

	i = 0;
	to_find[1] = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		to_find[0] = base[i];
		if (ft_strstr(base, to_find) != base + i)
			return (-1);
		i++;
	}
	return (i);
}

void	print_chars(unsigned int nbr, int nbr_length, char *base, int base_len)
{
	unsigned int	copy;

	while (nbr_length >= 0)
	{
		copy = nbr / ft_pow(base_len, nbr_length);
		write(1, base + copy % base_len, 1);
		nbr_length--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_length;
	unsigned int	u_nbr;
	int				i;
	unsigned int	nbr_copy;

	base_length = check_base(base);
	if (base_length < 2)
		return ;
	if (nbr == 0)
		write(1, base, 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	i = -1;
	nbr_copy = u_nbr;
	while (nbr_copy != 0)
	{
		i++;
		nbr_copy /= base_length;
	}
	print_chars(u_nbr, i, base, base_length);
}
/*
int main()
{
	char *base = "0123456789ABCDEF";
	ft_putnbr_base(-2147483648, base);
}*/
