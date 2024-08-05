/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:10:46 by pivander          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:09 by pivander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* ******************* */
/*  ---  Boolean  ---  */
/* ******************* */

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/* ********************** */
/*  ---  Dictionary  ---  */
/* ********************** */

typedef struct s_dict
{
	char	*units[20];
	char	*tens[8];
	char	*hundred;
	char	*thousands[12];
}	t_dict;

// Init the dicionary.
void	init_dict(t_dict *dict);
// Set all the values of the array to NULL.
void	clear_array(char *array[], int size);
// Free the allocated memory in s_dict structure.
void	free_dict(t_dict *dict);
// Free the content of a fixed size char array.
void	free_array(char *array[], int size);

/* ****************************** */
/*  ---  Dictionary Parsing  ---  */
/* ****************************** */

// Check if a line is valid.
// Returns:
// 	0: No error
// 	1: Empty line
// 	2: Invalid line
int		check_dict_line(t_dict *dict, char *line);
// Add the parsed entry to the dictionary.
t_bool	add_to_dict(t_dict *dict, char *line_value, int number, int zero_count);
// Parse a line in the dictionary.
t_bool	parse_line(t_dict *dict, char *line);
// Manage lines in the dictionary.
t_bool	dict_line(t_dict *dict, char c);
// Read the dictionary.
t_bool	read_dict(t_dict *dict, int file);
// Parse the dictionary and fill the s_dict structure.
t_bool	parse_dict(t_dict *dict, char *path);

/* ***************************** */
/*  ---  Arguments Parsing  ---  */
/* ***************************** */

// Check if the number is valid.
t_bool	check_number(char *number);
// Parse arguments.
t_bool	parse_args(int argc, char **argv, char **number, t_dict *dict);

/* ********************* */
/*  ---  Utilities  ---  */
/* ********************* */

// Compute the length of a string.
int		ft_strlen(char *str);
// Print the string on the standard output.
void	ft_putstr(char *str);
// Copy a string from src to dest.
char	*ft_strcpy(char *dest, char *src);
// A modified atoi that allows numbers with a lot of 0.
int		ft_atoi(char *str, int limit, int *zero_count);
// Return if the character is a white space.
t_bool	ft_isspace(char c);
// Return if a string is printable
t_bool	ft_is_printable(char *str);
// Print an error message on the error output.
void	error(t_dict *dict, char *type, char *msg);
// Clear a buffer.
void	clear_buf(char *buf, int size);
// Free the current value in an array and replace it by a new value.
void	safe_put_array(char *array[], int index, char *value);
// Remove whitespaces before and after the string.
char	*trim(char *str);

/* ******************* */
/*  ---  Writing  ---  */
/* ******************* */

// Print the result on the standard output.
void	print_result(t_dict *dict, char *number);
// Check if the number is 0.
t_bool	is_zero(char *number);
// Print a value preceding by a space if it is not the first.
void	print_value(char *str);
// Print tens and units.
void	print_units(t_dict *dict, char *number, int index, int length);

#endif
