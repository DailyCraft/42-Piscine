/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:21:36 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 22:46:31 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sc_size(int **sc);
int		sc_border(int **sc, int index);

/**
 * Get the value in content if it is definable.
 */
int	get_predefined(int **sc, int x, int y)
{
	int	size;

	size = sc_size(sc);
	if (sc_border(sc, size * 2 + y) == size)
		return (x + 1);
	if (x == 0 && sc_border(sc, size * 2 + y) == 1)
		return (size);
	if (sc_border(sc, size * 3 + y) == size)
		return (size - x);
	if (x == size - 1 && sc_border(sc, size * 3 + y) == 1)
		return (size);
	if (sc_border(sc, x) == size)
		return (y + 1);
	if (y == 0 && sc_border(sc, x) == 1)
		return (size);
	if (sc_border(sc, size + x) == size)
		return (size - y);
	if (y == size - 1 && sc_border(sc, size + x) == 1)
		return (size);
	return (0);
}

/**
 * Predefine possible values.
 */
void	predef(int **sc)
{
	int	x;
	int	y;

	x = 0;
	while (x < sc_size(sc))
	{
		y = 0;
		while (y < sc_size(sc))
		{
			sc[x + 1][y] = get_predefined(sc, x, y);
			y++;
		}
		x++;
	}
}
