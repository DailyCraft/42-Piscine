/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:10 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 14:36:15 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	order(char *values[], int size)
{
	int		modified;
	int		i;
	char	*temp;

	modified = 1;
	while (modified)
	{
		modified = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(values[i], values[i + 1]) > 0)
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
				modified = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	order(++argv, --argc);
	i = 0;
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
