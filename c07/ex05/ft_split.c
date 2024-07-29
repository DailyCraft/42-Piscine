/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:12:10 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/29 09:30:07 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	compute_result_size(char *str, char *charset)
{
	int		i;
	int		size;
	char	*start;

	i = 0;
	size = 0;
	start = str;
	while (str[i])
	{
		if (contains(charset, str[i]))
		{
			if (start != str + i)
				size++;
			start = str + i + 1;
		}
		i++;
	}
	if (start != str + i)
		size++;
	return (size);
}

void	add_to_result(char **result, int i, char *start, char *str)
{
	char	*entry;
	int		j;

	entry = malloc(str - start + 1);
	j = 0;
	while (start + j < str)
	{
		entry[j] = start[j];
		j++;
	}
	result[i] = entry;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*start;
	int		i;
	int		j;

	start = str;
	result = malloc((compute_result_size(str, charset) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (contains(charset, str[i]))
		{
			if (start != str + i)
				add_to_result(result, j++, start, str + i);
			start = str + i + 1;
		}
		i++;
	}
	if (start != str + i)
		add_to_result(result, j++, start, str + i);
	result[j] = 0;
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char **result;
	result = ft_split("abajabajabauayavaiahgaiahaiaaaaiagauiahahau ua a", "a");
	for (int i = 0; result[i] != 0; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
}*/