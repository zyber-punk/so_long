/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:15:47 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 02:46:16 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		free_game(game);
		return (1);
	}
	return (0);
}

static void	load_wall_outline_images(t_game *game, int tex_w, int tex_h)
{
	game->tex_wall_outline[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_top.xpm", &tex_w, &tex_h);
	game->tex_wall_outline[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_bottom.xpm", &tex_w, &tex_h);
	game->tex_wall_outline[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_left.xpm", &tex_w, &tex_h);
	game->tex_wall_outline[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_right.xpm", &tex_w, &tex_h);
	game->tex_wall_outline[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_angle_top_left.xpm",
			&tex_w, &tex_h);
	game->tex_wall_outline[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_angle_top_right.xpm",
			&tex_w, &tex_h);
	game->tex_wall_outline[6] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_angle_bottom_left.xpm",
			&tex_w, &tex_h);
	game->tex_wall_outline[7] = mlx_xpm_file_to_image(game->mlx,
			"textures/walls_outlines/wall_outline_angle_bottom_right.xpm",
			&tex_w, &tex_h);
}

int	load_wall_outline_textures(t_game *game, int tex_w, int tex_h)
{
	load_wall_outline_images(game, tex_w, tex_h);
	if (!game->tex_wall_outline[0] || !game->tex_wall_outline[1]
		|| !game->tex_wall_outline[2] || !game->tex_wall_outline[3]
		|| !game->tex_wall_outline[4] || !game->tex_wall_outline[5]
		|| !game->tex_wall_outline[6] || !game->tex_wall_outline[7])
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load wall outline texture\n", 35);
		free_game(game);
		return (1);
	}
	return (0);
}
