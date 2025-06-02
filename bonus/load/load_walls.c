/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:15:47 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:53 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_tree_images(t_game *game, int tex_w, int tex_h)
{
	game->tex_tree[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_1.xpm", &tex_w, &tex_h);
	game->tex_tree[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_2.xpm", &tex_w, &tex_h);
	game->tex_tree[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_3.xpm", &tex_w, &tex_h);
	game->tex_tree[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_4.xpm", &tex_w, &tex_h);
	game->tex_tree[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_apple_1.xpm", &tex_w, &tex_h);
	game->tex_tree[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_apple_2.xpm", &tex_w, &tex_h);
	game->tex_tree[6] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_apple_3.xpm", &tex_w, &tex_h);
	game->tex_tree[7] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls/tree_apple_4.xpm", &tex_w, &tex_h);
}

static int	check_tree_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!game->tex_tree[i])
		{
			write(1, "Error\n", 6);
			write(1, "Failed to load tree texture\n", 28);
			return (1);
		}
		i++;
	}
	return (0);
}

int	load_tree_textures(t_game *game, int tex_w, int tex_h)
{
	load_tree_images(game, tex_w, tex_h);
	if (check_tree_images(game))
		return (1);
	return (0);
}
