/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:28 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/15 04:13:30 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chose_grass(t_game *g, int i, int j, t_vec map_offset)
{
	char	sur[4];

	sur[0] = g->map[j - map_offset.y - 1][i - map_offset.x];
	sur[1] = g->map[j - map_offset.y][i - map_offset.x - 1];
	sur[2] = g->map[j - map_offset.y + 1][i - map_offset.x];
	sur[3] = g->map[j - map_offset.y][i - map_offset.x + 1];
	if (sur[0] != '1' && sur[1] != '1' && sur[2] != '1' && sur[3] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[4],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[15],\
			j * TS - g->player.offset.x, i * TS - g->player.offset.y);
}

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
				chose_grass(g, i, j, map_offset);
		}
	}
}

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
	if (g->player.dir.x == 0 && g->player.dir.y == 0)
		anim_player_idle(g, g->player.anim_dir);
	else
		anim_player_walk(g, g->player.anim_dir);
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
	g->frames += 2;
	if (g->frames > 60)
		g->frames = 1;
	return (0);
}

/*int	main_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	mlx_clear_window(g->mlx, g->win);
	for (int i = 0; i < 6; i++)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->right[i], TS * i, 0);
	for (int i = 0; i < 6; i++)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->left[i], TS * i, 100);
	for (int i = 0; i < 6; i++)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->idle_r[i], TS * i, 200);
	for (int i = 0; i < 6; i++)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->idle_l[i], TS * i, 300);
	mlx_put_image_to_window(g->mlx, g->win, g->assets->water, 0, 400);
	for (int i = 0; i < 16; i++)
		mlx_put_image_to_window(g->mlx, g->win, g->assets->grass[i], TS * i, 464);
	return (0);
}*/

void	game_init(char **map)
{
	t_game	g;

	g.moves = 0;
	g.map = map;
	g.frames = 1;
	g.map_size = get_map_size(map);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 21 * TS, 11 * TS, "so_long");
	g.player.pos = get_player_pos(g.map);
	g.player.dir = vecnew(0, 0);
	g.player.anim_dir = 0;
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
