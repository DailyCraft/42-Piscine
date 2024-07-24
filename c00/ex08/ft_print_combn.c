/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:08:45 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/17 18:26:17 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr(int nb, int length)
{
	char	letter;

	length--;
	while (length >= 0)
	{
		letter = nb / ft_pow(10, length) % 10 + 48;
		write(1, &letter, 1);
		nb -= nb / ft_pow(10, length) % 10 * ft_pow(10, length);
		length--;
	}
}

int	is_sorted(int nb, int length)
{
	int	i;
	int	digit;

	i = 0;
	digit = 10;
	while (i < length)
	{
		if (nb % 10 >= digit)
			return (0);
		digit = nb % 10;
		nb /= 10;
		i++;
	}
	return (1);
}

int	get_max(int length)
{
	int	value;
	int	i;
	int	j;

	value = 0;
	j = 0;
	i = 9;
	while (j < length)
	{
		value += i * ft_pow(10, 9 - i);
		i--;
		j++;
	}
	return (value);
}

void	ft_print_combn(int n)
{
	int	value;
	int	max;

	value = 0;
	max = get_max(n);
	while (value <= max)
	{
		if (is_sorted(value, n))
		{
			ft_putnbr(value, n);
			if (value == max)
				return ;
			else
				write(1, ", ", 2);
		}
		value++;
	}
}
