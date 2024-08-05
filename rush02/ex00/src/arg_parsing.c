/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:11:11 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:26 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_bool	check_number_too_long(int i)
{
	if (i > 39)
	{
		error(NULL, "Error", "The number is too long.");
		return (FALSE);
	}
	return (TRUE);
}

// Check if the number is valid.
t_bool	check_number(char *number)
{
	int	i;

	i = 0;
	if (number[ft_strlen(number) - 1] == '\n')
		number[ft_strlen(number) - 1] = 0;
	number = trim(number);
	if (number[0] == 0)
	{
		free(number);
		error(NULL, "Error", "Invalid number");
		return (FALSE);
	}
	while (number[i])
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
		{
			free(number);
			error(NULL, "Error", "Invalid number");
			return (FALSE);
		}
		i++;
	}
	free(number);
	return (check_number_too_long(i));
}

// Parse arguments.
t_bool	parse_args(int argc, char **argv, char **number, t_dict *dict)
{
	char	dict_path[40];

	if (!check_number(argv[argc - 1]))
		return (FALSE);
	*number = trim(argv[argc - 1]);
	if (argc == 3)
	{
		if (ft_strlen(argv[1]) > 39)
		{
			error(NULL, "Dict Error", "The dictionary path is too long.");
			return (FALSE);
		}
		ft_strcpy(dict_path, argv[1]);
	}
	else
		ft_strcpy(dict_path, "numbers.dict");
	if (!parse_dict(dict, dict_path))
		return (FALSE);
	return (TRUE);
}
