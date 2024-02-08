/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:33:08 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 21:50:11 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>

// Structs
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

// Main
int		main(int argc, char **argv);

// Vectors
t_vec	vecnew(int x, int y);
t_vec	addvec(t_vec vec1, t_vec vec2);
void	vec_tab_cpy(t_vec *dest, t_vec *src, int len);
t_vec	*add_coords(t_vec *dejavu, t_vec coords, int depth);

// Parsing
int		map_errors(int err_num);
char	**read_map(int fd);
int		check_line(char *line, int maplen, int occ[3], int j);
int		check_symbols(char **map);
char	**check_map(char *name);

// Checking
//void	ft_check_options(int y, int x, char **map, int opt[4]);
//int		ft_check_path(t_vec coords, char **map, int **dejavu, int depth);
int		check_map_path(char **map);
#endif
