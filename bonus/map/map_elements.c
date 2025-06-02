/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:45:51 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 16:23:06 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	count_elements(char **map, int *counts)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				counts[0]++;
			if (map[i][j] == 'P')
				counts[1]++;
			if (map[i][j] == 'C')
				counts[2]++;
			j++;
		}
		i++;
	}
}

static int	check_exit(int exit_count)
{
	if (exit_count != 1)
	{
		write(1, "Error\n", 6);
		write(1, "Map must contain exactly one exit\n", 34);
		return (0);
	}
	return (1);
}

static int	check_player(int player_count)
{
	if (player_count != 1)
	{
		write(1, "Error\n", 6);
		write(1, "Map must contain exactly one player\n", 36);
		return (0);
	}
	return (1);
}

static int	check_collectibles(int collectible_count)
{
	if (collectible_count < 1)
	{
		write(1, "Error\n", 6);
		write(1, "Map must contain at least one collectible\n", 42);
		return (0);
	}
	return (1);
}

int	check_map_elements(char **map)
{
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	count_elements(map, counts);
	if (!check_exit(counts[0]))
		return (0);
	if (!check_player(counts[1]))
		return (0);
	if (!check_collectibles(counts[2]))
		return (0);
	return (1);
}
