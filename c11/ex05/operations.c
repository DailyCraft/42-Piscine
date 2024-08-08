/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:55:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 09:22:35 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr);

void	add(int i, int j)
{
	ft_putnbr(i + j);
	write(1, "\n", 1);
}

void	sub(int i, int j)
{
	ft_putnbr(i - j);
	write(1, "\n", 1);
}

void	mul(int i, int j)
{
	ft_putnbr(i * j);
	write(1, "\n", 1);
}

void	div(int i, int j)
{
	if (j == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(i / j);
	write(1, "\n", 1);
}

void	mod(int i, int j)
{
	if (j == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(i % j);
	write(1, "\n", 1);
}
