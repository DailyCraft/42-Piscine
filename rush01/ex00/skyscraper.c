/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:03 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 18:11:06 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * sc is a 2 entry array:
 * 	sc[0] after the index 1 contains the border.
 * 	sc[0][0] contains the size.
 * 	sc after the index 1 contains the content.
 * 
 * Example (for 4x4);
 * 	sc[0][0]: size
 * 	sc[0][1 -> 16]: border
 * 	sc[1 -> 16][0 -> 15]: content
 * 	sc[0][1 a 16] 
 * 	content[x][y]
 */

/**
 * Get the size of the sc.
 */
int	sc_size(int **sc)
{
	return (sc[0][0]);
}

/**
 * Get a value in the content of the puzzle.
 */
int	sc_content(int **sc, int x, int y)
{
	return (sc[x + 1][y]);
}

/**
 * Get a value of the border of the puzzle.
 */
int	sc_border(int **sc, int index)
{
	return (sc[0][index + 1]);
}

void	sc_border_set(int **sc, int index, int new_value)
{
	sc[0][index + 1] = new_value;
}
