/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:44:55 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/08 16:34:16 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

void	invalid_number_of_bytes(char *str)
{
	char	*error;

	write(2, "tail: invalid number of bytes: ‘", 34);
	write(2, str, ft_strlen(str));
	write(2, "’", 3);
	if (errno != 0)
	{
		write(2, ": ", 2);
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		errno = 0;
	}
}

size_t	ft_atollu(char *str, int *err)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbr * 10 + str[i] - '0' < nbr)
		{
			errno = 75;
			invalid_number_of_bytes(str);
			*err = 1;
			return (0);
		}
		nbr = nbr * 10 + str[i++] - '0';
	}
	if (str[i] != 0)
	{
		invalid_number_of_bytes(str);
		*err = 1;
		return (0);
	}
	return (nbr);
}

size_t	get_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_errno(void)
{
	char	*err;

	err = strerror(errno);
	write(2, err, ft_strlen(err));
}
