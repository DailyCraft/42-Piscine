/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:50:47 by nbenhami          #+#    #+#             */
/*   Updated: 2024/07/28 22:25:14 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		sc_size(int **sc);
int		sc_border_set(int **sc, int index, int new_value);
int		sc_alloc(int ***sc, int size);
void	sc_free(int **sc);
void	sc_print(int **sc);
void	predef(int **sc);
int		backtracking(int **sc, int x, int y);

void	error(int **sc)
{
	sc_free(sc);
	write(2, "\033[1;31mError\n", 13);
}

/**
 * Compute the size of the puzzle.
 * Also check malformed argument.
 */
int	compute_size(int ***sc, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '7' && i % 2 == 0)
			count++;
		else if (str[i] != ' ' || i % 2 == 0)
			return (0);
		i++;
	}
	if (count % 4 != 0 || count / 4 < 4 || count / 4 > 7)
		return (0);
	if (sc_alloc(sc, count / 4) == 0)
		return (0);
	return (1);
}

/**
 * Parse the argument and check if it is malformed.
 * Store it on the sc array.
 */
int	parse_argument(int **sc, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '7')
		{
			sc_border_set(sc, count++, str[i] - '0');
			if (str[i] - '0' > sc_size(sc))
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * The main function of the program.
 */
int	main(int argc, char *argv[])
{
	int	**sc;

	sc = NULL;
	if (argc != 2
		|| compute_size(&sc, argv[1]) == 0
		|| parse_argument(sc, argv[1]) == 0)
	{
		error(sc);
		return (0);
	}
	predef(sc);
	if (backtracking(sc, 0, 0) == 0)
	{
		error(sc);
		return (0);
	}
	sc_print(sc);
	sc_free(sc);
}
