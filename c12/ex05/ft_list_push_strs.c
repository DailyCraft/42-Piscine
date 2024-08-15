/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:29:12 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 16:17:47 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*current;

	list = ft_create_elem(strs[0]);
	current = list;
	i = 1;
	while (i < size)
	{
		current->next = ft_create_elem(strs[i]);
		current = current->next;
		i++;
	}
	return (list);
}
/*
int main()
{
	char *strs[] = {"Hello", "world", "!"};
	t_list *list = ft_list_push_strs(3, strs);
}*/