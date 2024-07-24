/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:34:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/23 09:46:59 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	hexa_digit(int i)
{
	if (i < 10)
		return (i + '0');
	else
		return (i + 'a' - 10);
}

void	print_addr(void *addr)
{
	int		i;
	char	hexa;

	i = 15;
	while (i >= 0)
	{
		hexa = hexa_digit((((unsigned long) addr >> i * 4) & 0xf));
		write(1, &hexa, 1);
		i--;
	}
}

void	print_hexa_content(void *addr, unsigned int size)
{
	unsigned int		i;
	char				hexa;

	i = 0;
	while (i < 16)
	{
		if (i >= size)
			write(1, "  ", 2);
		else
		{
			hexa = hexa_digit(*((char *) addr + i) >> 4 & 0xf);
			write(1, &hexa, 1);
			hexa = hexa_digit(*((char *) addr + i) & 0xf);
			write(1, &hexa, 1);
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_char_content(void *addr, unsigned int size)
{
	while (size > 0)
	{
		if (*((char *) addr) >= 32 && *((char *) addr) <= 126)
			write(1, addr, 1);
		else
			write(1, ".", 1);
		size--;
		addr++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	void			*original_addr;

	original_addr = addr;
	while (size > 0)
	{
		print_addr(addr);
		write(1, ": ", 2);
		if (size > 16)
			i = 16;
		else
			i = size;
		print_hexa_content(addr, i);
		print_char_content(addr, i);
		write(1, "\n", 1);
		size -= i;
		addr += 16;
	}
	return (original_addr);
}
/*
int main()
{
	char str[] = "Salut moooo\nooooonsieur, alors ca roule ?\n\n\n\n\n";
	ft_print_memory(str, 47);
}*/