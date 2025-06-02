/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_outlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:10:49 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:25 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static int	check_wall_outline_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!game->tex_wall_outline[i])
		{
			write(1, "Error\n", 6);
			write(1, "Failed to load wall outline texture\n", 35);
			return (1);
		}
		i++;
	}
	return (0);
}

int	load_wall_outline_textures(t_game *game, int tex_w, int tex_h)
{
	load_wall_outline_images(game, tex_w, tex_h);
	if (check_wall_outline_images(game))
		return (1);
	return (0);
}
