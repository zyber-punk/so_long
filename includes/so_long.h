/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:17:15 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 03:23:15 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx_opengl_20191021/mlx.h"
# endif

# define GL_SILENCE_DEPRECATION
# define TILE_SIZE 72

# ifdef __linux__

static inline void	destroy_display(void *mlx)
{
	mlx_destroy_display(mlx);
}
# else

static inline void	destroy_display(void *mlx)
{
	(void)mlx;
}
# endif

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			nb_collect;
	int			collected;
	int			nb_moves;
	int			player_direction;
	int			player_moving;
	int			player_alive;
	int			anim_timer;
	int			static_anim_timer;
	int			player_anim;
	int			nb_tree;
	int			nb_floor;
	int			**floor_map;
	int			**tree_map;
	void		*tex_floor[2];
	void		*tex_tree[8];
	void		*tex_wall_outline[8];
	void		*tex_player[4][2][6];
	void		*tex_collectible[6];
	void		*tex_exit_closed;
	void		*tex_exit_open;
	void		*tex_digit[10];
}	t_game;

// Game functions
void	draw_texture(t_game *game, void *tex, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	render_game(t_game *game);
int		key_hook(int keycode, t_game *game);
int		loop_hook(t_game *game);
int		exit_game(t_game *game);

// Map functions
char	**read_map(char *filename);
int		check_map(char **map);
int		check_map_rectangular(char **map);
int		check_map_characters(char **map);
int		check_map_elements(char **map);
int		check_map_walls(char **map);
int		check_valid_path(char **map);
int		flood_fill(char **map, int x, int y);
int		append_char_to_map(char **map_str, char c);
int		read_file(int fd, char **map_str);
int		check_empty_lines(char *map_str);
int		check_map_structure(char **map);
int		check_map_content(char **map);

// Init functions
int		init_game(t_game *game, char *map_file);
int		init_maps(t_game *game);
void	init_player_and_collectibles(t_game *game);
void	init_floor_and_tree_maps(t_game *game);

// Load functions
int		load_textures(t_game *game);
int		load_wall_outline_textures(t_game *game, int tex_w, int tex_h);
int		load_tree_textures(t_game *game, int tex_w, int tex_h);
void	load_player_images(t_game *game, int tex_w, int tex_h);

// Utils functions
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	free_map(char **map);
void	free_map_copy(char **map_copy);
void	free_game(t_game *game);
void	cleanup_game(t_game *game);
void	handle_player_movement(t_game *game,
						int keycode, int *new_x, int *new_y);
char	*ft_itoa(int n);
void	free_environment_textures(t_game *game);
void	free_object_textures(t_game *game);
void	free_player_textures(t_game *game);

#endif
