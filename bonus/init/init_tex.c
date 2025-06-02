/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:24:25 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:04:59 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->nb_collect = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->nb_collect++;
			x++;
		}
		y++;
	}
}

void	init_player_and_collectibles(t_game *game)
{
	init_player_position(game);
	count_collectibles(game);
	game->collected = 0;
	game->nb_moves = 0;
	game->nb_tree = 8;
	game->nb_floor = 2;
	game->player_anim = 0;
	game->enemy_anim = 0;
	game->coll_anim = 0;
	game->player_direction = 0;
	game->player_moving = 0;
	game->player_alive = 1;
	game->anim_timer = 0;
	game->static_anim_timer = 0;
}

void	init_floor_and_tree_maps(t_game *game)
{
	int				x;
	int				y;
	unsigned int	seed;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			seed = (y * 7919 + x * 3571) * 1103515245 + 12345;
			game->floor_map[y][x] = seed % 2;
			seed = (y * 3571 + x * 7919) * 1103515245 + 12345;
			game->tree_map[y][x] = seed % 8;
			x++;
		}
		y++;
	}
}
