/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:11:44 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/16 23:25:06 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_ui(t_game *g)
{
	char	*nb;
	int		offset;

	mlx_put_image_to_window(g->mlx, g->win, g->assets->life_ui, 64, 64);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->objs_ui, 1024, 64);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->dst_ui, 64, 576);
//	mlx_string_put(g->mlx, g->win, 500, 500, 0xFFFFFFFF, "TEST");
	nb = ft_itoa(g->objs);
	offset = (ft_strlen(nb) - 1) * 10;
	mlx_string_put(g->mlx, g->win, 1140 - offset, 100, 0xFF34391A, nb);
	free(nb);
	nb = ft_itoa(g->moves);
	offset = (ft_strlen(nb) - 1) * 10;
	mlx_string_put(g->mlx, g->win, 180 - offset, 615, 0xFF142A31, nb);
	free(nb);
}
