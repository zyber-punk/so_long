/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:01:11 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 03:04:23 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_top_wall(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			write(1, "Error\n", 6);
			write(1, "Map must be surrounded by walls\n", 32);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_bottom_wall(char **map, int height)
{
	int	i;

	i = 0;
	while (map[height - 1][i])
	{
		if (map[height - 1][i] != '1')
		{
			write(1, "Error\n", 6);
			write(1, "Map must be surrounded by walls\n", 32);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_side_walls(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			write(1, "Error\n", 6);
			write(1, "Map must be surrounded by walls\n", 32);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_walls(char **map)
{
	int	width;
	int	height;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	if (!check_top_wall(map))
		return (0);
	if (!check_bottom_wall(map, height))
		return (0);
	if (!check_side_walls(map, width))
		return (0);
	return (1);
}
