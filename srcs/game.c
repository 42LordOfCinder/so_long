/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 22:23:35 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(void *param)
{
	t_game	*g;
	t_vec	new_cell;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	if (g->d_frames == 1 && !g->player.atk && g->v == 0)
		move(g);
	new_cell = vecnew(g->player.pos.x / TS, g->player.pos.y / TS);
	if (new_cell.x != g->player.cell.x || new_cell.y != g->player.cell.y)
		g->moves++;
	g->player.cell = new_cell;
	g->player.offset = vecnew(g->player.pos.x % TS, g->player.pos.y % TS);
	draw_map(g);
	draw_ui(g);
	g->frames += 2;
	if (g->frames > 60)
		g->frames = 1;
	g->f_frames += 1.5;
	if (g->f_frames > 80)
		g->f_frames = 1;
	g->o_frames += 2;
	if (g->o_frames > 500)
		g->o_frames = 1;
	if (g->player.atk)
		g->a_frames += 2;
	if (g->player.iframes > 0)
		g->player.iframes--;
	if (g->player.health == 0)
	{
		g->d_frames += 2;
		death(g);
	}
	if (g->v == 1)
	{
		kill_all_foes(g);
		g->v_frames += 2;
		if (g->v_frames > 115)
			mlx_loop_end(g->mlx);
	}
	return (0);
}

void	game_init(char **map)
{
	t_game	g;

	g.a_dir = 0;
	g.moves = -1;
	g.map = map;
	g.objs = 0;
	g.foes_nb = 0;
	get_map_info(&g);
	g.frames = 1;
	g.d_frames = 1;
	g.f_frames = 1;
	g.o_frames = 1;
	g.a_frames = 1;
	g.v_frames = 1;
	g.v = 0;
	g.mlx = mlx_init();
	init_foes(&g);
	g.player.dir = vecnew(0, 0);
	g.player.anim_dir = 0;
	g.player.atk_type = 0;
	g.player.atk = 0;
	g.player.iframes = 0;
	g.player.health = 3;
	load_assets(&g);
	mlx_set_fps_goal(g.mlx, 60);
	mlx_loop_hook(g.mlx, main_loop, &g);
	g.win = mlx_new_window(g.mlx, 21 * TS, 11 * TS, "so_long");
	mlx_set_font_scale(g.mlx, g.win, "assets/font/font.ttf", 45.0f);
	mlx_on_event(g.mlx, g.win, MLX_KEYDOWN, key_down_hook, &g);
	mlx_on_event(g.mlx, g.win, MLX_KEYUP, key_up_hook, &g);
	mlx_on_event(g.mlx, g.win, MLX_WINDOW_EVENT, window_hook, g.mlx);
	mlx_loop(g.mlx);
	free(g.foes);
	mlx_destroy_window(g.mlx, g.win);
	destroy_assets(&g);
	mlx_destroy_display(g.mlx);
}
