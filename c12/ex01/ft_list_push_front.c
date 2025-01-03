/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:10:31 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 16:11:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_begin;

	new_begin = ft_create_elem(data);
	new_begin->next = *begin_list;
	*begin_list = new_begin;
}
/*
int main()
{
	t_list *list = ft_create_elem("Hello");
	ft_list_push_front(&list, "world!");
	list = 0;
	ft_list_push_front(&list, "Hello");
}*/