/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:46:04 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/22 14:55:54 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int *indexes, int i)
{
	int	current;
	int	j;

	current = indexes[i];
	j = i - 1;
	while (j >= 0)
	{
		if (current == indexes[j])
			return (0);
		if (current == indexes[j] - i + j || current == indexes[j] + i - j)
			return (0);
		j--;
	}
	return (1);
}

void	print(int *indexes)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = indexes[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	recursive(int *indexes, int i, int amount)
{
	indexes[i] = 0;
	while (indexes[i] < 10)
	{
		if (is_valid(indexes, i))
		{
			if (i == 9)
			{
				print(indexes);
				amount++;
			}
			else
				amount = recursive(indexes, i + 1, amount);
		}
		indexes[i]++;
	}
	return (amount);
}

int	ft_ten_queens_puzzle(void)
{
	int	indexes[10];

	return (recursive(indexes, 0, 0));
}
/*
#include <stdio.h>
int main()
{
    printf("Amount: %d\n", ft_ten_queens_puzzle());
}*/
