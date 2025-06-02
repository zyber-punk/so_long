/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:53 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 17:58:08 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_wall_and_tree_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->tex_wall_outline[i])
			mlx_destroy_image(game->mlx, game->tex_wall_outline[i]);
		if (game->tex_tree[i])
			mlx_destroy_image(game->mlx, game->tex_tree[i]);
		i++;
	}
}

void	destroy_player_textures_part1(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex_player[i][0][0])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][0]);
		if (game->tex_player[i][0][1])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][1]);
		if (game->tex_player[i][0][2])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][2]);
		if (game->tex_player[i][0][3])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][3]);
		if (game->tex_player[i][0][4])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][4]);
		if (game->tex_player[i][0][5])
			mlx_destroy_image(game->mlx, game->tex_player[i][0][5]);
		i++;
	}
}

void	destroy_player_textures_part2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex_player[i][1][0])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][0]);
		if (game->tex_player[i][1][1])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][1]);
		if (game->tex_player[i][1][2])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][2]);
		if (game->tex_player[i][1][3])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][3]);
		if (game->tex_player[i][1][4])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][4]);
		if (game->tex_player[i][1][5])
			mlx_destroy_image(game->mlx, game->tex_player[i][1][5]);
		i++;
	}
}
