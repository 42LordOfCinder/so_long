/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:34:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/12 19:05:53 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec	vecnew(int x, int y)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	return (new);
}

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
