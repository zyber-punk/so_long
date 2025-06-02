/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:18:01 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/10 01:17:01 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_empty_lines(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			write(1, "Error\n", 6);
			write(1, "Map contains empty lines\n", 25);
			return (0);
		}
		i++;
	}
	if (map_str[0] == '\n' || map_str[ft_strlen(map_str) - 1] == '\n')
	{
		write(1, "Error\n", 6);
		write(1, "Map contains empty lines\n", 25);
		return (0);
	}
	return (1);
}

static char	**process_map(char *map_str)
{
	char	**map;

	if (!check_empty_lines(map_str))
	{
		free(map_str);
		return (NULL);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

char	**read_map(char *filename)
{
	int		fd;
	char	*map_str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		write(1, "Map not found\n", 14);
		return (NULL);
	}
	map_str = ft_strdup("");
	if (!map_str)
		return (NULL);
	if (!read_file(fd, &map_str))
	{
		free(map_str);
		close(fd);
		write(1, "Error\n", 6);
		write(1, "Map file is empty\n", 18);
		return (NULL);
	}
	close(fd);
	map = process_map(map_str);
	return (map);
}

int	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1')
		return (1);
	if (map[y][x] == 'C')
		map[y][x] = 'V';
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return (1);
	}
	else
		map[y][x] = '1';
	if (!flood_fill(map, x + 1, y))
		return (0);
	if (!flood_fill(map, x - 1, y))
		return (0);
	if (!flood_fill(map, x, y + 1))
		return (0);
	if (!flood_fill(map, x, y - 1))
		return (0);
	return (1);
}

int	check_map(char **map)
{
	if (!check_map_rectangular(map))
		return (0);
	if (!check_map_characters(map))
		return (0);
	if (!check_map_elements(map))
		return (0);
	if (!check_map_walls(map))
		return (0);
	if (!check_valid_path(map))
		return (0);
	return (1);
}
