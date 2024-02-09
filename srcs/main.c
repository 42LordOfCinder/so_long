/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:32:24 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/09 02:35:37 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nExpected one argument: map.ber\n", 2);
		return (1);
	}
	map = check_map(argv[1]);
	if (map == NULL)
		return (1);
	if (!check_map_path(map))
	{
		ft_putstr_fd("Error\nThe map is not doable\n", 2);
		ft_free_tab(map);
		return (1);
	}
	for (int i = 0; map[i]; i++)
		ft_printf("[%s]\n", map[i]);
	ft_free_tab(map);
	return (0);
}
