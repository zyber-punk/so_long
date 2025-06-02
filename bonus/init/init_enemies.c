/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:28:07 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 03:37:10 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_enemy_properties(t_enemy *enemy,
int x, int y, unsigned int *seed)
{
	enemy->x = x;
	enemy->y = y;
	*seed = ft_rand(*seed);
	enemy->direction = *seed % 4;
	enemy->anim = 0;
	enemy->move_timer = 0;
	enemy->anim_timer = 0;
	*seed = ft_rand(*seed);
	enemy->behavior = *seed % 3;
	enemy->moving = 0;
}

static void	find_and_init_enemies(t_game *game, unsigned int *seed)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'M')
			{
				init_enemy_properties(&game->enemies[game->nb_enemies],
					x, y, seed);
				game->nb_enemies++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_game *game)
{
	static unsigned int	seed = 42;

	game->nb_enemies = 0;
	find_and_init_enemies(game, &seed);
}
