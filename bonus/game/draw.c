/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:16:05 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:04:07 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_texture(t_game *game, void *tex, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		tex, x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_horizontal_walls(t_game *game, int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
			draw_texture(game, game->tex_wall_outline[4], x, y);
		else if (x == game->map_width - 1)
			draw_texture(game, game->tex_wall_outline[5], x, y);
		else
			draw_texture(game, game->tex_wall_outline[0], x, y);
	}
	else if (y == game->map_height - 1)
	{
		if (x == 0)
			draw_texture(game, game->tex_wall_outline[6], x, y);
		else if (x == game->map_width - 1)
			draw_texture(game, game->tex_wall_outline[7], x, y);
		else
			draw_texture(game, game->tex_wall_outline[1], x, y);
	}
}

static void	draw_vertical_walls(t_game *game, int x, int y)
{
	if (x == 0)
		draw_texture(game, game->tex_wall_outline[2], x, y);
	else if (x == game->map_width - 1)
		draw_texture(game, game->tex_wall_outline[3], x, y);
	else
		draw_texture(game, game->tex_tree[game->tree_map[y][x]], x, y);
}

void	draw_wall(t_game *game, int x, int y)
{
	if (y == 0 || y == game->map_height - 1)
		draw_horizontal_walls(game, x, y);
	else
		draw_vertical_walls(game, x, y);
}
