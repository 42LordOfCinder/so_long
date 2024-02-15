/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:38 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chose_grass(t_game *g, int i, int j, t_vec map_offset)
{
	char	sur[4];

	sur[0] = g->map[i - map_offset.y - 1][j - map_offset.x];
	sur[1] = g->map[i - map_offset.y][j - map_offset.x - 1];
	sur[2] = g->map[i - map_offset.y + 1][j - map_offset.x];
	sur[3] = g->map[i - map_offset.y][j - map_offset.x + 1];
	mlx_put_image_to_window(g->mlx, g->win, g->assets->water,\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	if (sur[0] != '1' && sur[1] != '1' && sur[2] != '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[4],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] != '1' && sur[2] != '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[5],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] != '1' && sur[2] == '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[7],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] != '1' && sur[2] == '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[8],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] == '1' && sur[2] != '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[3],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] == '1' && sur[2] != '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[10],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] == '1' && sur[2] == '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[6],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] != '1' && sur[1] == '1' && sur[2] == '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[11],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] != '1' && sur[2] != '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[1],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] != '1' && sur[2] != '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[2],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] != '1' && sur[2] == '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[13],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] != '1' && sur[2] == '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[14],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] == '1' && sur[2] != '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[0],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] == '1' && sur[2] != '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[9],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] == '1' && sur[2] == '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[12],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else if (sur[0] == '1' && sur[1] == '1' && sur[2] == '1' && sur[3] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[15],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
}
