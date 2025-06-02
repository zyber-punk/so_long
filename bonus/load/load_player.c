/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:42:41 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:37 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	process_player_frame(t_frame_params *params)
{
	params->load->frame = params->frame;
	if (params->load->is_static)
		build_static_path(params->load->path, params->dir,
			params->frame, params->directions);
	else
		build_animated_path(params->load->path, params->dir,
			params->frame, params->directions);
	if (check_player_file(params->load->path))
		return (1);
	if (load_player_image(params->load))
		return (1);
	return (0);
}

static int	load_frames_loop(t_frame_params *frame_params)
{
	int	frame;

	frame = 0;
	while (frame < 6)
	{
		frame_params->frame = frame;
		if (process_player_frame(frame_params))
			return (1);
		frame++;
	}
	return (0);
}

static int	load_player_frames(t_frames_params *params)
{
	char			path[100];
	const char		*directions[] = {"down", "left", "right", "up"};
	t_player_load	load;
	t_frame_params	frame_params;
	t_init_params	init_params;

	init_params.load = &load;
	init_params.game = params->game;
	init_params.path = path;
	init_params.dir = params->dir;
	init_params.tex_w = params->tex_w;
	init_params.tex_h = params->tex_h;
	init_params.is_static = params->is_static;
	init_player_load(&init_params);
	init_frame_params(&frame_params, &load, params->dir, directions);
	return (load_frames_loop(&frame_params));
}

int	load_player_textures(t_game *game, int tex_w, int tex_h)
{
	int				dir;
	t_frames_params	params;

	params.game = game;
	params.tex_w = tex_w;
	params.tex_h = tex_h;
	dir = 0;
	while (dir < 4)
	{
		params.dir = dir;
		params.is_static = 1;
		if (load_player_frames(&params))
			return (1);
		params.is_static = 0;
		if (load_player_frames(&params))
			return (1);
		dir++;
	}
	return (0);
}
