/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gmassoni@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:05:51 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 21:49:00 by gmassoni         ###   ########.fr       */
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

t_vec	addvec(t_vec vec1, t_vec vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return (vec1);
}

void	vec_tab_cpy(t_vec *dest, t_vec *src, int len)
{
	int	i;

	i = 0;
	while (src && dest && i < len)
	{
		dest[i] = vecnew(src[i].x, src[i].y);
		i++;
	}
}

t_vec	*add_coords(t_vec *dejavu, t_vec coords, int depth)
{
	t_vec	*res;

	res = ft_calloc(depth + 1, sizeof(t_vec));
	vec_tab_cpy(res, dejavu, depth);
	if (dejavu)
		free(dejavu);
	if (res)
		res[depth] = vecnew(coords.x, coords.y);
	return (res);
}
