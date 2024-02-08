/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:32:24 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 20:51:20 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_errors(int err_num)
{
	if (err_num == 0)
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
	else if (err_num == 1)
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
	else if (err_num == 2)
		ft_putstr_fd("Error\nCharacter not recognized\n", 2);
	else if (err_num == 3)
		ft_putstr_fd("Error\nProhibited duplicates characters\n", 2);
	else if (err_num == 4)
		ft_putstr_fd("Error\nMandatory character not found\n", 2);
	return (0);
}

char	**read_map(int fd)
{
	char	**map;
	char	*str;

	map = NULL;
	str = get_next_line(fd);
	while (str)
	{
		map = ft_add_element_tab(map, ft_remove_char(str, ft_strlen(str) - 1));
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	check_line(char *line, int maplen, int occ[3], int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((j == 0 || j == maplen - 1 || i == 0
				|| i == (int)ft_strlen(line) - 1) && line[i] != '1')
			return (map_errors(1));
		else if (!ft_inset(line[i], "01CEPF"))
			return (map_errors(2));
		else if (line[i] == 'E')
			occ[0]++;
		else if (line[i] == 'C')
			occ[1]++;
		else if (line[i] == 'P')
			occ[2]++;
		i++;
	}
	return (1);
}

// occ[3] are 3 counters for this characters: ECP
int	check_symbols(char **map)
{
	int	i;
	int	len;
	int	occ[3];

	occ[0] = 0;
	occ[1] = 0;
	occ[2] = 0;
	i = -1;
	len = ft_strlen(map[0]);
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (map_errors(0));
		len = ft_strlen(map[i]);
		if (!check_line(map[i], ft_tablen(map), occ, i))
			return (0);
	}
	if (occ[0] > 1 || occ[2] > 1)
		return (map_errors(3));
	if (occ[0] < 1 || occ[1] < 1 || occ[2] < 1)
		return (map_errors(4));
	return (1);
}

char	**check_map(char *name)
{
	int		len;
	int		fd;
	char	**map;

	len = ft_strlen(name);
	if (len < 5 || name[len - 1] != 'r' || name[len - 2] != 'e'
		|| name[len - 3] != 'b' || name[len - 4] != '.')
	{
		ft_putstr_fd("Error\nBad file format\n", 2);
		return (NULL);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(name);
		return (NULL);
	}
	map = read_map(fd);
	if (!map || !check_symbols(map))
	{
		ft_free_tab(map);
		return (NULL);
	}
	return (map);
}
