/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:58:22 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 21:26:17 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_foe_dead(t_game *g, t_vec map_offset, t_foe *foe)
{
	int	i;

	if (foe->death_frames >= 80)
		return ;
	i = foe->death_frames / 10;
	mlx_put_image_to_window(g->mlx, g->win, g->assets->f_death[i],
		(foe->cell.x + map_offset.x) * TS - g->player.offset.x - 110 +
		foe->offset.x, (foe->cell.y + map_offset.y) * TS - g->player.offset.y 
		+ foe->offset.y - 110);
	foe->death_frames += 2;
}

void	draw_foe_idle(t_game *g, t_vec map_offset, t_foe foe)
{
	int		k;
	void	**tab;

	if (foe.anim_dir == 0)
		tab = g->assets->f_idle_r;
	else
		tab = g->assets->f_idle_l;
	k = g->frames / 10;
	if (k == 6)
		k = 0;
	mlx_put_image_to_window(g->mlx, g->win, tab[k], (foe.cell.x + map_offset.x)
		* TS - g->player.offset.x - 57 + foe.offset.x, (foe.cell.y + map_offset.y) *
		TS - g->player.offset.y - 80 + foe.offset.y);
}

void	draw_foe_walk(t_game *g, t_vec map_offset, t_foe foe)
{
	int		k;
	void	**tab;

	if (foe.anim_dir == 0)
		tab = g->assets->f_right;
	else
		tab = g->assets->f_left;
	k = g->frames / 10;
	if (k == 6)
		k = 0;
	if (foe.anim_dir == 0)
		mlx_put_image_to_window(g->mlx, g->win, tab[k], (foe.cell.x + map_offset.x)
			* TS - g->player.offset.x - 90 + foe.offset.x, (foe.cell.y + map_offset.y) *
			TS - g->player.offset.y - 70 + foe.offset.y);
	else
		mlx_put_image_to_window(g->mlx, g->win, tab[k], (foe.cell.x + map_offset.x)
			* TS - g->player.offset.x - 50 + foe.offset.x, (foe.cell.y + map_offset.y)  *
			TS - g->player.offset.y - 70 + foe.offset.y);
}

void	get_foe_info(t_game *g, t_foe *foe)
{
	if (foe->dir.x > 0)
		if (g->map[foe->cell.y][foe->cell.x + 1] != '1'
			|| foe->offset.x <= 40)
			foe->pos.x += foe->dir.x;
	if (foe->dir.x < 0)
		if (g->map[foe->cell.y][foe->cell.x - 1] != '1'
			|| foe->offset.x >= 44)
			foe->pos.x += foe->dir.x;
	if (foe->dir.y > 0)
		if (g->map[foe->cell.y + 1][foe->cell.x] != '1'
			|| foe->offset.y <= 42)
			foe->pos.y += foe->dir.y;
	if (foe->dir.y < 0)
		if (g->map[foe->cell.y - 1][foe->cell.x] != '1'
			|| foe->offset.y >= 10)
			foe->pos.y += foe->dir.y;
	foe->cell = vecnew(foe->pos.x / TS, foe->pos.y / TS);
	foe->offset = vecnew(foe->pos.x % TS, foe->pos.y % TS);
	if (foe->cell.x < g->player.cell.x)
		foe->anim_dir = 0;
	else if (foe->cell.x > g->player.cell.x)
		foe->anim_dir = 1;
}

void	update_foes(t_game *g)
{
	int		i;
	t_vec	dist;

	i = -1;
	while (++i < g->foes_nb)
	{
		dist = vecnew(g->foes[i].cell.x - g->player.cell.x, g->foes[i].cell.y - g->player.cell.y);
		if (dist.x >= -4 && dist.x <= 4 && dist.y >= -4 && dist.y <= 4 && !g->foes[i].dead)
		{
			g->foes[i].status = 1;
			g->foes[i].dir = vecnew(0, 0);
			if (dist.x >= -4 && dist.x < 0)
				g->foes[i].dir.x = 2;
			else if (dist.x > 0 && dist.x <= 4)
				g->foes[i].dir.x = -2;
			if (dist.y >= - 4 && dist.y < 0)
				g->foes[i].dir.y = 2;
			else if (dist.y > 0 && dist.y <= 4)
				g->foes[i].dir.y = -2;
		}
		else
		{
			g->foes[i].dir = vecnew(0, 0);
			g->foes[i].status = 0;
		}
		get_foe_info(g, &g->foes[i]);
		if (g->foes[i].cell.x == g->player.cell.x
				&& g->foes[i].cell.y == g->player.cell.y
				&& !g->player.iframes && !g->foes[i].dead)
		{
			g->player.health--;
			g->player.iframes = 120;
		}
	}
}
