/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:41:49 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:28:49 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if (cmp(list_ptr->data, data_ref) == 0)
			f(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
/*
#include <stdio.h>
#include <string.h>
void print(void *data)
{
	printf("%s\n", (char *) data);
}

int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("hello");
	list->next->next = ft_create_elem("Hello!");
	ft_list_foreach_if(list, print, "Hello", strcmp);
}*/