/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:17:56 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:30 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_player_file(char *path)
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

int	load_player_image(t_player_load *load)
{
	if (load->is_static)
		return (load_static_texture(load));
	else
		return (load_animated_texture(load));
}

void	init_player_load(t_init_params *params)
{
	params->load->game = params->game;
	params->load->path = params->path;
	params->load->dir = params->dir;
	params->load->tex_w = params->tex_w;
	params->load->tex_h = params->tex_h;
	params->load->is_static = params->is_static;
}

void	init_frame_params(t_frame_params *frame_params, t_player_load *load,
		int dir, const char *directions[])
{
	frame_params->load = load;
	frame_params->dir = dir;
	frame_params->directions = directions;
}
