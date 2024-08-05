/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:11:47 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:16:23 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Check if a line is valid.
// Returns:
// 	0: No error
// 	1: Empty line
// 	2: Invalid line
int	check_dict_line(t_dict *dict, char *line)
{
	int	i;

	if (line[0] == 0)
		return (1);
	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] != ':')
	{
		error(dict, "Dict Error", "Parsing error, invalid line.");
		return (2);
	}
	i++;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == 0)
	{
		error(dict, "Dict Error", "Parsing error, invalid line.");
		return (2);
	}
	return (0);
}

// Add the parsed entry to the dictionary.
t_bool	add_to_dict(t_dict *dict, char *line_value, int number, int zero_count)
{
	char	*value;

	value = trim(line_value);
	if (!ft_is_printable(value))
	{
		free(value);
		error(dict, "Dict Error", "Unprintable character in the dictionary");
		return (FALSE);
	}
	if (number < 20 && zero_count == 0)
		safe_put_array(dict->units, number, value);
	else if (number == 1 && zero_count == 1)
		safe_put_array(dict->units, 10, value);
	else if (number < 100 && number % 10 == 0)
		safe_put_array(dict->tens, number / 10 - 2, value);
	else if (number == 1 && zero_count == 2)
	{
		if (dict->hundred != NULL)
			free(dict->hundred);
		dict->hundred = value;
	}
	else if (number == 1 && zero_count % 3 == 0)
		if (zero_count > 2 && zero_count < 37)
			safe_put_array(dict->thousands, zero_count / 3 - 1, value);
	return (TRUE);
}

// Parse a line in the dictionary.
t_bool	parse_line(t_dict *dict, char *line)
{
	int		line_valid_statut;
	int		i;
	int		number;
	int		zero_count;

	line_valid_statut = check_dict_line(dict, line);
	if (line_valid_statut == 1)
		return (TRUE);
	else if (line_valid_statut == 2)
		return (FALSE);
	i = 0;
	zero_count = 0;
	while (line[i] && line[i] != ':')
		i++;
	number = ft_atoi(line, i, &zero_count);
	i++;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (number < 0)
	{
		error(dict, "Dict Error", "Invalid number in the dictionary");
		return (FALSE);
	}
	return (add_to_dict(dict, line + i, number, zero_count));
}

// Manage lines in the dictionary.
t_bool	dict_line(t_dict *dict, char c)
{
	static char	line[100] = {};
	static int	current = 0;

	if (c != '\n')
	{
		if (current == 100)
		{
			error(dict, "Dict error", "A line in the dictionary is too long.");
			return (FALSE);
		}
		line[current] = c;
		current++;
		return (TRUE);
	}
	if (!parse_line(dict, line))
		return (FALSE);
	clear_buf(line, 100);
	current = 0;
	return (TRUE);
}
