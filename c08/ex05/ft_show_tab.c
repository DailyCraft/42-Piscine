/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 07:58:45 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/30 08:20:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	unsigned int	u;

	if (nbr < 0)
	{
		write(1, "-", 1);
		u = -nbr;
	}
	else
		u = nbr;
	if (u > 9)
		ft_putnbr(u / 10);
	ft_putchar(u % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		write(1, par->str, par->size);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		write(1, par->copy, par->size);
		ft_putchar('\n');
		par++;
	}
}
/*
int main()
{
	t_stock_str stock[] = {
		{5, "salut", "salut"},
		{7, "bonjour", "bonjour"},
		{.str = 0}
	};
	ft_show_tab(stock);
}*/