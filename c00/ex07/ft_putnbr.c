/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:10:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 09:18:54 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	string_length(int nb)
{
	int	temp;
	int	length;

	if (nb < 0)
		temp = -nb;
	else
		temp = nb;
	length = 0;
	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

int	ft_pow(int nb, int pow_nb)
{
	int	result;

	result = nb;
	if (pow_nb == 0)
		return (1);
	if (pow_nb == 1)
		return (nb);
	while (pow_nb > 1)
	{
		result *= nb;
		pow_nb--;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	int		length;
	char	letter;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		length = string_length(nb) - 1;
		while (length >= 0)
		{
			letter = nb / ft_pow(10, length) % 10 + 48;
			write(1, &letter, 1);
			nb -= nb / ft_pow(10, length) % 10 * ft_pow(10, length);
			length--;
		}
	}
}
/*
int main()
{
	ft_putnbr(0);
}*/
