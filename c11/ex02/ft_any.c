/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:26:41 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 09:24:36 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int contains_k(char *str)
{
	while (*str)
	{
		if (*str == 'k')
			return 1;
		str++;
	}
	return 0;
}

#include <stdio.h>
int main()
{
	char *tab[] = {"Bob", "Michel", "Jkan", 0};
	printf("%d", ft_any(tab, contains_k));
}*/