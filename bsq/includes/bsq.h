/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:24:22 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/06 23:16:26 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	empty;
	char	wall;
	char	fill;
	int		width;
	int		height;
	char	*slots;
	int		**walls;
	int		wall_count;
}	t_map;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

// Map
void		populate_map_walls(t_map *map, int count);
void		free_map(t_map *map);

// Utils
char		*ft_realloc(char *src, char c);
int			ft_strlen(char *str);
int			ft_char_is_printable(char c);
int			get_min(int a, int b);
void		ft_reset_square(t_square *square, int val);

// Parsing
char		get_map_info(int fd, t_map *map);
int			ft_fill_slots(t_map *map, int fd);

// Solving
t_square	solve(t_map *map);

// Printing
void		print(t_map *map, t_square *square);

#endif
