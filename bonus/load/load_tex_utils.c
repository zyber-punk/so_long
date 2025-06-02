/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:19:12 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 18:19:35 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_exit_textures(t_game *game, int tex_w, int tex_h)
{
	game->tex_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit_close.xpm", &tex_w, &tex_h);
	game->tex_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit_open.xpm", &tex_w, &tex_h);
	if (!game->tex_exit_closed || !game->tex_exit_open)
	{
		if (game->tex_exit_closed)
			mlx_destroy_image(game->mlx, game->tex_exit_closed);
		if (game->tex_exit_open)
			mlx_destroy_image(game->mlx, game->tex_exit_open);
		write(1, "Error\n", 6);
		write(1, "Failed to load exit texture\n", 28);
		return (1);
	}
	return (0);
}

int	load_digit_textures(t_game *game, int tex_w, int tex_h)
{
	int		i;
	char	path[100];
	char	*base_path;

	i = 0;
	while (i < 10)
	{
		base_path = "textures/digits/units/";
		ft_strcpy(path, base_path);
		path[ft_strlen(base_path)] = i + '0';
		ft_strcpy(path + ft_strlen(base_path) + 1, "_units.xpm");
		game->tex_digit[i] = mlx_xpm_file_to_image(game->mlx,
				path, &tex_w, &tex_h);
		if (!game->tex_digit[i])
		{
			while (--i >= 0)
				mlx_destroy_image(game->mlx, game->tex_digit[i]);
			write(1, "Error\n", 6);
			write(1, "Failed to load digit texture\n", 29);
			return (1);
		}
		i++;
	}
	return (0);
}

int	load_tens_textures(t_game *game, int tex_w, int tex_h)
{
	int		i;
	char	path[100];
	char	*base_path;

	i = 0;
	while (i < 10)
	{
		base_path = "textures/digits/tens/";
		ft_strcpy(path, base_path);
		path[ft_strlen(base_path)] = i + '0';
		ft_strcpy(path + ft_strlen(base_path) + 1, "_tens.xpm");
		game->tex_tens[i] = mlx_xpm_file_to_image(game->mlx,
				path, &tex_w, &tex_h);
		if (!game->tex_tens[i])
		{
			while (--i >= 0)
				mlx_destroy_image(game->mlx, game->tex_tens[i]);
			write(1, "Error\n", 6);
			write(1, "Failed to load tens texture\n", 28);
			return (1);
		}
		i++;
	}
	return (0);
}

int	load_hundreds_textures(t_game *game, int tex_w, int tex_h)
{
	int		i;
	char	path[100];
	char	*base_path;

	i = 0;
	while (i < 10)
	{
		base_path = "textures/digits/hundreds/";
		ft_strcpy(path, base_path);
		path[ft_strlen(base_path)] = i + '0';
		ft_strcpy(path + ft_strlen(base_path) + 1, "_hundreds.xpm");
		game->tex_hundreds[i] = mlx_xpm_file_to_image(game->mlx,
				path, &tex_w, &tex_h);
		if (!game->tex_hundreds[i])
		{
			while (--i >= 0)
				mlx_destroy_image(game->mlx, game->tex_hundreds[i]);
			write(1, "Error\n", 6);
			write(1, "Failed to load hundreds texture\n", 31);
			return (1);
		}
		i++;
	}
	return (0);
}
