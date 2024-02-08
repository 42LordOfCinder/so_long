/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:55:47 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/01 17:05:12 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_len_fix;
	size_t	i;

	i = 0;
	if (size == 0 && dst == NULL)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst_len_fix = dst_len;
	if (dst_len > size)
		return (size + src_len);
	while (src[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = 0;
	return (dst_len_fix + src_len);
}
