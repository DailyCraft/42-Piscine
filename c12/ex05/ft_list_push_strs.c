/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:29:12 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/05 13:33:41 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*current;

	i = 1;
	list = ft_create_elem(strs[0]);
	while (i < size)
	{
		current = ft_create_elem(strs[i]);
		list->next = current;
		list = current;
		i++;
	}
	return (list);
}