/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:33:08 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/09 19:19:23 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MacroLibX/includes/mlx.h"
# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef TS
#  define TS 80
# endif

// Structs
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		moves;
}	t_game;

// Main
int		main(int argc, char **argv);

// Vectors
t_vec	vecnew(int x, int y);

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
void	game_init(char **map);
#endif
