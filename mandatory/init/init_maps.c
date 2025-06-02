/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:16:56 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 20:55:26 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game_resources(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	destroy_display(game->mlx);
	free(game->mlx);
}

static int	allocate_main_arrays(t_game *game)
{
	game->floor_map = malloc(sizeof(int *) * game->map_height);
	game->tree_map = malloc(sizeof(int *) * game->map_height);
	if (!game->floor_map || !game->tree_map)
	{
		free_game_resources(game);
		return (1);
	}
	return (0);
}

static int	allocate_sub_arrays(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		game->floor_map[i] = malloc(sizeof(int) * game->map_width);
		game->tree_map[i] = malloc(sizeof(int) * game->map_width);
		if (!game->floor_map[i] || !game->tree_map[i])
		{
			while (i > 0)
			{
				free(game->floor_map[--i]);
				free(game->tree_map[i]);
			}
			free(game->floor_map);
			free(game->tree_map);
			free_game_resources(game);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_maps(t_game *game)
{
	if (allocate_main_arrays(game))
		return (1);
	if (allocate_sub_arrays(game))
		return (1);
	return (0);
}
