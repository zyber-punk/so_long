/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:05:37 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 16:22:47 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				write(1, "Error\n", 6);
				write(1, "Map contains invalid characters\n", 32);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'C' && map[i][j] != 'E' &&
				map[i][j] != 'P' && map[i][j] != 'M')
			{
				write(1, "Error\n", 6);
				write(1, "Map contains invalid characters\n", 32);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_empty_space(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (1);
			j++;
		}
		i++;
	}
	write(1, "Error\n", 6);
	write(1, "Map must contain at least one empty space\n", 42);
	return (0);
}

int	check_map_characters(char **map)
{
	if (!check_spaces(map))
		return (0);
	if (!check_valid_chars(map))
		return (0);
	if (!check_empty_space(map))
		return (0);
	return (1);
}
