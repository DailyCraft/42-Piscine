/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:13:12 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:44 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Read the dictionary.
t_bool	read_dict(t_dict *dict, int file)
{
	char	buf[1];
	int		count;

	count = read(file, buf, 1);
	while (count > 0)
	{
		if (!dict_line(dict, buf[0]))
		{
			close(file);
			return (FALSE);
		}
		count = read(file, buf, 1);
	}
	if (count == -1)
	{
		error(dict, "Dict Error", "Failed to read the file");
		return (FALSE);
	}
	if (buf[0] != '\n')
	{
		error(dict, "Dict Error",
			"The dictionary file must end with a new line");
		return (FALSE);
	}
	return (TRUE);
}

// Parse the dictionary and fill the s_dict structure.
t_bool	parse_dict(t_dict *dict, char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		close(file);
		error(NULL, "Dict Error", "Cannot open the file");
		return (FALSE);
	}
	if (!read_dict(dict, file))
	{
		close(file);
		return (FALSE);
	}
	close(file);
	return (TRUE);
}
