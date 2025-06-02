/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:52:51 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 03:04:39 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (ft_strlen(map[0]) + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	find_player_position(char **map, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	check_flood_fill(char **map_copy, int player_x, int player_y)
{
	if (!flood_fill(map_copy, player_x, player_y))
	{
		write(1, "Error\n", 6);
		write(1, "No valid path to exit and collectibles\n", 37);
		return (0);
	}
	return (1);
}

static int	check_unreachable(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				write(1, "Error\n", 6);
				write(1, "Some collectibles or exit are unreachable\n", 42);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(char **map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	find_player_position(map, &player_x, &player_y);
	if (!check_flood_fill(map_copy, player_x, player_y))
	{
		free_map_copy(map_copy);
		return (0);
	}
	if (!check_unreachable(map_copy))
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}
