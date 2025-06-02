/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:35:09 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/14 16:44:05 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_player_animation(t_game *game)
{
	if (game->player_moving)
	{
		game->anim_timer++;
		if (game->anim_timer >= 16)
		{
			game->anim_timer = 0;
			game->player_anim = (game->player_anim + 1) % 6;
			if (game->player_anim == 5)
			{
				game->player_moving = 0;
				game->player_anim = 0;
			}
		}
	}
	else
	{
		game->static_anim_timer++;
		if (game->static_anim_timer >= 100)
		{
			game->static_anim_timer = 0;
			game->player_anim = (game->player_anim + 1) % 6;
		}
	}
}

void	update_enemy_animations(t_game *game, int *enemy_anim_timer,
	int *enemy_move_timer)
{
	int	i;

	*enemy_anim_timer += 1;
	if (*enemy_anim_timer >= 24)
	{
		*enemy_anim_timer = 0;
		update_enemy_animation(game);
	}
	*enemy_move_timer += 1;
	if (*enemy_move_timer >= 300)
	{
		*enemy_move_timer = 0;
		i = 0;
		while (i < game->nb_enemies)
		{
			move_enemy(game, &game->enemies[i]);
			i++;
		}
	}
}
