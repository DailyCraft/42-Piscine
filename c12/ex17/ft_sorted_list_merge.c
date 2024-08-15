/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:56:47 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:19:32 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	**current;
	t_list	*temp;

	current = begin_list1;
	while (*current != NULL)
	{
		if (begin_list2 == NULL)
			return ;
		if (cmp((*current)->data, begin_list2->data) > 0)
		{
			temp = *current;
			*current = begin_list2;
			begin_list2 = begin_list2->next;
			(*current)->next = temp;
		}
		current = &(*current)->next;
	}
	if (begin_list2 != NULL)
	{
		if (*current == NULL)
			*current = begin_list2;
		else
			(*current)->next = begin_list2;
	}
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	t_list *a = ft_create_elem("a");
	a->next = ft_create_elem("b");
	a->next->next = ft_create_elem("e");
	a->next->next->next = ft_create_elem("g");
	
	t_list *b = ft_create_elem("");
	b->next = ft_create_elem("c");
	b->next->next = ft_create_elem("d");
	b->next->next->next = ft_create_elem("f");
	
	ft_sorted_list_merge(&a, b, strcmp);
	printf("%s\n", (char *) a->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
	printf("%s\n", (char *) (a = a->next)->data);
}*/