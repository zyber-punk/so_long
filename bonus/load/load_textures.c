/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:34:30 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 18:18:51 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	load_floor_textures(t_game *game, int tex_w, int tex_h)
{
	game->tex_floor[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_0.xpm", &tex_w, &tex_h);
	game->tex_floor[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_1.xpm", &tex_w, &tex_h);
	if (!game->tex_floor[0] || !game->tex_floor[1])
	{
		if (game->tex_floor[0])
			mlx_destroy_image(game->mlx, game->tex_floor[0]);
		if (game->tex_floor[1])
			mlx_destroy_image(game->mlx, game->tex_floor[1]);
		write(1, "Error\n", 6);
		write(1, "Failed to load floor texture\n", 29);
		return (1);
	}
	return (0);
}

static int	load_collectible_textures(t_game *game, int tex_w, int tex_h)
{
	int		i;
	char	path[100];
	char	*base_path;

	i = 0;
	while (i < 6)
	{
		base_path = "textures/collectible/animated/coin_";
		ft_strcpy(path, base_path);
		path[ft_strlen(base_path)] = i + '0';
		ft_strcpy(path + ft_strlen(base_path) + 1, ".xpm");
		game->tex_collectible[i] = mlx_xpm_file_to_image(game->mlx,
				path, &tex_w, &tex_h);
		if (!game->tex_collectible[i])
		{
			while (--i >= 0)
				mlx_destroy_image(game->mlx, game->tex_collectible[i]);
			write(1, "Error\n", 6);
			write(1, "Failed to load collectible texture\n", 34);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	load_map_textures(t_game *game, int tex_w, int tex_h)
{
	if (load_wall_outline_textures(game, tex_w, tex_h))
		return (1);
	if (load_tree_textures(game, tex_w, tex_h))
		return (1);
	if (load_floor_textures(game, tex_w, tex_h))
		return (1);
	if (load_player_textures(game, tex_w, tex_h))
		return (1);
	if (load_enemy_textures(game, tex_w, tex_h))
		return (1);
	if (load_collectible_textures(game, tex_w, tex_h))
		return (1);
	if (load_exit_textures(game, tex_w, tex_h))
		return (1);
	return (0);
}

static int	load_ui_textures(t_game *game, int tex_w, int tex_h)
{
	if (load_digit_textures(game, tex_w, tex_h))
		return (1);
	if (load_tens_textures(game, tex_w, tex_h))
		return (1);
	if (load_hundreds_textures(game, tex_w, tex_h))
		return (1);
	return (0);
}

int	load_textures(t_game *game)
{
	int	tex_w;
	int	tex_h;

	tex_w = 0;
	tex_h = 0;
	if (load_map_textures(game, tex_w, tex_h))
		return (1);
	if (load_ui_textures(game, tex_w, tex_h))
		return (1);
	return (0);
}
