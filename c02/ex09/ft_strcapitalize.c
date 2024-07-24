/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:55:58 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 08:30:08 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_alphanumeric(char c)
{
	return (is_alpha(c) || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (is_alpha(str[i]) && (i == 0 || !is_alphanumeric(str[i - 1])))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "salut, comment tu vas ? 42mots Quarante-deux; cinQuante+et+un";
	ft_strcapitalize(str);
	printf("%s", str);
}*/