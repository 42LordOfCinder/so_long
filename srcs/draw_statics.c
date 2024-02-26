/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:42:41 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 22:45:06 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_object(t_game *g, int i, int j, t_vec map_offset)
{
	int	k;

	if (j - map_offset.x == g->player.cell.x
		&& i - map_offset.y == g->player.cell.y
		&& g->player.offset.y > 10)
	{
		g->map[i - map_offset.y][j - map_offset.x] = '0';
		g->objs--;
		return ;
	}
	if (g->o_frames > 70)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->o_idle, j * TS
			- g->player.offset.x, i * TS - g->player.offset.y);
	else
	{
		k = g->o_frames / 10;
		mlx_put_image_to_window(g->mlx, g->win, g->assets->objects[k], j * TS
			- g->player.offset.x - 1, i * TS - g->player.offset.y - 1);
	}
}

void	draw_ally(t_game *g, int i, int j, t_vec map_offset)
{
	void	**tab;

	if (j - map_offset.x == g->player.cell.x
		&& i - map_offset.y == g->player.cell.y)
		if (g->objs == 0)
			g->v = 1;
	if (j - map_offset.x < g->player.cell.x)
		g->a_dir = 0;
	else if (j - map_offset.x > g->player.cell.x)
		g->a_dir = 1;
	if (g->v == 0)
	{
		tab = g->assets->a_idle_l;
		if (g->a_dir == 0)
			tab = g->assets->a_idle_r;
	}
	else
	{
		tab = g->assets->v_left;
		if (g->a_dir == 0)
			tab = g->assets->v_right;
	}
	draw_ally2(g, i, j, tab);
}

void	draw_ally2(t_game *g, int i, int j, void **tab)
{
	int	k;

	k = g->frames / 10;
	if (k == 6)
		k = 0;
	if (g->v == 0)
		mlx_put_image_to_window(g->mlx, g->win, tab[k],
			j * TS - g->player.offset.x, i * TS - g->player.offset.y - 10);
	else
		mlx_put_image_to_window(g->mlx, g->win, tab[k],
			j * TS - g->player.offset.x - 14, i * TS - g->player.offset.y - 70);
}
