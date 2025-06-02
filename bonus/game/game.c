/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:18:44 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/14 16:37:01 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	handle_player_collision(t_game *game, char cell)
{
	if (cell == '1' || cell == 'M')
	{
		if (cell == 'M')
		{
			game->player_alive = 0;
			write(1, "Game over!\n", 10);
			free_game(game);
			exit(0);
		}
		game->player_moving = 0;
		return (1);
	}
	return (0);
}

static int	handle_exit_and_collectible(t_game *game, char cell)
{
	if (cell == 'E' && game->collected != game->nb_collect)
	{
		game->player_moving = 0;
		return (1);
	}
	if (cell == 'C')
		game->collected++;
	if (cell == 'E' && game->collected == game->nb_collect)
	{
		write(1, "You win!\n", 9);
		free_game(game);
		exit(0);
	}
	return (0);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->nb_moves++;
	render_game(game);
}

int	key_hook(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;
	char	cell;

	if (!game->player_alive)
		return (0);
	if (keycode == 53 || keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	new_x = game->player_x;
	new_y = game->player_y;
	handle_player_movement(game, keycode, &new_x, &new_y);
	if (!game->player_moving)
		return (0);
	cell = game->map[new_y][new_x];
	if (handle_player_collision(game, cell))
		return (0);
	if (handle_exit_and_collectible(game, cell))
		return (0);
	update_player_position(game, new_x, new_y);
	return (0);
}

int	loop_hook(t_game *game)
{
	static int		coll_timer;
	static int		enemy_move_timer;
	static int		enemy_anim_timer;

	update_player_animation(game);
	coll_timer++;
	if (coll_timer >= 16)
	{
		coll_timer = 0;
		game->coll_anim = (game->coll_anim + 1) % 6;
	}
	update_enemy_animations(game, &enemy_anim_timer, &enemy_move_timer);
	render_game(game);
	return (0);
}
