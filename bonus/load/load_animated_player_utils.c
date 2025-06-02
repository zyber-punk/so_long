/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animated_player_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:58:48 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:10 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_animated_frame(char *path, int *i, int frame)
{
	path[*i] = '_';
	(*i)++;
	path[*i] = frame + '0';
	(*i)++;
}

void	build_animated_path(char *path, int dir,
		int frame, const char *directions[])
{
	int	i;

	path[0] = '\0';
	i = 0;
	copy_animated_base(path, &i);
	copy_animated_direction(path, &i, dir, directions);
	copy_animated_middle(path, &i);
	copy_animated_direction(path, &i, dir, directions);
	add_animated_frame(path, &i, frame);
	copy_animated_end(path, &i);
	path[i] = '\0';
}

void	handle_animated_texture_error(void *texture)
{
	if (!texture)
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load player animated texture\n", 38);
	}
}

int	load_animated_texture(t_player_load *load)
{
	void	*texture;

	texture = mlx_xpm_file_to_image(load->game->mlx, load->path,
			&load->tex_w, &load->tex_h);
	load->game->tex_player[load->dir][1][load->frame] = texture;
	handle_animated_texture_error(texture);
	return (!texture);
}
