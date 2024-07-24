/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:59:45 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/21 13:26:30 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
char	*ft_strcpy(char *dest, char *src);
void	error(char *error);

/**
 * The function that print the correct character of the rush pattern.
 */
void	print_char(int x, int y, int *indexes, char *format)
{
	int	xi;
	int	yi;

	xi = indexes[0];
	yi = indexes[1];
	if (yi == 0 && xi == 0)
		ft_putchar(format[0]);
	else if (yi == 0 && xi == x - 1)
		ft_putchar(format[1]);
	else if (yi == y - 1 && xi == 0)
		ft_putchar(format[2]);
	else if (yi == y - 1 && xi == x - 1)
		ft_putchar(format[3]);
	else if (yi == 0 || yi == y - 1)
		ft_putchar(format[4]);
	else if (xi == 0 || xi == x - 1)
		ft_putchar(format[5]);
	else
		ft_putchar(' ');
}

/**
 * Analyse x and y and print potentials errors.
 */
int	print_errors(int x, int y)
{
	if (x == -1 || y == -1 || x == 0 || y == 0)
	{
		error("Les valeurs des paramètres x et y doivent ");
		error("être supérieur à 0 !\n");
		error("The values of arguments x and y must be greater than 0!");
		return (1);
	}
	else if (x == -2 || y == -2)
	{
		error("La valeur du paramètre x ou y est trop grande !\n");
		error("The value of the argument x or y is too big!");
		return (1);
	}
	else if (x == -3 || y == -3)
	{
		error("La valeur du paramètre x ou y ne peut pas être analysée !\n");
		error("The value of the argument x or y cannot be parsed!");
		return (1);
	}
	return (0);
}

/**
 * The main function for print a rush pattern.
 */
void	print_rush(int x, int y, char *format)
{
	int	xi;
	int	yi;
	int	indexes[2];

	if (print_errors(x, y) == 1)
		return ;
	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			indexes[0] = xi;
			indexes[1] = yi;
			print_char(x, y, indexes, format);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

/**
 * The rush04 function.
 */
void	rush(int x, int y)
{
	print_rush(x, y, "ACCABB");
}
