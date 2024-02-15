/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:33:08 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 03:48:08 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/includes/mlx.h"
# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef TS
#  define TS 64
# endif

// Structs
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_assets
{
	void	*grass[16];
	void	*water;
	void	*idle_r[6];
	void	*idle_l[6];
	void	*right[6];
	void	*left[6];
}	t_assets;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	int		anim_dir;
	t_vec	cell;
	t_vec	offset;
}	t_player;

typedef struct s_game
{
	char		**map;
	t_vec		map_size;
	void		*mlx;
	void		*win;
	int			moves;
	int			frames;
	t_assets	*assets;
	t_player	player;
}	t_game;

// Main
int		main(int argc, char **argv);

// Parsing
int		map_errors(int err_num);
char	**read_map(int fd);
int		check_line(char *line, int maplen, int occ[3], int j);
int		check_symbols(char **map);
char	**check_map(char *name);

// Checking
void	get_map_access(char **cpy, t_vec coords);
int		check_access(char **map, char **cpy);
int		check_map_path(char **map);

// Game
void	draw_map(t_game *g);
int		main_loop(void *param);
void	game_init(char **map);

// Utils
t_vec	vecnew(int x, int y);
int		key_up_hook(int key, void *mlx);
int		key_down_hook(int key, void *mlx);
int		window_hook(int event, void *mlx);
t_vec	get_player_pos(char **map);
t_vec	get_map_size(char **map);

// Anims
void	anim_player_idle(t_game *g, int dir);
void	anim_player_walk(t_game *g, int dir);

// Assets
void	load_assets(t_game *g);
void	destroy_assets(t_game *g);
#endif
