/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:46:28 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 03:46:43 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_wall_outline(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->tex_wall_outline[i])
			mlx_destroy_image(game->mlx, game->tex_wall_outline[i]);
		i++;
	}
}

void	destroy_tree(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->tex_tree[i])
			mlx_destroy_image(game->mlx, game->tex_tree[i]);
		i++;
	}
}
