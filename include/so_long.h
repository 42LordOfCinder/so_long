/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:33:08 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/24 16:44:05 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/includes/mlx.h"
# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>

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
	void		*grass[16];
	void		*water;
	void		*o_idle;
	void		*objects[7];
	void		*foam[8];
	void		*deco[8];
	void		*idle_r[6];
	void		*idle_l[6];
	void		*right[6];
	void		*left[6];
	void		*atk_r_t1[6];
	void		*atk_r_t2[6];
	void		*atk_l_t1[6];
	void		*atk_l_t2[6];
	void		*a_idle_l[6];
	void		*a_idle_r[6];
	void		*f_idle_r[6];
	void		*f_idle_l[6];
	void		*f_right[6];
	void		*f_left[6];
	void		*objs_ui;
	void		*dst_ui;
	void		*life_ui;
	void		*life;
	void		*l_anim[7];
	void		*death_r[14];
	void		*death_l[14];
}	t_assets;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	int		anim_dir;
	t_vec	cell;
	t_vec	offset;
	int		atk_type;
	int		atk;
	int		health;
	int		iframes;
}	t_player;

typedef struct s_foe
{
	t_vec	pos;
	t_vec	offset;
	t_vec	cell;
	int		status;
	t_vec	dir;
	int		anim_dir;
}	t_foe;

typedef struct s_game
{
	char		**map;
	t_vec		map_size;
	void		*mlx;
	void		*win;
	int			moves;
	int			frames;
	float		f_frames;
	int			o_frames;
	int			a_frames;
	int			d_frames;
	t_assets	*assets;
	t_player	player;
	int			objs;
	t_foe		*foes;
	int			foes_nb;
	int			a_dir;
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
void	draw_player(t_game *g);
void	draw_map(t_game *g);
int		main_loop(void *param);
void	game_init(char **map);

// Ground
void	draw_map(t_game *g);
void	chose_grass(t_game *g, int i, int j, t_vec map_offset);

// Utils
t_vec	vecnew(int x, int y);
int		key_up_hook(int key, void *mlx);
int		key_down_hook(int key, void *mlx);
int		window_hook(int event, void *mlx);
void	get_map_info(t_game *g);

// Foes
void	draw_foe_idle(t_game *g, t_vec map_offset, t_foe foe);
void	draw_foe_walk(t_game *g, t_vec map_offset, t_foe foe);
void	update_foes(t_game *g);

// Anims
void	anim_player_idle(t_game *g, int dir);
void	anim_player_walk(t_game *g, int dir);
void	anim_player_atk(t_game *g, int dir);

// Assets
void	load_assets(t_game *g);
void	destroy_assets(t_game *g);

// UI
void	draw_ui(t_game *g);
#endif
