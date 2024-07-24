/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 07:57:39 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 10:20:00 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	digit_count(int nb)
{
	int	i;

	i = 0;
	while (nb / 10 > 0)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

void	print_digit(int nb, int i)
{
	int		j;
	char	c;

	j = 0;
	while (j++ < i)
		nb /= 10;
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	i = digit_count(nb) - 1;
	while (i >= 0)
	{
		print_digit(nb, i);
		i--;
	}
}
/*
#include <stdio.h>
int main()
{
	//printf("%d", digit_count(478));
	ft_putnbr(2147483647);
}*/
