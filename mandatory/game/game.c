/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:18:44 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 04:14:17 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_player_collision(t_game *game, char cell)
{
	if (cell == '1')
	{
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

static void	handle_player_move(t_game *game, int new_x, int new_y)
{
	char	*moves_str;

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->nb_moves++;
	write(1, "Moves: ", 7);
	moves_str = ft_itoa(game->nb_moves);
	write(1, moves_str, ft_strlen(moves_str));
	free(moves_str);
	write(1, "\n", 1);
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
	handle_player_move(game, new_x, new_y);
	return (0);
}

int	loop_hook(t_game *game)
{
	render_game(game);
	return (0);
}
