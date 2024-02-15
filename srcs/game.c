/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 18:29:19 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_hitbox(t_game *g, char dir)
{
	if (dir == 'x')
	{
		if (g->player.dir.x > 0)
			if (g->map[g->player.cell.y][g->player.cell.x + 1] == '1')
				if (g->player.offset.x >= 49)
					return (1);
		if (g->player.dir.x < 0)
			if (g->map[g->player.cell.y][g->player.cell.x - 1] == '1')
				if (g->player.offset.x <= 15)
					return (1);
	}
	if (dir == 'y')
	{
		if (g->player.dir.y > 0)
			if (g->map[g->player.cell.y + 1][g->player.cell.x] == '1')
				if (g->player.offset.y >= 47)
					return (1);
		if (g->player.dir.y < 0)
			if (g->map[g->player.cell.y - 1][g->player.cell.x] == '1')
				if (g->player.offset.y <= 2)
					return (1);
	}
	return (0);
}

void	draw_player(t_game *g)
{
	if (!g->player.dir.x && !g->player.dir.y && !g->player.atk)
		anim_player_idle(g, g->player.anim_dir);
	else if (!g->player.atk)
		anim_player_walk(g, g->player.anim_dir);
	else
		anim_player_atk(g, g->player.anim_dir);
}

int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	if (!check_hitbox(g, 'x') && !g->player.atk)
		g->player.pos.x += g->player.dir.x;
	if (!check_hitbox(g, 'y') && !g->player.atk)
		g->player.pos.y += g->player.dir.y;
	g->player.cell = vecnew(g->player.pos.x / TS, g->player.pos.y / TS);
	g->player.offset = vecnew(g->player.pos.x % TS, g->player.pos.y % TS);
	draw_map(g);
	draw_player(g);
	g->frames += 2;
	if (g->frames > 60)
		g->frames = 1;
	g->f_frames += 1.5;
	if (g->f_frames > 80)
		g->f_frames = 1;
	return (0);
}

void	game_init(char **map)
{
	t_game	g;

	g.moves = 0;
	g.map = put_random_elt(map);
	g.frames = 1;
	g.f_frames = 1;
	g.map_size = get_map_size(map);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 21 * TS, 11 * TS, "so_long");
	g.player.pos = get_player_pos(g.map);
	g.player.dir = vecnew(0, 0);
	g.player.anim_dir = 0;
	g.player.atk_type = 0;
	g.player.atk = 0;
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
