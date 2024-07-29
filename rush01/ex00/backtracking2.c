/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:06:18 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 21:00:42 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sc_size(int **sc);
int	sc_border(int **sc, int index);

/**
 * An extension of is_valid().
 * A logic function to eliminate some values in some locations.
 */
int	check_max(int **sc, int value, int x, int y)
{
	int	size;
	int	temp;

	size = sc_size(sc);
	temp = sc_border(sc, size * 2 + y);
	if (x < temp - 1 && value - x > size - temp + 1)
		return (0);
	temp = sc_border(sc, x);
	if (y < temp - 1 && value - y > size - temp + 1)
		return (0);
	return (1);
}
