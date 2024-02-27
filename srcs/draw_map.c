/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/27 17:24:26 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_foam(t_game *g, t_vec map_offset)
{
	int	i;
	int	j;
	int	k;

	i = -2;
	k = (int)g->f_frames / 10;
	if (k == 8)
		k = 0;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
			if (j - map_offset.x >= 0 && i - map_offset.y >= 0
				&& j - map_offset.x <= g->map_size.x - 1
				&& i - map_offset.y <= g->map_size.y - 1
				&& g->map[i - map_offset.y][j - map_offset.x] != '1')
				mlx_put_image_to_window(g->mlx, g->win, g->assets->foam[k], j
					* TS - g->player.offset.x - 11,
					i * TS - g->player.offset.y - 11);
	}
}

void	draw_element(t_game *g, t_vec map_offset, int i, int j)
{
	if (ft_isdigit(g->map[i - map_offset.y][j - map_offset.x]))
		mlx_put_image_to_window(g->mlx, g->win, g->assets->deco[
			g->map[i - map_offset.y][j - map_offset.x] - 48 - 2], j
			* TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (g->map[i - map_offset.y][j - map_offset.x] == 'C')
		draw_object(g, i, j, map_offset);
	else if (g->map[i - map_offset.y][j - map_offset.x] == 'E')
		draw_ally(g, i, j, map_offset);
}

void	draw_grass_and_elements(t_game *g, t_vec map_offset)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
		{
			if (j - map_offset.x >= 0 && i - map_offset.y >= 0
				&& j - map_offset.x <= g->map_size.x - 1
				&& i - map_offset.y <= g->map_size.y - 1
				&& g->map[i - map_offset.y][j - map_offset.x] != '1')
			{
				chose_grass(g, i, j, map_offset);
				if (g->map[i - map_offset.y][j - map_offset.x] != '0')
					draw_element(g, map_offset, i, j);
			}
		}
	}
}

void	draw_map(t_game *g)
{
	t_vec	map_offset;
	int		i;
	int		j;

	map_offset = vecnew(10 - g->player.cell.x, 5 - g->player.cell.y);
	i = -2;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->water, j * TS
				- g->player.offset.x, i * TS - g->player.offset.y);
	}
	draw_foam(g, map_offset);
	draw_grass_and_elements(g, map_offset);
	draw_foes(g, map_offset);
	if (g->player.health != 0)
		draw_player(g);
}
