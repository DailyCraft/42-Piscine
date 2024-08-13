/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:12:04 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 17:05:35 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i])
			{
				if (j != i)
					return (-1);
				break ;
			}
			j++;
		}
		i++;
	}
	return (i);
}

void	print_nbr(unsigned int nbr, char *base, unsigned int base_length)
{
	if (nbr >= base_length)
		print_nbr(nbr / base_length, base, base_length);
	write(1, base + nbr % base_length, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_length;

	base_length = check_base(base);
	if (base_length < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_nbr(-nbr, base, base_length);
	}
	else
		print_nbr(nbr, base, base_length);
}
/*
int main()
{
	char *base = "0123456789ABCDEF";
	ft_putnbr_base(-2147483648, base);
}*/
