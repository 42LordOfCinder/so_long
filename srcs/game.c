/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/14 19:26:07 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *g)
{
	t_vec	map_offset;
	int		i;
	int		j;

	map_offset = vecnew(10 - g->player.cell.x, 5 - g->player.cell.y);
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
					j * TS - g->player.offset.x, i * TS - g->player.offset.y);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->assets->ground,\
					j * TS - g->player.offset.x, i * TS - g->player.offset.y);
		}
	}
}

int	check_hitbox(t_game *g, char dir)
{
	if (dir == 'x')
	{
		if (g->player.dir.x > 0)
			if (g->map[g->player.cell.y][g->player.cell.x + 1] == '1')
				if (g->player.offset.x >= 42)
					return (1);
		if (g->player.dir.x < 0)
			if (g->map[g->player.cell.y][g->player.cell.x - 1] == '1')
				if (g->player.offset.x <= 20)
					return (1);
	}
	if (dir == 'y')
	{
		if (g->player.dir.y > 0)
			if (g->map[g->player.cell.y + 1][g->player.cell.x] == '1')
				if (g->player.offset.y >= 53)
					return (1);
		if (g->player.dir.y < 0)
			if (g->map[g->player.cell.y - 1][g->player.cell.x] == '1')
				if (g->player.offset.y <= 7)
					return (1);
	}
	return (0);
}

void	draw_player(t_game *g)
{
	//if (g->player.dir == vecnew())
	mlx_put_image_to_window(g->mlx, g->win, g->assets->idle_r[0], (TS * 10) - 32, (TS * 5) - 82);
}

int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	if (!check_hitbox(g, 'x'))
		g->player.pos.x += g->player.dir.x;
	if (!check_hitbox(g, 'y'))
		g->player.pos.y += g->player.dir.y;
	g->player.cell = vecnew(g->player.pos.x / TS, g->player.pos.y / TS);
	g->player.offset = vecnew(g->player.pos.x % TS, g->player.pos.y % TS);
	draw_map(g);
	draw_player(g);
	g->frames++;
	return (0);
}

void	game_init(char **map)
{
	t_game	g;

	g.moves = 0;
	g.map = map;
	g.frames = 0;
	g.map_size = get_map_size(map);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 21 * TS, 11 * TS, "so_long");
	g.player.pos = get_player_pos(g.map);
	g.player.dir = vecnew(0, 0);
	load_assets(&g);
	mlx_set_fps_goal(g.mlx, 60);
	mlx_on_event(g.mlx, g.win, MLX_KEYDOWN, key_down_hook, &g);
	mlx_on_event(g.mlx, g.win, MLX_KEYUP, key_up_hook, &g);
	mlx_on_event(g.mlx, g.win, MLX_WINDOW_EVENT, window_hook, g.mlx);
	mlx_loop_hook(g.mlx, main_loop, &g);
	mlx_loop(g.mlx);
	mlx_destroy_window(g.mlx, g.win);
	destroy_assets(&g);
	mlx_destroy_display(g.mlx);
}
