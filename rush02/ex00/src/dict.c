/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:11:30 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:35 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Set all the values of the array to NULL.
void	clear_array(char *array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
}

// Init the dicionary.
void	init_dict(t_dict *dict)
{
	clear_array(dict->units, 20);
	clear_array(dict->tens, 8);
	dict->hundred = NULL;
	clear_array(dict->thousands, 12);
}

// Free the content of a fixed size char array.
void	free_array(char *array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
}

// Free the allocated memory in s_dict structure.
void	free_dict(t_dict *dict)
{
	free_array(dict->units, 20);
	free_array(dict->tens, 8);
	if (dict->hundred != NULL)
		free(dict->hundred);
	free_array(dict->thousands, 12);
}
