/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:00:12 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 22:44:27 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sc_size(int **sc);
int	sc_content(int **sc, int x, int y);
int	sc_border(int **sc, int index);
int	backtracking(int **sc, int x, int y);
int	check_max(int **sc, int value, int x, int y);

/**
 * Check if a value is allowed with the border.
 * 
 * step:
 * 	0: vertcal - up
 * 	1: vertical - down
 * 	2: horizontal - left
 * 	3: horizontal - right
 */
int	is_line_valid(int **sc, int step, int current, int max_current)
{
	int	i;
	int	max;
	int	counter;

	i = (max_current - 1) * !(step == 0 || step == 2);
	max = 0;
	counter = 0;
	while (i < max_current && i >= 0)
	{
		if (sc_content(sc, i, current) > max && step >= 2)
		{
			max = sc_content(sc, i, current);
			counter++;
		}
		if (sc_content(sc, current, i) > max && step < 2)
		{
			max = sc_content(sc, current, i);
			counter++;
		}
		i += (step == 0 || step == 2) * 2 - 1;
	}
	if (max_current == sc_size(sc))
		return (counter == sc_border(sc, sc_size(sc) * step + current));
	else
		return (counter <= sc_border(sc, sc_size(sc) * step + current));
}

/**
 * An extension of is_valid().
 * Call is_line_valid() with correct args in accordance to the orientation.
 */
int	is_border_valid(int **sc, int x, int y, int orientation)
{
	if (orientation == 0)
	{
		if (is_line_valid(sc, 2, y, x + 1) == 0)
			return (0);
		if (is_line_valid(sc, 3, y, x + 1) == 0)
			return (0);
	}
	else
	{
		if (is_line_valid(sc, 0, x, y + 1) == 0)
			return (0);
		if (y + 1 == sc_size(sc) && is_line_valid(sc, 1, x, y + 1) == 0)
			return (0);
	}
	return (1);
}

/**
 * Check if a value is allowed in the current location.
 */
int	is_valid(int **sc, int value, int x, int y)
{
	int	i;
	int	size;

	if (check_max(sc, value, x, y) == 0)
		return (0);
	i = 0;
	size = sc_size(sc);
	while (i < size)
	{
		if (i != x && sc_content(sc, i, y) == value)
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i != y && sc_content(sc, x, i) == value)
			return (0);
		i++;
	}
	if (x == sc_size(sc) - 1 && !is_border_valid(sc, x, y, 0))
		return (0);
	if (!is_border_valid(sc, x, y, 1))
		return (0);
	return (1);
}

/**
 * Go to the next value of the backtracking.
 */
int	go_next(int **sc, int x, int y)
{
	if (x == sc_size(sc) - 1 && y == sc_size(sc) - 1)
		return (1);
	if (x == sc_size(sc) - 1)
	{
		if (backtracking(sc, 0, y + 1))
			return (1);
	}
	else
	{
		if (backtracking(sc, x + 1, y))
			return (1);
	}
	return (0);
}

/**
 * The main function for the backtracking algorithm.
 */
int	backtracking(int **sc, int x, int y)
{
	int	i;

	if (sc_content(sc, x, y) != 0 && is_valid(sc, sc_content(sc, x, y), x, y))
		if (go_next(sc, x, y))
			return (1);
	i = 1;
	while (i <= sc_size(sc))
	{
		sc[x + 1][y] = i;
		if (is_valid(sc, i, x, y))
			if (go_next(sc, x, y))
				return (1);
		i++;
	}
	sc[x + 1][y] = 0;
	return (0);
}
