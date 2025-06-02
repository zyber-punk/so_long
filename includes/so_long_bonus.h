/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:02:41 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/04/09 18:21:49 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

/* Structure pour gérer les ennemis */
typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
	int	anim;
	int	move_timer;
	int	anim_timer;
	int	behavior;
	int	moving;
}	t_enemy;

/* Structure principale du jeu */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		nb_collect;
	int		collected;
	int		nb_moves;
	int		player_direction;
	int		player_anim;
	int		player_moving;
	int		player_alive;
	int		anim_timer;
	int		static_anim_timer;
	void	*tex_wall_outline[8];
	void	*tex_tree[8];
	int		nb_tree;
	void	*tex_floor[2];
	int		nb_floor;
	int		**floor_map;
	int		**tree_map;
	void	*tex_player[4][2][6];
	void	*tex_enemy[4][4];
	t_enemy	enemies[10];
	int		nb_enemies;
	int		enemy_anim;
	void	*tex_collectible[6];
	int		coll_anim;
	void	*tex_exit_closed;
	void	*tex_exit_open;
	void	*tex_digit[10];
	void	*tex_tens[10];
	void	*tex_hundreds[10];
}	t_game;

/* Structures pour le chargement des textures */
typedef struct s_enemy_load
{
	t_game	*game;
	char	*path;
	int		dir;
	int		frame;
	int		tex_w;
	int		tex_h;
}	t_enemy_load;

typedef struct s_player_load
{
	t_game	*game;
	char	*path;
	int		dir;
	int		frame;
	int		tex_w;
	int		tex_h;
	int		is_static;
}	t_player_load;

typedef struct s_frame_params
{
	t_player_load	*load;
	int				dir;
	int				frame;
	const char		**directions;
}	t_frame_params;

typedef struct s_init_params
{
	t_player_load	*load;
	t_game			*game;
	char			*path;
	int				dir;
	int				tex_w;
	int				tex_h;
	int				is_static;
}	t_init_params;

typedef struct s_frames_params
{
	t_game	*game;
	int		dir;
	int		tex_w;
	int		tex_h;
	int		is_static;
}	t_frames_params;

/* Fonctions de lecture et vérification de la carte */

char			**read_map(char *filename);
void			free_map(char **map);
int				check_map(char **map);
int				check_map_rectangular(char **map);
int				check_map_elements(char **map);
int				check_valid_path(char **map);
int				check_map_walls(char **map);
int				check_map_characters(char **map);
void			free_map_copy(char **map_copy);
int				flood_fill(char **map, int x, int y);
int				append_char_to_str(char **map_str, char buffer);
int				read_file(int fd, char **map_str);

/* Gestion des évènements */
int				key_hook(int keycode, t_game *game);
int				loop_hook(t_game *game);
void			render_game(t_game *game);
void			render_moves(t_game *game);
void			handle_player_movement(t_game *game, int keycode,
						int *new_x, int *new_y);
void			update_player_animation(t_game *game);
void			update_enemy_animations(t_game *game, int *enemy_anim_timer,
						int *enemy_move_timer);

/* Gestion des ennemis */
void			move_enemy(t_game *game, t_enemy *enemy);
void			update_enemy_direction(t_enemy *enemy, t_game *game);
void			update_enemy_animation(t_game *game);

/* Rendu graphique */
void			draw_wall(t_game *game, int x, int y);
void			draw_texture(t_game *game, void *tex, int x, int y);

/* Gestion de la mémoire et de la fermeture */
void			cleanup_game(t_game *game);
int				exit_game(t_game *game);
void			free_game(t_game *game);
void			destroy_floor(t_game *game);
void			destroy_player(t_game *game);
void			destroy_enemy(t_game *game);
void			destroy_collectible(t_game *game);
void			destroy_digits(t_game *game);
void			destroy_wall_outline(t_game *game);
void			destroy_tree(t_game *game);
void			destroy_enemy_textures(t_game *game);
void			destroy_collectible_textures(t_game *game);
void			destroy_exit_textures(t_game *game);
void			destroy_digit_textures(t_game *game);
void			destroy_floor_textures(t_game *game);
void			destroy_wall_and_tree_textures(t_game *game);
void			destroy_player_textures_part1(t_game *game);
void			destroy_player_textures_part2(t_game *game);

/* Initialisation du jeu */
int				init_game(t_game *game, char *map_file);
int				init_maps(t_game *game);
void			init_player_and_collectibles(t_game *game);
void			init_floor_and_tree_maps(t_game *game);
void			init_enemies(t_game *game);
int				load_textures(t_game *game);
int				load_wall_outline_textures(t_game *game, int tex_w, int tex_h);
int				load_tree_textures(t_game *game, int tex_w, int tex_h);
int				load_enemy_textures(t_game *game, int tex_w, int tex_h);
int				load_player_textures(t_game *game, int tex_w, int tex_h);
int				load_exit_textures(t_game *game, int tex_w, int tex_h);
int				load_digit_textures(t_game *game, int tex_w, int tex_h);
int				load_tens_textures(t_game *game, int tex_w, int tex_h);
int				load_hundreds_textures(t_game *game, int tex_w, int tex_h);

/* Fonctions de construction des chemins de textures */
void			add_frame_number(char *path, int *i, int frame);
void			copy_base_path(char *path, int *i);
void			copy_direction(char *path, int *i,
						int dir, const char *directions[]);
void			copy_middle_path(char *path, int *i);
void			copy_end_path(char *path, int *i);
void			add_static_frame(char *path, int *i, int frame);
void			build_static_path(char *path, int dir,
						int frame, const char *directions[]);
void			add_animated_frame(char *path, int *i, int frame);
void			build_animated_path(char *path, int dir,
						int frame, const char *directions[]);

/* Fonctions de gestion des textures */
void			handle_static_texture_error(void *texture, char *path);
int				load_static_texture(t_player_load *load);
void			handle_animated_texture_error(void *texture);
int				load_animated_texture(t_player_load *load);

/* Fonctions de copie des chemins de textures */
void			copy_animated_base(char *path, int *i);
void			copy_animated_direction(char *path, int *i,
						int dir, const char *directions[]);
void			copy_animated_middle(char *path, int *i);
void			copy_animated_end(char *path, int *i);
void			copy_static_base(char *path, int *i);
void			copy_static_direction(char *path, int *i,
						int dir, const char *directions[]);
void			copy_static_middle(char *path, int *i);
void			copy_static_end(char *path, int *i);

/* Fonctions de chargement des textures */
int				check_player_file(char *path);
int				load_player_image(t_player_load *load);
void			init_player_load(t_init_params *params);
void			init_frame_params(t_frame_params *frame_params,
						t_player_load *load, int dir, const char *directions[]);

/* Fonctions utilitaires */
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			**ft_split(char const *s, char c);
int				random_int(int max);
char			*ft_itoa(int n);
unsigned int	ft_rand(unsigned int seed);

#endif
