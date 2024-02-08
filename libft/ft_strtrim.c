/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:02:33 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 03:50:38 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	res = malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
