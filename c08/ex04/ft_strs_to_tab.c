/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 07:49:46 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/26 09:24:27 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	result = malloc((ac + 1) * sizeof(t_stock_str));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *strs[] = {"", "bb", "ccc", "dddd"};
	t_stock_str *stock = ft_strs_to_tab(4, strs);
	while (stock->str != 0)
	{
		stock->copy[2] = 'w';
		printf("%d '%s' '%s'\n", stock->size, stock->str, stock->copy);
		stock++;
	}
	
}*/