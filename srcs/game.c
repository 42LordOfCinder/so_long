/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/13 04:23:07 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *g)
{
	t_vec	player_case;
	t_vec	offset;
	int		i;
	int		j;

	player_case.x = (g->player_pos.x + 32) / 64;
	player_case.y = (g->player_pos.y + 51) / 64;
	offset = vecnew(ft_abs(7 - player_case.x), ft_abs(4 - player_case.y));
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 16)
		{
			if (j - offset.x < 0 || i - offset.y < 0 ||
				j - offset.x > g->map_size.x - 1 ||
				i - offset.y > g->map_size.y - 1 ||
				g->map[i - offset.y][j - offset.x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->assets->water,\
					j * TS, i * TS);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->assets->ground,\
					j * TS, i * TS);
		}
	}
}

int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	print_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->player, 480, 226);
	return (0);
}

void	game_init(char **map)
{
	t_game	game;

	game.moves = 0;
	game.map = map;
	game.map_size = get_map_size(map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 16 * TS, 9 * TS, "so_long");
	game.player_pos = get_player_pos(map);
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
