/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:47:29 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/24 07:54:14 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*start;

	if (!*to_find)
		return (str);
	while (*str)
	{
		i = 0;
		start = str;
		while (*str == to_find[i])
		{
			if (to_find[i] == 0 || to_find[i + 1] == 0)
				return (start);
			i++;
			str++;
		}
		if (str == start)
			str++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char str1[] = "SalutSalut";
	printf("SalutSalut: %s\n", ft_strstr(str1, ""));
	char str2[] = "SalutSalut";
	printf("(null): %s\n", ft_strstr(str2, "Slt"));
	char str3[] = "SalutSalut";
	printf("SalutSalut: %s\n", ft_strstr(str3, "Sal"));
	char str4[] = "SalutSwlut";
	printf("Swlut: %s\n", ft_strstr(str4, "Swl"));
	char str5[] = "SaSwlut";
	printf("Swlut: %s\n", ft_strstr(str5, "Swl"));
	char str6[] = "SSwlut";
	printf("Swlut: %s\n", ft_strstr(str6, "Swl"));
	char str7[] = "Salut";
	printf("lut: %s\n", ft_strstr(str7, "lut"));
	char str8[] = "Salu";
	printf("(null): %s\n", ft_strstr(str8, "lut"));
}*/