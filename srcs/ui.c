/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:11:44 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/16 19:10:12 by gmassoni         ###   ########.fr       */
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
	nb = ft_itoa(g->objs);
	offset = ft_strlen(nb);
	mlx_string_put(g->mlx, g->win, 1162 - (offset * 10), 98, 0xE8BBB552, nb);
	free(nb);
}
