/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:08:26 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/09 02:38:41 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabcpy(char **dst, char **src, int total)
{
	int	i;

	i = 0;
	while (dst && src && src[i])
	{
		if (!total)
			dst[i] = src[i];
		else
		{
			dst[i] = ft_strdup(src[i]);
			if (!dst[i])
				break ;
		}
		i++;
	}
	dst[i] = NULL;
}
