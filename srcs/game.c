/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 21:27:34 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *g)
{
	if (g->player.dir.x > 0)
		if (g->map[g->player.cell.y][g->player.cell.x + 1] != '1'
			|| g->player.offset.x <= 37)
			g->player.pos.x += g->player.dir.x;
	if (g->player.dir.x < 0)
		if (g->map[g->player.cell.y][g->player.cell.x - 1] 	!= '1'
			|| g->player.offset.x >= 25)
			g->player.pos.x += g->player.dir.x;
	if (g->player.dir.y > 0)
		if (g->map[g->player.cell.y + 1][g->player.cell.x] != '1'
			|| g->player.offset.y <= 40)
			g->player.pos.y += g->player.dir.y;
	if (g->player.dir.y < 0)
		if (g->map[g->player.cell.y - 1][g->player.cell.x] != '1'
			|| g->player.offset.y >= 2)
			g->player.pos.y += g->player.dir.y;
}

void	draw_player(t_game *g)
{
	if ((!g->player.dir.x && !g->player.dir.y && !g->player.atk) || g->v == 1)
		anim_player_idle(g, g->player.anim_dir);
	else if (!g->player.atk)
		anim_player_walk(g, g->player.anim_dir);
	else
		anim_player_atk(g, g->player.anim_dir);
}

void	death(t_game *g)
{
	void	**tab;
	int		i;

	if (g->player.anim_dir == 0)
		tab = g->assets->death_r;
	else
		tab = g->assets->death_l;
	i = g->d_frames / 10;
	if (i >= 7)
		i = 6;
	if (g->d_frames > 200)
		mlx_loop_end(g->mlx);
	mlx_put_image_to_window(g->mlx, g->win, tab[i], TS * 10 - 64,
		TS * 5 - 64);
}

void	kill_all_foes(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->foes_nb)
	{
		if (g->foes[i].dead != 1)
			g->foes[i].dead = 1;
	}
}

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
		g->v_frames++;
		if (g->v_frames > 120)
			mlx_loop_end(g->mlx);
	}
	return (0);
}

void	init_foes(t_game *g)
{
	int	i;
	int	j;
	int	k;

	g->foes = malloc(sizeof(t_foe) * g->foes_nb);
	i = -1;
	k = 0;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'F')
			{
				g->foes[k].pos = vecnew(j * TS + 45, i * TS + 45);
				g->foes[k].status = 0;
				g->foes[k].cell = vecnew(g->foes[k].pos.x / TS, g->foes[k].pos.y / TS);
				g->foes[k].offset = vecnew(g->foes[k].pos.x % TS, g->foes[k].pos.y % TS);
				g->foes[k].anim_dir = 0;
				g->foes[k].dead = 0;
				g->foes[k].death_frames = 1;
				k++;
			}
		}
	}
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
