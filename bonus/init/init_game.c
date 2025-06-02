/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:14:30 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/10 01:11:59 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	init_map(t_game *game, char *map_file)
{
	game->map = read_map(map_file);
	if (!game->map)
		return (1);
	if (!check_map(game->map))
	{
		free_map(game->map);
		return (1);
	}
	return (0);
}

static int	init_map_dimensions(t_game *game)
{
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	if (game->map_width * TILE_SIZE <= 0 || game->map_height * TILE_SIZE <= 0)
	{
		write(1, "Error\n", 6);
		write(1, "Map size is too large\n", 22);
		free_map(game->map);
		return (1);
	}
	return (0);
}

static int	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		return (1);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free_map(game->map);
		destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	return (0);
}

int	init_game(t_game *game, char *map_file)
{
	if (init_map(game, map_file))
		return (1);
	if (init_map_dimensions(game))
		return (1);
	if (init_mlx_window(game))
		return (1);
	if (init_maps(game))
		return (1);
	return (0);
}
