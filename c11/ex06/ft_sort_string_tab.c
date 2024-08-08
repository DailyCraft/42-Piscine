/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:26:36 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 09:34:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		modified;
	int		i;
	char	*temp;

	modified = 1;
	while (modified)
	{
		modified = 0;
		i = 1;
		while (tab[i])
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
				modified = 1;
			}
			i++;
		}
	}
}
/*
#include <stdio.h>
int main()
{
	char *tab[] = {"z", "a", "t", "tt", "a", "tr", "t", 0};
	ft_sort_string_tab(tab);
	for (int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);
}*/