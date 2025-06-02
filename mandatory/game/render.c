/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:38:51 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 02:38:09 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor_exit(t_game *game, int x, int y, char cell)
{
	void	*tex;

	draw_texture(game, game->tex_floor[game->floor_map[y][x]], x, y);
	if (cell == 'E')
	{
		if (game->collected == game->nb_collect)
			tex = game->tex_exit_open;
		else
			tex = game->tex_exit_closed;
		draw_texture(game, tex, x, y);
	}
}

static void	render_player(t_game *game, int x, int y)
{
	void	*tex_player;

	tex_player = game->tex_player[game->player_direction][0][0];
	draw_texture(game, tex_player, x, y);
}

static void	render_collectible(t_game *game, int x, int y)
{
	draw_texture(game, game->tex_collectible[0], x, y);
}

void	render_game(t_game *game)
{
	int		x;
	int		y;
	char	cell;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			cell = game->map[y][x];
			render_floor_exit(game, x, y, cell);
			if (cell == '1')
				draw_wall(game, x, y);
			else if (cell == 'P')
				render_player(game, x, y);
			else if (cell == 'C')
				render_collectible(game, x, y);
		}
	}
}

void	load_player_images(t_game *game, int tex_w, int tex_h)
{
	int			dir;

	dir = 0;
	while (dir < 4)
	{
		if (dir == 0)
			game->tex_player[dir][0][0] = mlx_xpm_file_to_image(game->mlx,
					"textures/character/static/pepe_down.xpm", &tex_w, &tex_h);
		else if (dir == 1)
			game->tex_player[dir][0][0] = mlx_xpm_file_to_image(game->mlx,
					"textures/character/static/pepe_left.xpm", &tex_w, &tex_h);
		else if (dir == 2)
			game->tex_player[dir][0][0] = mlx_xpm_file_to_image(game->mlx,
					"textures/character/static/pepe_right.xpm", &tex_w, &tex_h);
		else if (dir == 3)
			game->tex_player[dir][0][0] = mlx_xpm_file_to_image(game->mlx,
					"textures/character/static/pepe_up.xpm", &tex_w, &tex_h);
		dir++;
	}
}
