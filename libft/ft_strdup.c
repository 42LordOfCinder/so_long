/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:45:09 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/01 16:01:28 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		s_len;

	s_len = ft_strlen(s);
	dst = (char *)malloc((s_len) + 1 * sizeof(char));
	if (dst == NULL)
		return (dst);
	ft_memcpy(dst, s, s_len);
	dst[s_len] = 0;
	return (dst);
}
