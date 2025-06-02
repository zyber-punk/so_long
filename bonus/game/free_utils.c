/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:43:19 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 03:49:38 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_floor(t_game *game)
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

void	destroy_player(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			k = 0;
			while (k < 6)
			{
				if (game->tex_player[i][j][k])
					mlx_destroy_image(game->mlx, game->tex_player[i][j][k]);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	destroy_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (game->tex_enemy[i][j])
				mlx_destroy_image(game->mlx, game->tex_enemy[i][j]);
			j++;
		}
		i++;
	}
}

void	destroy_collectible(t_game *game)
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

void	destroy_digits(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->tex_digit[i])
			mlx_destroy_image(game->mlx, game->tex_digit[i]);
		i++;
	}
}
