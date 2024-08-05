/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:14:13 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:16:34 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_bool	manage_args(int argc, char **argv, char **number, t_dict *dict)
{
	if (argc == 2 || argc == 3)
		return (parse_args(argc, argv, number, dict));
	error(NULL, "Error", "Format: [dictionary] <number>");
	return (FALSE);
}

int	main(int argc, char **argv)
{
	char	*number;
	t_dict	dict;

	init_dict(&dict);
	if (!manage_args(argc, argv, &number, &dict))
		return (0);
	print_result(&dict, number);
	if (number != NULL)
		free(number);
	free_dict(&dict);
	return (0);
}
