/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:05:17 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/12 19:54:00 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *game)
{
	game->assets->ground = mlx_png_file_to_image(game->mlx,\
		"assets/graphics/terrain/ground.png", NULL, NULL);
	game->assets->water = mlx_png_file_to_image(game->mlx,\
		"assets/graphics/terrain/water.png", NULL, NULL);
	game->assets->player = mlx_png_file_to_image(game->mlx,\
		"assets/graphics/player/idle/idle_right.png", NULL, NULL);
}

void	destroy_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets->ground);
	mlx_destroy_image(game->mlx, game->assets->water);
}
