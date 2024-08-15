/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:34:11 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/15 14:26:04 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list != NULL)
	{
		ft_list_clear(begin_list->next, free_fct);
		free_fct(begin_list->data);
		free(begin_list);
	}
}
/*
int main()
{
	void *data = malloc(4);
	t_list *list = ft_create_elem(data);
	data = malloc(4);
	list->next = ft_create_elem(data);
	ft_list_clear(list, free);
}*/