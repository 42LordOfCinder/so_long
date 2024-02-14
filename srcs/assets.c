/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:05:17 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/14 19:31:14 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_png(char *tmp, int i, char *path)
{
	size_t	len;

	len = ft_strlen(path);
	ft_memcpy(tmp, path, len);
	tmp[len] = (char)(i + 48);
	tmp[len + 1] = '.';
	tmp[len + 2] = 'p';
	tmp[len + 3] = 'n';
	tmp[len + 4] = 'g';
}

void	load_assets(t_game *game)
{
	int		i;
	char	tmp[100];

	game->assets = ft_calloc(1, sizeof(t_assets));
	game->assets->ground = mlx_png_file_to_image(game->mlx,\
		"assets/graphics/terrain/ground.png", NULL, NULL);
	game->assets->water = mlx_png_file_to_image(game->mlx,\
		"assets/graphics/terrain/water.png", NULL, NULL);
	i = 0;
	while (i < 6)
	{
		add_png(tmp, i, "assets/graphics/player/idle_right/");
		game->assets->idle_r[i] = mlx_png_file_to_image(game->mlx,\
				tmp, NULL, NULL);
		i++;
	}
}

void	destroy_assets(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->assets->ground);
	mlx_destroy_image(game->mlx, game->assets->water);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(game->mlx, game->assets->idle_r[i]);
	free(game->assets);
}
