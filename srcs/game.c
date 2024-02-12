/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/12 20:02:18 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->player, 576, 320);
	return (0);
}

void	game_init(char **map)
{
	t_game	game;

	game.moves = 0;
	game.map = map;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 16 * TS, 9 * TS, "so_long");
	load_assets(&game);
	mlx_set_fps_goal(game.mlx, 60);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, key_hook, game.mlx);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, window_hook, game.mlx);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	//destroy_assets(&game);
	mlx_destroy_display(game.mlx);
}
