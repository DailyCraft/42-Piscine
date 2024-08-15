/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:24:06 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 16:41:06 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL || nbr == 0)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}
/*
#include <stdio.h>
int main()
{
	t_list *list = ft_create_elem("Hello");
	list->next = ft_create_elem("world");
	list->next->next = ft_create_elem("!");
	t_list *at = ft_list_at(list, 2);
	printf("%p\n", at);
	if (at != NULL)
		printf("%s", (char *) at->data);
}*/