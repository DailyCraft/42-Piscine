/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:48:02 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 14:52:08 by dvan-hum         ###   ########.fr       */
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
void print(int i)
{
	printf("%d\n", i);
}

int main()
{
	int array[] = {0, 1, 2, 5, 6, -42};
	ft_foreach(array, 6, print);
}*/