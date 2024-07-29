/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:09:01 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 18:12:24 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	sc_size(int **sc);
int	sc_content(int **sc, int x, int y);

/**
 * Allocate necessary space for sc in accordance to size.
 */
int	sc_alloc(int ***sc, int size)
{
	int	i;
	int	j;
	int	**new_sc;

	new_sc = malloc((size + 1) * sizeof(int *));
	*sc = new_sc;
	if (new_sc == NULL)
		return (0);
	new_sc[0] = malloc((size * 4 + 1) * sizeof(int));
	i = 0;
	while (i < size)
	{
		new_sc[i + 1] = malloc(size * sizeof(int));
		if (new_sc[i + 1] == NULL)
			return (0);
		j = 0;
		while (j < size)
			new_sc[i][j++] = 0;
		i++;
	}
	new_sc[0][0] = size;
	return (1);
}

/**
 * Free sc at the end of the program.
 */
void	sc_free(int **sc)
{
	int	size;
	int	i;

	if (sc == NULL || sc[0] == NULL)
		return ;
	size = sc_size(sc);
	i = 0;
	while (i <= size)
	{
		if (sc[i] != NULL)
			free(sc[i]);
		i++;
	}
	if (sc != NULL)
		free(sc);
}

/**
 * Print sc in the standard output.
 */
void	sc_print(int **sc)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < sc_size(sc))
	{
		x = 0;
		while (x < sc_size(sc))
		{
			c = sc_content(sc, x, y) + '0';
			write(1, &c, 1);
			if (x != sc_size(sc) - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
