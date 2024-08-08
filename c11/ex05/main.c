/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:45:00 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/01 10:24:21 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add(int i, int j);
void	sub(int i, int j);
void	mul(int i, int j);
void	div(int i, int j);
void	mod(int i, int j);

int	ft_atoi(char *str)
{
	int	result;
	int	is_neg;

	result = 0;
	is_neg = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_neg = !is_neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (is_neg)
		return (-result);
	return (result);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	index_of(char *str, char *c)
{
	int	i;

	if (!(c[0] != 0 && c[1] == 0))
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c[0])
			return (i);
		i++;
	}
	return (-1);
}

void	init_operations(char *operators, void (*operations[])(int, int))
{
	operators[0] = '+';
	operators[1] = '-';
	operators[2] = '*';
	operators[3] = '/';
	operators[4] = '%';
	operations[0] = add;
	operations[1] = sub;
	operations[2] = mul;
	operations[3] = div;
	operations[4] = mod;
}

int	main(int argc, char **argv)
{
	char	operators[5];
	void	(*operations[5])(int, int);
	int		index;

	init_operations(operators, operations);
	if (argc == 4)
	{
		index = index_of(operators, argv[2]);
		if (index != -1)
			operations[index](ft_atoi(argv[1]), ft_atoi(argv[3]));
		else
			ft_putnbr(0);
	}
}
