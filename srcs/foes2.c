/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:03:13 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/28 19:32:49 by gmassoni         ###   ########.fr       */
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
		(foe->cell.x + map_offset.x) * TS - g->player.offset.x - 110
		+ foe->offset.x, (foe->cell.y + map_offset.y) * TS - g->player.offset.y
		+ foe->offset.y - 110);
	foe->death_frames += 2;
}

void	init_foes(t_game *g)
{
	int	i;
	int	j;
	int	k;

	g->foes = malloc(sizeof(t_foe) * g->foes_nb);
	i = -1;
	k = 0;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'F')
			{
				g->foes[k].pos = vecnew(j * TS + 45, i * TS + 45);
				g->foes[k].cell = vecnew(g->foes[k].pos.x / TS,
						g->foes[k].pos.y / TS);
				g->foes[k].offset = vecnew(g->foes[k].pos.x % TS,
						g->foes[k].pos.y % TS);
				g->foes[k].dead = 0;
				g->foes[k].health = 1;
				g->foes[k++].death_frames = 1;
			}
		}
	}
}

void	take_damage(t_foe *foe)
{
	foe->health--;
	if (foe->health <= 0)
		foe->dead = 1;
}

void	kill_all_foes(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->foes_nb)
	{
		if (g->foes[i].dead != 1)
			g->foes[i].dead = 1;
	}
}

void	draw_foes(t_game *g, t_vec map_offset)
{
	int	i;

	update_foes(g);
	i = 0;
	while (i < g->foes_nb)
	{
		if (g->foes[i].dead == 1)
			draw_foe_dead(g, map_offset, &g->foes[i]);
		else if (g->foes[i].status == 0)
			draw_foe_idle(g, map_offset, g->foes[i]);
		else
			draw_foe_walk(g, map_offset, g->foes[i]);
		i++;
	}
}
