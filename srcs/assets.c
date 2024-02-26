/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:05:17 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 22:11:01 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *g)
{
	g->assets = ft_calloc(1, sizeof(t_assets));
	g->assets->water = mlx_png_file_to_image(g->mlx,
			"assets/graphics/terrain/water.png", NULL, NULL);
	load_tab(g, 8, "assets/graphics/terrain/foam/", g->assets->foam);
	load_tab(g, 16, "assets/graphics/terrain/grass/", g->assets->grass);
	load_tab(g, 8, "assets/graphics/terrain/deco/", g->assets->deco);
	g->assets->o_idle = mlx_png_file_to_image(g->mlx,
			"assets/graphics/objects/idle.png", NULL, NULL);
	load_tab(g, 7, "assets/graphics/objects/anim/", g->assets->objects);
	load_tab(g, 6, "assets/graphics/player/idle_right/", g->assets->idle_r);
	load_tab(g, 6, "assets/graphics/player/idle_left/", g->assets->idle_l);
	load_tab(g, 6, "assets/graphics/player/right/", g->assets->right);
	load_tab(g, 6, "assets/graphics/player/left/", g->assets->left);
	load_tab(g, 6, "assets/graphics/player/attack_r/t1/", g->assets->atk_r_t1);
	load_tab(g, 6, "assets/graphics/player/attack_r/t2/", g->assets->atk_r_t2);
	load_tab(g, 6, "assets/graphics/player/attack_l/t1/", g->assets->atk_l_t1);
	load_tab(g, 6, "assets/graphics/player/attack_l/t2/", g->assets->atk_l_t2);
	load_tab(g, 6, "assets/graphics/ally/right/", g->assets->a_idle_r);
	load_tab(g, 6, "assets/graphics/ally/left/", g->assets->a_idle_l);
	load_tab(g, 6, "assets/graphics/foes/idle_right/", g->assets->f_idle_r);
	load_tab(g, 6, "assets/graphics/foes/idle_left/", g->assets->f_idle_l);
	load_assets2(g);
}

void	load_assets2(t_game *g)
{
	load_tab(g, 6, "assets/graphics/foes/right/", g->assets->f_right);
	load_tab(g, 6, "assets/graphics/foes/left/", g->assets->f_left);
	load_tab(g, 7, "assets/graphics/player/life/", g->assets->l_anim);
	load_tab(g, 7, "assets/graphics/player/death_r/", g->assets->death_r);
	load_tab(g, 7, "assets/graphics/player/death_l/", g->assets->death_l);
	load_tab(g, 8, "assets/graphics/foes/death/", g->assets->f_death);
	load_tab(g, 6, "assets/graphics/ally/v_right/", g->assets->v_right);
	load_tab(g, 6, "assets/graphics/ally/v_left/", g->assets->v_left);
	g->assets->objs_ui = mlx_png_file_to_image(g->mlx,
			"assets/graphics/ui/objects.png", NULL, NULL);
	g->assets->life_ui = mlx_png_file_to_image(g->mlx,
			"assets/graphics/ui/life.png", NULL, NULL);
	g->assets->dst_ui = mlx_png_file_to_image(g->mlx,
			"assets/graphics/ui/distance.png", NULL, NULL);
	g->assets->life = mlx_png_file_to_image(g->mlx,
			"assets/graphics/player/life.png", NULL, NULL);
}

void	destroy_assets(t_game *g)
{
	destroy_tab(g, 8, g->assets->foam);
	destroy_tab(g, 8, g->assets->deco);
	destroy_tab(g, 7, g->assets->objects);
	destroy_tab(g, 6, g->assets->a_idle_r);
	destroy_tab(g, 6, g->assets->a_idle_l);
	destroy_tab(g, 6, g->assets->f_idle_r);
	destroy_tab(g, 6, g->assets->f_idle_l);
	destroy_tab(g, 7, g->assets->l_anim);
	destroy_tab(g, 6, g->assets->f_right);
	destroy_tab(g, 6, g->assets->f_left);
	destroy_tab(g, 7, g->assets->death_l);
	destroy_tab(g, 7, g->assets->death_r);
	destroy_tab(g, 8, g->assets->f_death);
	destroy_tab(g, 6, g->assets->v_right);
	destroy_tab(g, 6, g->assets->v_left);
	destroy_assets2(g);
	free(g->assets);
}

void	destroy_assets2(t_game *g)
{
	mlx_destroy_image(g->mlx, g->assets->water);
	mlx_destroy_image(g->mlx, g->assets->o_idle);
	mlx_destroy_image(g->mlx, g->assets->objs_ui);
	mlx_destroy_image(g->mlx, g->assets->life_ui);
	mlx_destroy_image(g->mlx, g->assets->dst_ui);
	mlx_destroy_image(g->mlx, g->assets->life);
	destroy_tab(g, 6, g->assets->idle_r);
	destroy_tab(g, 6, g->assets->idle_l);
	destroy_tab(g, 6, g->assets->right);
	destroy_tab(g, 6, g->assets->left);
	destroy_tab(g, 6, g->assets->atk_r_t1);
	destroy_tab(g, 6, g->assets->atk_r_t2);
	destroy_tab(g, 6, g->assets->atk_l_t1);
	destroy_tab(g, 6, g->assets->atk_l_t2);
	destroy_tab(g, 16, g->assets->grass);
}
