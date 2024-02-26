/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:05:18 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/26 22:06:09 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_png(char *tmp, int i, char *path)
{
	size_t	len;
	int		inc;

	inc = 0;
	if (i >= 10)
		inc++;
	len = ft_strlen(path);
	ft_memcpy(tmp, path, len);
	if (i < 10)
		tmp[len] = (char)(i + 48);
	else
	{
		tmp[len] = (char)(i / 10 + 48);
		tmp[len + 1] = (char)(i % 10 + 48);
	}
	tmp[len + 1 + inc] = '.';
	tmp[len + 2 + inc] = 'p';
	tmp[len + 3 + inc] = 'n';
	tmp[len + 4 + inc] = 'g';
	tmp[len + 5 + inc] = 0;
}

void	load_tab(t_game *g, int i, char *path, void **tab)
{
	int		j;
	char	tmp[100];

	j = 0;
	while (j < i)
	{
		add_png(tmp, j, path);
		tab[j] = mlx_png_file_to_image(g->mlx, tmp, NULL, NULL);
		j++;
	}
}

void	destroy_tab(t_game *g, int i, void **tab)
{
	int	j;

	j = 0;
	while (j < i)
	{
		mlx_destroy_image(g->mlx, tab[j]);
		j++;
	}
}
