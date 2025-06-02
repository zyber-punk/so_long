/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:19:37 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:18 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	build_enemy_path(char *path, int dir,
		int frame, const char *directions[])
{
	int	i;

	path[0] = '\0';
	i = 0;
	copy_base_path(path, &i);
	copy_direction(path, &i, dir, directions);
	copy_middle_path(path, &i);
	copy_direction(path, &i, dir, directions);
	add_frame_number(path, &i, frame);
	copy_end_path(path, &i);
	path[i] = '\0';
}

static int	check_enemy_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		write(1, "File does not exist: ", 20);
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
		return (1);
	}
	close(fd);
	return (0);
}

static int	load_enemy_image(t_enemy_load *load)
{
	load->game->tex_enemy[load->dir][load->frame] = mlx_xpm_file_to_image(
			load->game->mlx, load->path, &load->tex_w, &load->tex_h);
	if (!load->game->tex_enemy[load->dir][load->frame])
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load enemy texture\n", 29);
		return (1);
	}
	return (0);
}

static int	load_enemy_direction(t_game *game, int dir, int tex_w, int tex_h)
{
	int				frame;
	char			path[100];
	const char		*directions[] = {"down", "left", "right", "up"};
	t_enemy_load	load;

	load.game = game;
	load.path = path;
	load.dir = dir;
	load.tex_w = tex_w;
	load.tex_h = tex_h;
	frame = 0;
	while (frame < 4)
	{
		load.frame = frame;
		build_enemy_path(path, dir, frame, directions);
		if (check_enemy_file(path))
			return (1);
		if (load_enemy_image(&load))
			return (1);
		frame++;
	}
	return (0);
}

int	load_enemy_textures(t_game *game, int tex_w, int tex_h)
{
	int	dir;

	dir = 0;
	while (dir < 4)
	{
		if (load_enemy_direction(game, dir, tex_w, tex_h))
			return (1);
		dir++;
	}
	return (0);
}
