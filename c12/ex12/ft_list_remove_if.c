/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:02:53 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 21:20:21 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	**list_ptr_ptr;

	list_ptr = *begin_list;
	list_ptr_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if (cmp(list_ptr->data, data_ref) == 0)
		{
			free_fct(list_ptr->data);
			*list_ptr_ptr = list_ptr->next;
			free(list_ptr);
			list_ptr = *list_ptr_ptr;
		}
		else
		{
			list_ptr_ptr = &list_ptr->next;
			list_ptr = *list_ptr_ptr;
		}
	}
}
/*
int valid(void *s1, void *s2)
{
	return *((char *) s1) - *((char *) s2);
}

void fct(void *data)
{	
}

int main()
{
	t_list *list = ft_create_elem("hello");
	list->next = ft_create_elem("Hello");
	list->next->next = ft_create_elem("Hello!");
	list->next->next->next = ft_create_elem("hello");
	ft_list_remove_if(&list, "H", valid, fct);
}*/