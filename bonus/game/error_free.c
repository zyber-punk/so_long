/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:18:44 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 17:57:38 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	destroy_textures(t_game *game)
{
	destroy_wall_and_tree_textures(game);
	destroy_floor_textures(game);
	destroy_player_textures_part1(game);
	destroy_player_textures_part2(game);
	destroy_enemy_textures(game);
	destroy_collectible_textures(game);
	destroy_exit_textures(game);
	destroy_digit_textures(game);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->floor_map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->floor_map[i]);
			free(game->tree_map[i]);
			i++;
		}
		free(game->floor_map);
		free(game->tree_map);
	}
	free_map(game->map);
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
