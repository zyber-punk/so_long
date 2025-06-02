/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:34:30 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 02:47:08 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_floor_textures(t_game *game, int tex_w, int tex_h)
{
	game->tex_floor[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_0.xpm", &tex_w, &tex_h);
	game->tex_floor[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_1.xpm", &tex_w, &tex_h);
	if (!game->tex_floor[0] || !game->tex_floor[1])
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load floor texture\n", 29);
		return (1);
	}
	return (0);
}

static int	load_collectible_textures(t_game *game, int tex_w, int tex_h)
{
	game->tex_collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible/coin.xpm", &tex_w, &tex_h);
	if (!game->tex_collectible[0])
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load collectible texture\n", 34);
		return (1);
	}
	return (0);
}

static int	load_exit_textures(t_game *game, int tex_w, int tex_h)
{
	game->tex_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit_close.xpm", &tex_w, &tex_h);
	game->tex_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit_open.xpm", &tex_w, &tex_h);
	if (!game->tex_exit_closed || !game->tex_exit_open)
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load exit texture\n", 28);
		return (1);
	}
	return (0);
}

static int	load_player_textures(t_game *game, int tex_w, int tex_h)
{
	int			dir;

	load_player_images(game, tex_w, tex_h);
	dir = 0;
	while (dir < 4)
	{
		if (!game->tex_player[dir][0][0])
		{
			write(1, "Error\n", 6);
			write(1, "Failed to load player texture\n", 29);
			return (1);
		}
		dir++;
	}
	return (0);
}

int	load_textures(t_game *game)
{
	int	tex_w;
	int	tex_h;

	tex_w = 0;
	tex_h = 0;
	if (load_wall_outline_textures(game, tex_w, tex_h))
		return (1);
	if (load_tree_textures(game, tex_w, tex_h))
		return (1);
	if (load_floor_textures(game, tex_w, tex_h))
		return (1);
	if (load_player_textures(game, tex_w, tex_h))
		return (1);
	if (load_collectible_textures(game, tex_w, tex_h))
		return (1);
	if (load_exit_textures(game, tex_w, tex_h))
		return (1);
	return (0);
}
