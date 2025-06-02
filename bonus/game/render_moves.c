/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:11:38 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 04:06:07 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render_hundreds(t_game *game, int hundreds)
{
	if (game->tex_hundreds[hundreds])
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_hundreds[hundreds], (game->map_width - 3) * TILE_SIZE,
			(game->map_height - 1) * TILE_SIZE);
}

static void	render_tens(t_game *game, int tens)
{
	if (game->tex_tens[tens])
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_tens[tens], (game->map_width - 2) * TILE_SIZE,
			(game->map_height - 1) * TILE_SIZE);
}

static void	render_units(t_game *game, int units)
{
	if (game->tex_digit[units])
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_digit[units], (game->map_width - 1) * TILE_SIZE,
			(game->map_height - 1) * TILE_SIZE);
}

void	render_moves(t_game *game)
{
	int		units;
	int		tens;
	int		hundreds;

	units = game->nb_moves % 10;
	tens = (game->nb_moves / 10) % 10;
	hundreds = (game->nb_moves / 100) % 10;
	if (game->nb_moves >= 100)
		render_hundreds(game, hundreds);
	if (game->nb_moves >= 10)
		render_tens(game, tens);
	render_units(game, units);
}
