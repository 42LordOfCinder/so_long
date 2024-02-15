/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:05 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *g)
{
	t_vec	map_offset;
	int		i;
	int		j;
	int		k;

	map_offset = vecnew(10 - g->player.cell.x, 5 - g->player.cell.y);
	i = -2;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
			mlx_put_image_to_window(g->mlx, g->win, g->assets->water, j * TS -\
				g->player.offset.x, i * TS - g->player.offset.y);
	}
	i = -2;
	k = (int)g->f_frames / 10;
	if (k == 8)
		k = 0;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
			if (j - map_offset.x >= 0 && i - map_offset.y >= 0 &&
				j - map_offset.x <= g->map_size.x - 1 &&
				i - map_offset.y <= g->map_size.y - 1 &&
				g->map[i - map_offset.y][j - map_offset.x] != '1')
				mlx_put_image_to_window(g->mlx, g->win, g->assets->foam[k], j *\
					TS - g->player.offset.x - 11, i * TS - g->player.offset.y - 11);
	}
	i = -2;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
			if (j - map_offset.x >= 0 && i - map_offset.y >= 0 &&
				j - map_offset.x <= g->map_size.x - 1 &&
				i - map_offset.y <= g->map_size.y - 1 &&
				g->map[i - map_offset.y][j - map_offset.x] != '1')
			{
				chose_grass(g, i, j, map_offset);
				if (g->map[i - map_offset.y][j - map_offset.x] != '0' &&
					ft_isdigit(g->map[i - map_offset.y][j - map_offset.x]))
					mlx_put_image_to_window(g->mlx, g->win, g->assets->deco[\
					g->map[i - map_offset.y][j - map_offset.x] - 48 - 2], j * \
					TS - g->player.offset.x, i * TS - g->player.offset.y);
			}
	}
}

void	chose_grass(t_game *g, int i, int j, t_vec map_offset)
{
	char	sur[4];

	sur[0] = g->map[i - map_offset.y - 1][j - map_offset.x];
	sur[1] = g->map[i - map_offset.y][j - map_offset.x - 1];
	sur[2] = g->map[i - map_offset.y + 1][j - map_offset.x];
	sur[3] = g->map[i - map_offset.y][j - map_offset.x + 1];
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
