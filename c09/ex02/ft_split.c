/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:37 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/31 14:59:02 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	contains(char *str, char c)
{
	while (*str)
		if (*(str++) == c)
			return (1);
	return (0);
}

void	add_to_result(char **result, int index, char *start, char *end)
{
	int	i;

	i = 0;
	result[index] = malloc((end - start) * sizeof(char));
	if (result[index] != NULL)
	{
		i = 0;
		while (start + i < end)
		{
			result[index][i] = start[i];
			i++;
		}
	}
}

void	populate_result(char **result, char *str, char *charset)
{
	int		i;
	int		j;
	int		start;

	j = 0;
	i = 0;
	start = i;
	while (str[i])
	{
		if (contains(charset, str[i]))
		{
			if (i != start)
				add_to_result(result, j++, str + start, str + i);
			start = i + 1;
		}
		i++;
	}
	if (i != start)
		add_to_result(result, j++, str + start, str + i);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		start;
	int		length;

	i = 0;
	start = i;
	length = 0;
	while (str[i])
	{
		if (contains(charset, str[i]))
		{
			if (i != start)
				length++;
			start = i + 1;
		}
		i++;
	}
	if (i != start)
		length++;
	result = malloc((length + 1) * sizeof(char *));
	result[length] = 0;
	populate_result(result, str, charset);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char **split = ft_split("aaa0a1a2222a3a4a5a6a7a8a9aaaaaab", "a");
	int i = 0;
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/