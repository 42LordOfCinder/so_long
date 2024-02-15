/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:05:17 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 14:15:09 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_png(char *tmp, int i, char *path)
{
	size_t	len;
	int		inc;

	inc = 0;
	if (i >= 10)
		inc++;
	len = ft_strlen(path);
	ft_memcpy(tmp, path, len);
	if (i < 10)
	tmp[len] = (char)(i + 48);
	else
	{
		tmp[len] = (char)(i / 10 + 48);
		tmp[len + 1] = (char)(i % 10 + 48);
	}
	tmp[len + 1 + inc] = '.';
	tmp[len + 2 + inc] = 'p';
	tmp[len + 3 + inc] = 'n';
	tmp[len + 4 + inc] = 'g';
	tmp[len + 5 + inc] = 0;
}

void	load_assets(t_game *g)
{
	int		i;
	char	tmp[100];

	g->assets = ft_calloc(1, sizeof(t_assets));
	g->assets->water = mlx_png_file_to_image(g->mlx,\
		"assets/graphics/terrain/water.png", NULL, NULL);
	i = -1;
	while (++i < 16)
	{
		add_png(tmp, i, "assets/graphics/terrain/grass/");
		g->assets->grass[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/idle_right/");
		g->assets->idle_r[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/idle_left/");
		g->assets->idle_l[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/right/");
		g->assets->right[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/left/");
		g->assets->left[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/attack_r/t1/");
		g->assets->atk_r_t1[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/attack_r/t2/");
		g->assets->atk_r_t2[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/attack_l/t1/");
		g->assets->atk_l_t1[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
	i = -1;
	while (++i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/attack_l/t2/");
		g->assets->atk_l_t2[i] = mlx_png_file_to_image(g->mlx,\
			tmp, NULL, NULL);
	}
}

void	destroy_assets(t_game *g)
{
	int	i;

	mlx_destroy_image(g->mlx, g->assets->water);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->idle_r[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->idle_l[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->right[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->left[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->atk_r_t1[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->atk_r_t2[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->atk_l_t1[i]);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(g->mlx, g->assets->atk_l_t2[i]);
	i = -1;
	while (++i < 16)
		mlx_destroy_image(g->mlx, g->assets->grass[i]);
	free(g->assets);
}
