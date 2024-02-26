/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:19:58 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 21:34:31 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_player_idle(t_game *g, int dir)
{
	int		i;
	void	**tab;

	if (dir == 0)
		tab = g->assets->idle_r;
	else
		tab = g->assets->idle_l;
	i = g->frames / 10;
	if (i == 6)
		i = 0;
	if (!g->player.iframes || ((g->player.iframes % 10) % 2) > 0)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 40,
			TS * 5 - 45 - 30);
}

void	anim_player_walk(t_game *g, int dir)
{
	int		i;
	void	**tab;

	if (dir == 0)
		tab = g->assets->right;
	else
		tab = g->assets->left;
	i = g->frames / 10;
	if (i == 6)
		i = 0;
	if (dir == 0 && (!g->player.iframes
			|| ((g->player.iframes % 10) % 2) > 0))
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 48,
			TS * 5 - 48 - 30);
	else if (dir == 1 && (!g->player.iframes
			|| ((g->player.iframes % 10) % 2) > 0))
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 47,
			TS * 5 - 48 - 30);
}

void	reset_atk(t_game *g)
{
	g->a_frames = 1;
	g->player.atk = 0;
	if (g->player.atk_type == 1)
		g->player.atk_type = 0;
	else
		g->player.atk_type = 1;
}

void	anim_player_atk(t_game *g, int dir)
{
	int		i;

	i = g->a_frames / 10;
	if (!g->player.iframes || (g->player.iframes % 10) % 2 > 0)
	{
		if (g->player.atk_type == 0 && dir == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->atk_r_t1[i],
				TS * 10 - 45, TS * 5 - 67 - 30);
		else if (g->player.atk_type == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->atk_l_t1[i],
				TS * 10 - 74, TS * 5 - 67 - 30);
		else if (g->player.atk_type == 1 && dir == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->atk_r_t2[i],
				TS * 10 - 70, TS * 5 - 44 - 30);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->assets->atk_l_t2[i],
				TS * 10 - 74, TS * 5 - 44 - 30);
	}
	if (g->a_frames > 58)
		reset_atk(g);
}
