/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:18:32 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/27 20:00:34 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *g)
{
	if (g->player.dir.x > 0)
		if (g->map[g->player.cell.y][g->player.cell.x + 1] != '1'
			|| g->player.offset.x <= 37)
			g->player.pos.x += g->player.dir.x;
	if (g->player.dir.x < 0)
		if (g->map[g->player.cell.y][g->player.cell.x - 1] != '1'
			|| g->player.offset.x >= 25)
			g->player.pos.x += g->player.dir.x;
	if (g->player.dir.y > 0)
		if (g->map[g->player.cell.y + 1][g->player.cell.x] != '1'
			|| g->player.offset.y <= 40)
			g->player.pos.y += g->player.dir.y;
	if (g->player.dir.y < 0)
		if (g->map[g->player.cell.y - 1][g->player.cell.x] != '1'
			|| g->player.offset.y >= 2)
			g->player.pos.y += g->player.dir.y;
}

void	draw_player(t_game *g)
{
	if ((!g->player.dir.x && !g->player.dir.y && !g->player.atk) || g->v == 1)
		anim_player_idle(g, g->player.anim_dir);
	else if (!g->player.atk)
		anim_player_walk(g, g->player.anim_dir);
	else
	{
		atk(g);
		anim_player_atk(g, g->player.anim_dir);
	}
}

void	death(t_game *g)
{
	void	**tab;
	int		i;

	if (g->player.anim_dir == 0)
		tab = g->assets->death_r;
	else
		tab = g->assets->death_l;
	i = g->d_frames / 10;
	if (i >= 7)
		i = 6;
	if (g->d_frames > 200)
		mlx_loop_end(g->mlx);
	mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 64,
		TS * 5 - 64);
}

void	atk(t_game *g)
{
	int	atk_frame;
	int	i;

	atk_frame = g->a_frames / 10;
	i = -1;
	while (++i < g->foes_nb)
	{
		if (!g->player.anim_dir && g->player.pos.x <= g->foes[i].pos.x)
		{
			if (!g->player.atk_type /*&& atk_frame == 0*/
				&& g->foes[i].pos.x <= g->player.pos.x + 60
				&& g->foes[i].pos.y >= g->player.pos.y )
				take_damage(&g->foes[i]);
			/*if (!g->player.atk_type && atk_frame == 1)
				take_damage(&g->foes[i]);
			if (!g->player.atk_type && atk_frame == 2)
				take_damage(&g->foes[i]);
			if (!g->player.atk_type && atk_frame == 3)
				take_damage(&g->foes[i]);
			if (!g->player.atk_type && atk_frame == 4)
				take_damage(&g->foes[i]);
			if (!g->player.atk_type && atk_frame == 5)
				take_damage(&g->foes[i]);*/
		}
	}
}
