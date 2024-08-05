/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:14:53 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:14:56 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Check if the number is 0.
t_bool	is_zero(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] != '0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// Print a value preceding by a space if it is not the first.
void	print_value(char *str)
{
	static t_bool	is_first = TRUE;

	if (!is_first)
		ft_putstr(" ");
	is_first = FALSE;
	ft_putstr(str);
}

// Print tens and units.
void	print_units(t_dict *dict, char *number, int index, int length)
{
	int	value;

	if (index > 0)
		value = (number[index - 1] - '0') * 10 + number[index] - '0';
	else
		value = number[index] - '0';
	if (value == 0)
	{
		if (index == length - 1 && is_zero(number))
			print_value(dict->units[0]);
	}
	else if (value < 20)
		print_value(dict->units[value]);
	else
	{
		print_value(dict->tens[number[index - 1] - '0' - 2]);
		if (number[index] != '0')
		{
			ft_putstr("-");
			ft_putstr(dict->units[number[index] - '0']);
		}
	}
	if (index != length - 1)
		if (value != 0 || (index - 2 >= 0 && number[index - 2] != '0'))
			print_value(dict->thousands[(length - index) / 3 - 1]);
}

// Print the result on the standard output.
void	print_result(t_dict *dict, char *number)
{
	int	length;
	int	i;

	length = ft_strlen(number);
	i = 0;
	while (i < length)
	{
		if ((length - i - 1) % 3 == 0)
		{
			print_units(dict, number, i, length);
			i++;
		}
		else if ((length - i - 1) % 3 == 2)
		{
			if (number[i] != '0')
			{
				print_value(dict->units[number[i] - '0']);
				print_value(dict->hundred);
			}
			i += 2;
		}
		else
			i++;
	}
	ft_putstr("\n");
}
