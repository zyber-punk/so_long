/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rectangular.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:39:34 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 16:27:24 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_map_size(char **map, int width, int height)
{
	if (!map || !map[0])
	{
		write(1, "Error\n", 6);
		write(1, "Map is empty\n", 13);
		return (0);
	}
	if (height < 3)
	{
		write(1, "Error\n", 6);
		write(1, "Map must be at least 3 lines high\n", 33);
		return (0);
	}
	if (width < 3)
	{
		write(1, "Error\n", 6);
		write(1, "Map must be at least 3 characters wide\n", 37);
		return (0);
	}
	return (1);
}

static int	check_map_square(int width, int height)
{
	if (width == height)
	{
		write(1, "Error\n", 6);
		write(1, "Map cannot be square\n", 21);
		return (0);
	}
	return (1);
}

static int	check_map_lines(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
		{
			write(1, "Error\n", 6);
			write(1, "Map must be rectangular\n", 24);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_rectangular(char **map)
{
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	if (!check_map_size(map, width, height))
		return (0);
	if (!check_map_square(width, height))
		return (0);
	if (!check_map_lines(map, width))
		return (0);
	return (1);
}
