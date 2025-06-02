/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:28:18 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 02:29:20 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_environment_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->tex_tree[i])
			mlx_destroy_image(game->mlx, game->tex_tree[i]);
		if (game->tex_wall_outline[i])
			mlx_destroy_image(game->mlx, game->tex_wall_outline[i]);
		game->tex_tree[i] = NULL;
		game->tex_wall_outline[i] = NULL;
		i++;
	}
}

void	free_object_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->tex_floor[i])
			mlx_destroy_image(game->mlx, game->tex_floor[i]);
		game->tex_floor[i] = NULL;
		i++;
	}
	if (game->tex_collectible[0])
		mlx_destroy_image(game->mlx, game->tex_collectible[0]);
	game->tex_collectible[0] = NULL;
	if (game->tex_exit_closed)
		mlx_destroy_image(game->mlx, game->tex_exit_closed);
	game->tex_exit_closed = NULL;
	if (game->tex_exit_open)
		mlx_destroy_image(game->mlx, game->tex_exit_open);
	game->tex_exit_open = NULL;
}

void	free_player_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex_player[i][0][0])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][0]);
		game->tex_player[i][0][0] = NULL;
		i++;
	}
}
