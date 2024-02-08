/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:32:26 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/04 16:40:15 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_char(char *str, int i)
{
	int	len;
	int	j;

	len = ft_strlen(str);
	if (!str || i < 0 || i > len)
		return (str);
	j = i;
	while (j < len - 1)
	{
		str[j] = str[j + 1];
		j++;
	}
	str[len - 1] = 0;
	return (str);
}
