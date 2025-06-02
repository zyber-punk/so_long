/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:38:51 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:04:39 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

	tex_player = game->tex_player[game->player_direction]
	[game->player_moving][game->player_anim];
	draw_texture(game, tex_player, x, y);
}

static void	render_collectible(t_game *game, int x, int y)
{
	void	*tex_collect;

	tex_collect = game->tex_collectible[game->coll_anim];
	draw_texture(game, tex_collect, x, y);
}

static void	render_enemy(t_game *game, int x, int y)
{
	int		i;
	int		anim_index;
	void	*tex_enemy;

	i = 0;
	while (i < game->nb_enemies)
	{
		if (game->enemies[i].x == x && game->enemies[i].y == y)
		{
			if (game->enemies[i].moving)
				anim_index = game->enemies[i].anim;
			else
				anim_index = 0;
			tex_enemy = game->tex_enemy[game->enemies[i].direction][anim_index];
			draw_texture(game, tex_enemy, x, y);
			break ;
		}
		i++;
	}
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
			else if (cell == 'M')
				render_enemy(game, x, y);
		}
	}
	render_moves(game);
}
