/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:34:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 20:43:57 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		f(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
/*
#include <stdio.h>
void print(void *data)
{
	printf("%s\n", (char *) data);
}

int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	list->next->next = ft_create_elem("!");
	ft_list_foreach(list, print);
}*/