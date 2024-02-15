/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:19:58 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 04:07:39 by gmassoni         ###   ########.fr       */
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
	if (i == 0 || i == 1 || i == 5)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 39, TS * 5 - 45 - 30);
	if (i == 2)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 40, TS * 5 - 44 - 29);
	if (i == 3)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 40, TS * 5 - 43 - 28);
	if (i == 4)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 39, TS * 5 - 44 - 28);
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
	if (i == 0)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 30, TS * 5 - 46 - 31);
	if (i == 1)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 34, TS * 5 - 47 - 32);
	if (i == 2)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 39, TS * 5 - 40 - 25);
	if (i == 3)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 47, TS * 5 - 46 - 31);
	if (i == 4)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 44, TS * 5 - 47 - 32);
	if (i == 5)
		mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 39, TS * 5 - 40 - 25);
}
