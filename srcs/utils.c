/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:34:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/19 16:18:23 by gmassoni         ###   ########.fr       */
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
	if (key == 26 || key == 82)
		g->player.dir.y = -4;
	if (key == 22 || key == 81)
		g->player.dir.y = 4;
	if (key == 4 || key == 80)
		g->player.dir.x = -4;
	if (key == 7 || key == 79)
		g->player.dir.x = 4;
	if ((key == 7 || key == 79) && !g->player.atk)
		g->player.anim_dir = 0;
	if ((key == 4 || key == 80) && !g->player.atk)
		g->player.anim_dir = 1;
	if (key == 44)
		g->player.atk = 1;
	return (0);
}

int	key_up_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 26 || key == 82)
		g->player.dir.y = 0;
	if (key == 22 || key == 81)
		g->player.dir.y = 0;
	if (key == 4 || key == 80)
		g->player.dir.x = 0;
	if (key == 7 || key == 79)
		g->player.dir.x = 0;
	return (0);
}

int	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

void	get_map_info(t_game *g)
{
	int	i;
	int	j;
	int	ran;

	srand(time(NULL));
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			ran = rand() % 20;
			if (ran == 1 && g->map[i][j] == '0')
				g->map[i][j] = rand() % 8 + 48 + 2;
			if (g->map[i][j] == 'P')
				g->player.pos = vecnew(j * TS + 40, i * TS + 45);
			if (g->map[i][j] == 'C')
				g->objs++;
			if (g->map[i][j] == 'F')
				g->foes_nb++;
			j++;
		}
		i++;
	}
	g->map_size = vecnew(j, i);
}
