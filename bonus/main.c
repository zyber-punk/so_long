/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:14:51 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/01 19:42:42 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_args(int argc)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		write(1, "Usage: ./so_long ./maps/map.ber\n", 33);
		return (1);
	}
	return (0);
}

static int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || filename[len - 4] != '.'
		|| filename[len - 3] != 'b'
		|| filename[len - 2] != 'e'
		|| filename[len - 1] != 'r')
	{
		write(1, "Error\n", 6);
		write(1, "Map file must have .ber extension\n", 35);
		return (1);
	}
	return (0);
}

static int	init_game_components(t_game *game)
{
	init_player_and_collectibles(game);
	init_enemies(game);
	init_floor_and_tree_maps(game);
	if (load_textures(game))
	{
		write(1, "Error\n", 6);
		write(1, "Failed to load textures\n", 23);
		free_game(game);
		return (1);
	}
	return (0);
}

static void	setup_mlx_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, (int (*)())exit_game, game);
	mlx_loop_hook(game->mlx, (int (*)())loop_hook, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_args(argc))
		return (1);
	if (check_extension(argv[1]))
		return (1);
	if (init_game(&game, argv[1]))
		return (1);
	if (init_game_components(&game))
		return (1);
	render_game(&game);
	setup_mlx_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
