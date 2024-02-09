/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/09 19:17:42 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}

int	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

int	main_loop(void *game)
{
	game = (t_game *)game;
	return (0);
}

void	game_init(char **map)
{
	t_game	game;

	game.moves = 0;
	game.map = map;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, TS * 16, TS * 9, "so_long");
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, key_hook, game.mlx);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, window_hook, game.mlx);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
}
