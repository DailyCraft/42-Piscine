/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:57:47 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/07/21 13:29:29 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char	*dest, char *src);
void	error(char *error);
void	print_rush(int x, int y, char *format);
void	rush(int x, int y);

/**
 * Init the format of the rush pattern according to the rush id.
 */
int	init_format(char *rush_id, char *format)
{
	if (ft_strcmp(rush_id, "rush00") == 0 || ft_atoi(rush_id) == 0)
		ft_strcpy(format, "oooo-|");
	else if (ft_strcmp(rush_id, "rush01") == 0 || ft_atoi(rush_id) == 1)
		ft_strcpy(format, "/\\\\/**");
	else if (ft_strcmp(rush_id, "rush02") == 0 || ft_atoi(rush_id) == 2)
		ft_strcpy(format, "AACCBB");
	else if (ft_strcmp(rush_id, "rush03") == 0 || ft_atoi(rush_id) == 3)
		ft_strcpy(format, "ACACBB");
	else if (ft_strcmp(rush_id, "rush04") == 0 || ft_atoi(rush_id) == 4)
		ft_strcpy(format, "ACCABB");
	else
	{
		error("L'identifiant du rush n'existe pas !\n");
		error("The rush id doesn't exist!");
		return (1);
	}
	return (0);
}

/**
 * The main function of the program.
 */
int	main(int argc, char **argv)
{
	char	format[7];

	if (argc == 1)
		rush(4, 4);
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (argc == 4)
	{
		if (init_format(argv[1], format) == 1)
			return (0);
		print_rush(ft_atoi(argv[2]), ft_atoi(argv[3]), format);
	}
	else
	{
		error("Les arguments doivent être de la forme: ");
		error("[rush0X (rush04 par défaut)] <x> <y>\n");
		error("The program arguments must be: ");
		error("[rush0X (rush04 by default)] <x> <y>");
	}
	return (0);
}
