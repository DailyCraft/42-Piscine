/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:08:12 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/08/13 14:18:33 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sort(int argc, char **argv)
{
	int		modified;
	int		i;
	char	*temp;

	modified = 1;
	while (modified)
	{
		modified = 0;
		i = 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				temp = argv[i - 1];
				argv[i - 1] = argv[i];
				argv[i] = temp;
				modified = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort(argc - 1, argv + 1);
	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			ft_putchar(*argv[i]++);
		ft_putchar('\n');
		i++;
	}
}
