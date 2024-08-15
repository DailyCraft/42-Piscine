/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:49:25 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:22:05 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (1);
	return (1 + ft_list_size(begin_list->next));
}

t_list	*at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL || nbr == 0)
		return (begin_list);
	return (at(begin_list->next, nbr - 1));
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*current;
	void	*temp;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		temp = at(begin_list, i)->data;
		at(begin_list, i)->data = at(begin_list, size - 1 - i)->data;
		at(begin_list, size - 1 - i)->data = temp;
		i++;
	}
}
/*
#include <stdio.h>
int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	list->next->next = ft_create_elem("!");
	ft_list_reverse_fun(list);
	printf("%s\n%s\n%s\n%p", (char *) list->data, (char *) list->next->data,
		(char *) list->next->next->data, list->next->next->next);
}*/