/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:46:31 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 21:55:45 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_options(t_vec coords, char **map, int opt[4])
{
	if (map[coords.y - 1][coords.x] == '1')
		opt[0] = 0;
	else
		opt[0] = 1;
	if (map[coords.y][coords.x - 1] == '1')
		opt[1] = 0;
	else
		opt[1] = 1;
	if (map[coords.y + 1][coords.x] == '1')
		opt[2] = 0;
	else
		opt[2] = 1;
	if (map[coords.y][coords.x + 1] == '1')
		opt[3] = 0;
	else
		opt[3] = 1;
}

int	in_vectab(t_vec *tab, t_vec vec, int len)
{
	int	i;

	i = 0;
	while (tab && i < len)
	{
		if (tab[i].x == vec.x && tab[i].y == vec.y)
			return (1);
		i++;
	}
	return (0);
}

void	check_old(int opts[4], t_vec coords, t_vec *dejavu, int depth)
{
	t_vec	new_coords;

	new_coords = vecnew(coords.x, coords.y - 1);
	if (in_vectab(dejavu, new_coords, depth))
		opts[0] = 0;
	new_coords = vecnew(coords.x - 1, coords.y);
	if (in_vectab(dejavu, new_coords, depth))
		opts[1] = 0;
	new_coords = vecnew(coords.x, coords.y + 1);
	if (in_vectab(dejavu, new_coords, depth))
		opts[2] = 0;
	new_coords = vecnew(coords.x + 1, coords.y);
	if (in_vectab(dejavu, new_coords, depth))
		opts[3] = 0;
}

int	check_path(t_vec coords, char **map, t_vec *dejavu, int depth)
{
	int	opt[4];
	int	ret;

	if (map[coords.y][coords.x] == 'P')
		return (1);
	check_options(coords, map, opt);
	check_old(opt, coords, dejavu, depth);
	if (opt[0] == 0 && opt[1] == 0 && opt[2] == 0 && opt[3] == 0)
		return (0);
	dejavu = add_coords(dejavu, coords, depth);
	ret = 0;
	if (opt[0] == 1)
		ret += check_path(vecnew(coords.x, coords.y - 1), map, dejavu, depth + 1);
	if (opt[1] == 1)
		ret += check_path(vecnew(coords.x - 1, coords.y), map, dejavu, depth + 1);
	if (opt[2] == 1)
		ret += check_path(vecnew(coords.x, coords.y + 1), map, dejavu, depth + 1);
	if (opt[3] == 1)
		ret += check_path(vecnew(coords.x + 1, coords.y), map, dejavu, depth + 1);
	return (ret);
}

int	check_map_path(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				if (!check_path(vecnew(j, i), map, NULL, 0))
					return (0);
			}
		}
		i++;
	}
	return (1);
}
