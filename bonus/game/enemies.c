/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:39:09 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/01 18:58:12 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_random_behavior(t_enemy *enemy)
{
	static unsigned int	seed = 42;

	seed = ft_rand(seed);
	if (seed % 40 == 0)
	{
		seed = ft_rand(seed);
		enemy->direction = seed % 4;
	}
}

static void	handle_chase_behavior(t_enemy *enemy, t_game *game)
{
	static unsigned int	seed = 42;

	seed = ft_rand(seed);
	if (seed % 100 < 80)
	{
		if (enemy->x < game->player_x)
			enemy->direction = 2;
		else if (enemy->x > game->player_x)
			enemy->direction = 1;
		else if (enemy->y < game->player_y)
			enemy->direction = 0;
		else
			enemy->direction = 3;
	}
}

static void	handle_patrol_behavior(t_enemy *enemy, t_game *game)
{
	static unsigned int	seed = 42;

	if (enemy->x == 0 || enemy->x == game->map_width - 1)
	{
		if (enemy->direction == 1)
			enemy->direction = 2;
		else
			enemy->direction = 1;
	}
	if (enemy->y == 0 || enemy->y == game->map_height - 1)
	{
		if (enemy->direction == 0)
			enemy->direction = 3;
		else
			enemy->direction = 0;
	}
	seed = ft_rand(seed);
	if (seed % 100 < 5)
	{
		seed = ft_rand(seed);
		enemy->direction = seed % 4;
	}
}

void	update_enemy_direction(t_enemy *enemy, t_game *game)
{
	if (enemy->behavior == 0)
		handle_random_behavior(enemy);
	else if (enemy->behavior == 1)
		handle_chase_behavior(enemy, game);
	else if (enemy->behavior == 2)
		handle_patrol_behavior(enemy, game);
}

void	update_enemy_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_enemies)
	{
		if (game->enemies[i].moving)
		{
			game->enemies[i].anim++;
			if (game->enemies[i].anim >= 4)
			{
				game->enemies[i].moving = 0;
				game->enemies[i].anim = 0;
			}
		}
		i++;
	}
}
