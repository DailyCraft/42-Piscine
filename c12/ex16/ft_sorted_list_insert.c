/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:33:56 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:05:52 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	**current;
	t_list	*temp;

	current = begin_list;
	while (*current != NULL)
	{
		if (cmp((*current)->data, data) > 0)
		{
			temp = *current;
			*current = ft_create_elem(data);
			(*current)->next = temp;
			return ;
		}
		current = &(*current)->next;
	}
	temp = *current;
	*current = ft_create_elem(data);
	(*current)->next = temp;
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	t_list *list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	ft_sorted_list_insert(&list, "d", strcmp);
	printf("%s\n%s\n%s\n%s\n", (char *) list->data, (char *) list->next->data,
		(char *) list->next->next->data, (char *) list->next->next->next->data);
}*/