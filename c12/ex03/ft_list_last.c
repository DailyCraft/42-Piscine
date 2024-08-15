/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:18:46 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 16:04:35 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}
/*
int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	list->next->next = ft_create_elem("!");
	t_list *last = ft_list_last(list);
}*/