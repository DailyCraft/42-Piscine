/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:08:45 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/12 15:29:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_max(char *comb, int n)
{
	if (comb[--n] != '9')
		return (0);
	while (--n >= 0)
	{
		if (comb[n] != comb[n + 1] - 1)
			return (0);
	}
	return (1);
}

void	recursive(char *comb, int n, int current)
{
	if (current == n)
	{
		write(1, comb, n);
		if (!is_max(comb, n))
			write(1, ", ", 2);
		return ;
	}
	if (current == 0)
		comb[0] = '0';
	else
		comb[current] = comb[current - 1] + 1;
	while (comb[current] <= '9' - n + current + 1)
	{
		recursive(comb, n, current + 1);
		comb[current]++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[9];

	recursive(comb, n, 0);
}
