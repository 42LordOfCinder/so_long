/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 05:14:07 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/09 15:37:20 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_element_tab(char **tab, char *str)
{
	int		len;
	char	**res;

	len = ft_tablen(tab);
	res = malloc(sizeof(char *) * (len + 2));
	if (res == NULL)
		return (NULL);
	ft_tabcpy(res, tab, 0);
	if (tab)
		free(tab);
	res[len] = str;
	res[len + 1] = NULL;
	return (res);
}
