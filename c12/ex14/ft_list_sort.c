/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:29:52 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 21:46:51 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		modified;
	t_list	*current;
	void	*temp;

	if (*begin_list == NULL)
		return ;
	modified = 1;
	while (modified)
	{
		modified = 0;
		current = *begin_list;
		while (current->next != NULL)
		{
			if (cmp(current->data, current->next->data) > 0)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				modified = 1;
			}
			current = current->next;
		}
	}
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	t_list *list = ft_create_elem("z");
	list->next = ft_create_elem("a");
	list->next->next = ft_create_elem("z");
	list->next->next->next = ft_create_elem("xx");
	ft_list_sort(&list, strcmp);
	printf("%s\n%s\n%s\n%s\n", (char *) list->data, (char *) list->next->data,
		(char *) list->next->next->data, (char *) list->next->next->next->data);
}*/