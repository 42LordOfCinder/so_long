/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:34:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/13 19:24:35 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec	vecnew(int x, int y)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	return (new);
}

int	key_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 41)
		mlx_loop_end(g->mlx);
	if (key == 26 || key == 4 || key == 22 || key == 7)
		move_player(key, g);
	return (0);
}

int	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

t_vec	get_player_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (vecnew(j * TS, i * TS));
			j++;
		}
		i++;
	}
	return (vecnew(0, 0));
}

t_vec	get_map_size(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j])
		j++;
	return (vecnew(j, i));
}
