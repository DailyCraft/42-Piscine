/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:13:28 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:54 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

// Return if a string is printable
t_bool	ft_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
