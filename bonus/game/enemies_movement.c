/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:37:08 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 03:37:44 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_enemy_position(t_enemy *enemy, int *new_x, int *new_y)
{
	if (enemy->direction == 0)
		*new_y = enemy->y + 1;
	else if (enemy->direction == 1)
		*new_x = enemy->x - 1;
	else if (enemy->direction == 2)
		*new_x = enemy->x + 1;
	else if (enemy->direction == 3)
		*new_y = enemy->y - 1;
}

static int	check_enemy_collision(t_game *game, int new_x, int new_y)
{
	if (new_x == game->player_x && new_y == game->player_y)
	{
		game->player_alive = 0;
		write(1, "Game Over!\n", 10);
		free_game(game);
		exit(0);
	}
	return (1);
}

static int	handle_enemy_timer_and_behavior(t_enemy *enemy)
{
	static unsigned int	seed = 42;

	if (enemy->moving)
		return (0);
	seed = ft_rand(seed);
	if (seed % 100 == 0)
	{
		seed = ft_rand(seed);
		enemy->behavior = seed % 3;
	}
	return (1);
}

static int	try_enemy_movement(t_game *game, t_enemy *enemy,
	int *new_x, int *new_y)
{
	if (*new_x >= 0 && *new_x < game->map_width && *new_y >= 0
		&& *new_y < game->map_height && game->map[*new_y][*new_x] != '1'
		&& game->map[*new_y][*new_x] != 'M' && game->map[*new_y][*new_x] != 'C'
		&& game->map[*new_y][*new_x] != 'E')
	{
		check_enemy_collision(game, *new_x, *new_y);
		game->map[enemy->y][enemy->x] = '0';
		game->map[*new_y][*new_x] = 'M';
		enemy->x = *new_x;
		enemy->y = *new_y;
		enemy->anim = 0;
		enemy->moving = 1;
		return (1);
	}
	return (0);
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;
	int	attempts;
	int	original_direction;

	if (!handle_enemy_timer_and_behavior(enemy))
		return ;
	update_enemy_direction(enemy, game);
	attempts = 0;
	original_direction = enemy->direction;
	while (attempts < 4)
	{
		new_x = enemy->x;
		new_y = enemy->y;
		update_enemy_position(enemy, &new_x, &new_y);
		if (try_enemy_movement(game, enemy, &new_x, &new_y))
			break ;
		enemy->direction = (enemy->direction + 1) % 4;
		attempts++;
	}
	if (attempts >= 4)
	{
		enemy->direction = original_direction;
		enemy->moving = 0;
	}
}
