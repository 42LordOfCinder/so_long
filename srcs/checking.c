/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:46:31 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/13 15:50:34 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_access(char **cpy, t_vec coords)
{
	if (cpy[coords.y][coords.x] == '1' || cpy[coords.y][coords.x] == 'Y')
		return ;
	cpy[coords.y][coords.x] = 'Y';
	get_map_access(cpy, vecnew(coords.x, coords.y - 1));
	get_map_access(cpy, vecnew(coords.x, coords.y + 1));
	get_map_access(cpy, vecnew(coords.x - 1, coords.y));
	get_map_access(cpy, vecnew(coords.x + 1, coords.y));
}

int	check_access(char **map, char **cpy)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				if (cpy[i][j] != 'Y')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_path(char **map)
{
	char	**cpy;
	int		i;
	int		j;
	int		check;

	cpy = malloc(sizeof(char *) * (ft_tablen(map) + 1));
	if (!cpy)
		return (0);
	ft_tabcpy(cpy, map, 1);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				get_map_access(cpy, vecnew(j, i));
		}
	}
	check = check_access(map, cpy);
	ft_free_tab(cpy);
	return (check);
}
