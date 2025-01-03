/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:15 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 16:10:46 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*current;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	current = *begin_list;
	while (current->next != NULL)
		current = current->next;
	current->next = ft_create_elem(data);
}
/*
int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	ft_list_push_back(&list, "!");
	list = NULL;
	ft_list_push_back(&list, "Hello");
}*/