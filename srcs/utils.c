/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:34:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/12 03:09:02 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *game)
{
	game->assets->ground = mlx_png_file_to_image(game->mlx, \
		"assets/graphics/terrain/ground.png", NULL, NULL);
}

void	destroy_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets->ground);
}
