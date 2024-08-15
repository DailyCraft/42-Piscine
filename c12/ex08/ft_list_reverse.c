/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:06:35 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 17:33:26 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*result;
	t_list	*current;
	t_list	*temp;

	result = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		temp = current->next;
		current->next = result;
		result = current;
		current = temp;
	}
	*begin_list = result;
}
/*
#include <stdio.h>
int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	list->next->next = ft_create_elem("!");
	ft_list_reverse(&list);
	printf("%s\n%s\n%s\n%p", (char *) list->data, (char *) list->next->data,
		(char *) list->next->next->data, list->next->next->next);
}*/