/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/14 04:26:43 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *g)
{
	t_vec	player_case;
	t_vec	map_offset;
	t_vec	case_offset;
	int		i;
	int		j;

	player_case.x = g->player.pos.x / 64;
	player_case.y = g->player.pos.y / 64;
	map_offset = vecnew(10 - player_case.x, 5 - player_case.y);
	case_offset = vecnew(g->player.pos.x % 64, g->player.pos.y % 64);
	i = -2;
	while (++i < 13)
	{
		j = -2;
		while (++j < 23)
		{
			if (j - map_offset.x < 0 || i - map_offset.y < 0 ||
				j - map_offset.x > g->map_size.x - 1 ||
				i - map_offset.y > g->map_size.y - 1 ||
				g->map[i - map_offset.y][j - map_offset.x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->assets->water,\
					(j * TS) - case_offset.x, (i * TS) - case_offset.y);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->assets->ground,\
					(j * TS) - case_offset.x, (i * TS) - case_offset.y);
		}
	}
}

void	move_player(int key, t_game *g)
{
	if (key == 26)
		g->player.pos.y += -10;
	if (key == 22)
		g->player.pos.y += 10;
	if (key == 4)
		g->player.pos.x += -10;
	if (key == 7)
		g->player.pos.x += 10;
}

int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	draw_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->player, TS * 10, TS * 4 + 35);
	return (0);
}

void	game_init(char **map)
{
	t_game	g;

	g.moves = 0;
	g.map = map;
	g.map_size = get_map_size(map);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 21 * TS, 11 * TS, "so_long");
	g.player.pos = get_player_pos(g.map);
	load_assets(&g);
	mlx_set_fps_goal(g.mlx, 60);
	mlx_on_event(g.mlx, g.win, MLX_KEYDOWN, key_hook, &g);
	mlx_on_event(g.mlx, g.win, MLX_WINDOW_EVENT, window_hook, g.mlx);
	mlx_loop_hook(g.mlx, main_loop, &g);
	mlx_loop(g.mlx);
	mlx_destroy_window(g.mlx, g.win);
	//destroy_assets(&game);
	mlx_destroy_display(g.mlx);
}
