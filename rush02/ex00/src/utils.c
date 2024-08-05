/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:14:34 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:14:40 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Print an error message on the error output.
void	error(t_dict *dict, char *type, char *msg)
{
	write(STDERR_FILENO, "\033[1;31m", 7);
	write(STDERR_FILENO, type, ft_strlen(type));
	write(STDERR_FILENO, "\n\033[0;31m", 8);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\033[0m\n", 5);
	if (dict != NULL)
		free_dict(dict);
}

// Clear a buffer.
void	clear_buf(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buf[i] = 0;
		i++;
	}
}

// Free the current value in an array and replace it by a new value.
void	safe_put_array(char *array[], int index, char *value)
{
	if (array[index] != NULL)
		free(array[index]);
	array[index] = value;
}

// Remove whitespaces before and after the string.
char	*trim(char *str)
{
	char	*result;
	int		i;
	int		start;
	int		j;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	if (i != ft_strlen(str))
	{
		i = ft_strlen(str) - 1;
		while (str[i] && ft_isspace(str[i]))
			i--;
		i++;
	}
	result = malloc((i - start + 1) * sizeof(char));
	j = 0;
	while (start + j < i)
	{
		result[j] = str[start + j];
		j++;
	}
	result[j] = 0;
	return (result);
}
