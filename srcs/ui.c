/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:11:44 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/25 18:28:17 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_life(t_game *g)
{
	int	k;

	if (g->o_frames > 70)
	{
		if (g->player.health >= 1)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->life, 190, 90);
		if (g->player.health >= 2)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->life, 246, 90);
		if (g->player.health >= 3)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->life, 302, 90);
	}
	else
	{
		k = g->o_frames / 10;
		if (g->player.health >= 1)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->l_anim[k], 185, 90);
		if (g->player.health >= 2)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->l_anim[k], 241, 90);
		if (g->player.health >= 3)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->l_anim[k], 297, 90);
	}
}

void	draw_objects_remaining(t_game *g)
{
	char	*nb;
	int		offset;

	nb = ft_itoa(g->objs);
	offset = (ft_strlen(nb) - 1) * 10;
	mlx_string_put(g->mlx, g->win, 1120 - offset, 98, 0xFF34391A, nb);
	free(nb);
}

void	draw_moves(t_game *g)
{
	char	*nb;
	int		offset;

	nb = ft_itoa(g->moves);
	offset = (ft_strlen(nb) - 1) * 10;
	mlx_string_put(g->mlx, g->win, 220 - offset, 588, 0xFF142A31, nb);
	free(nb);
}

void	draw_ui(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->assets->life_ui, 150, 100);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->objs_ui, 1000, 60);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->dst_ui, 100, 550);
	draw_life(g);
	draw_objects_remaining(g);
	draw_moves(g);
}
