/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:30:38 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/01 15:46:23 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int *new_y)
{
	*new_y = game->player_y - 1;
	game->player_direction = 3;
	game->player_moving = 1;
	game->player_anim = 0;
	game->anim_timer = 0;
}

static void	move_down(t_game *game, int *new_y)
{
	*new_y = game->player_y + 1;
	game->player_direction = 0;
	game->player_moving = 1;
	game->player_anim = 0;
	game->anim_timer = 0;
}

static void	move_left(t_game *game, int *new_x)
{
	*new_x = game->player_x - 1;
	game->player_direction = 1;
	game->player_moving = 1;
	game->player_anim = 0;
	game->anim_timer = 0;
}

static void	move_right(t_game *game, int *new_x)
{
	*new_x = game->player_x + 1;
	game->player_direction = 2;
	game->player_moving = 1;
	game->player_anim = 0;
	game->anim_timer = 0;
}

void	handle_player_movement(t_game *game,
	int keycode, int *new_x, int *new_y)
{
	if (keycode == 13 || keycode == 126 || keycode == 119 || keycode == 65362)
		move_up(game, new_y);
	else if (keycode == 1 || keycode == 125
		|| keycode == 115 || keycode == 65364)
		move_down(game, new_y);
	else if (keycode == 0 || keycode == 123
		|| keycode == 97 || keycode == 65361)
		move_left(game, new_x);
	else if (keycode == 2 || keycode == 124
		|| keycode == 100 || keycode == 65363)
		move_right(game, new_x);
	else
		game->player_moving = 0;
}
