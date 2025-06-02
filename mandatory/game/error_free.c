/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:36:11 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 02:28:59 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_background_maps(t_game *game)
{
	int	i;

	if (!game->floor_map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		free(game->floor_map[i]);
		free(game->tree_map[i]);
		i++;
	}
	free(game->floor_map);
	free(game->tree_map);
	game->floor_map = NULL;
	game->tree_map = NULL;
}

void	free_game(t_game *game)
{
	free_background_maps(game);
	free_map(game->map);
	game->map = NULL;
	free_environment_textures(game);
	free_object_textures(game);
	free_player_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	if (game->mlx)
	{
		destroy_display(game->mlx);
		free(game->mlx);
	}
	game->mlx = NULL;
}

int	exit_game(t_game *game)
{
	if (game->player_alive)
	{
		free_game(game);
		exit(0);
	}
	return (0);
}

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}
