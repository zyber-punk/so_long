/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_static_player_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:49:02 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:45 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_static_frame(char *path, int *i, int frame)
{
	path[*i] = '_';
	(*i)++;
	path[*i] = frame + '0';
	(*i)++;
}

void	build_static_path(char *path, int dir,
		int frame, const char *directions[])
{
	int	i;

	path[0] = '\0';
	i = 0;
	copy_static_base(path, &i);
	copy_static_direction(path, &i, dir, directions);
	copy_static_middle(path, &i);
	copy_static_direction(path, &i, dir, directions);
	add_static_frame(path, &i, frame);
	copy_static_end(path, &i);
	path[i] = '\0';
}

void	handle_static_texture_error(void *texture, char *path)
{
	if (!texture)
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load texture: ", 23);
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
	}
}

int	load_static_texture(t_player_load *load)
{
	void	*texture;

	texture = mlx_xpm_file_to_image(load->game->mlx, load->path,
			&load->tex_w, &load->tex_h);
	load->game->tex_player[load->dir][0][load->frame] = texture;
	handle_static_texture_error(texture, load->path);
	return (!texture);
}
