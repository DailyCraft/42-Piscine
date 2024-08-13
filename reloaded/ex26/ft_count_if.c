/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:35 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 14:58:14 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		count += f(tab[i]) == 1;
		i++;
	}
	return (count);
}
/*
int check(char *str)
{
	return (*str == 'f');
}

#include <stdio.h>
int main()
{
	char *array[] = {"eru", "fre", "Fref", "f", "", 0};
	printf("%d", ft_count_if(array, check));
}*/