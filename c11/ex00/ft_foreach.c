/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:16:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 08:19:53 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
/*
#include <stdio.h>
void putnbr(int nbr)
{
	printf("%d\n", nbr);
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft_foreach(tab, 10, putnbr);
}*/