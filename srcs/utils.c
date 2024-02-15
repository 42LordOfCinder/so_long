/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:34:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 02:32:20 by gmassoni         ###   ########.fr       */
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

int	key_down_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 41)
		mlx_loop_end(g->mlx);
	if (key == 26)
		g->player.dir.y = -4;
	if (key == 22)
		g->player.dir.y = 4;
	if (key == 4)
		g->player.dir.x = -4;
	if (key == 7)
		g->player.dir.x = 4;
	if (key == 7)
		g->player.anim_dir = 0;
	if (key == 4)
		g->player.anim_dir = 1;
	return (0);
}

int	key_up_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 26)
		g->player.dir.y = 0;
	if (key == 22)
		g->player.dir.y = 0;
	if (key == 4)
		g->player.dir.x = 0;
	if (key == 7)
		g->player.dir.x = 0;
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
				return (vecnew((j * TS) + 39, (i * TS) + 45));
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
