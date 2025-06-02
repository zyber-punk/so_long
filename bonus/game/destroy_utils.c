/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:54:11 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 17:55:21 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_enemy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex_enemy[i][0])
			mlx_destroy_image(game->mlx, game->tex_enemy[i][0]);
		if (game->tex_enemy[i][1])
			mlx_destroy_image(game->mlx, game->tex_enemy[i][1]);
		if (game->tex_enemy[i][2])
			mlx_destroy_image(game->mlx, game->tex_enemy[i][2]);
		if (game->tex_enemy[i][3])
			mlx_destroy_image(game->mlx, game->tex_enemy[i][3]);
		i++;
	}
}

void	destroy_collectible_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->tex_collectible[i])
			mlx_destroy_image(game->mlx, game->tex_collectible[i]);
		i++;
	}
}

void	destroy_exit_textures(t_game *game)
{
	if (game->tex_exit_closed)
		mlx_destroy_image(game->mlx, game->tex_exit_closed);
	if (game->tex_exit_open)
		mlx_destroy_image(game->mlx, game->tex_exit_open);
}

void	destroy_digit_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->tex_digit[i])
			mlx_destroy_image(game->mlx, game->tex_digit[i]);
		if (game->tex_tens[i])
			mlx_destroy_image(game->mlx, game->tex_tens[i]);
		if (game->tex_hundreds[i])
			mlx_destroy_image(game->mlx, game->tex_hundreds[i]);
		i++;
	}
}

void	destroy_floor_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->tex_floor[i])
			mlx_destroy_image(game->mlx, game->tex_floor[i]);
		i++;
	}
}
