/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:31:54 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/08 03:07:52 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_calloc1(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}

static char	*ft_strjoin1(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	free(s1);
	return (res);
}

static int	ft_check_line(char *buffer, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buffer[j] = line[i];
			i++;
			j++;
		}
		buffer[j] = 0;
		line[i - j] = 0;
		return (1);
	}
	return (0);
}

char	*ft_handle_read_0(char *buffer, char *line)
{
	free(buffer);
	buffer = NULL;
	if (line[0] != 0)
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			chars;

	line = ft_calloc1(1, 1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc1(BUFFER_SIZE + 1, 1);
	while (buffer[fd] && line)
	{
		line = ft_strjoin1(line, buffer[fd]);
		if (ft_check_line(buffer[fd], line))
			return (line);
		chars = read(fd, buffer[fd], BUFFER_SIZE);
		if (chars <= 0)
			return (ft_handle_read_0(buffer[fd], line));
		buffer[fd][chars] = 0;
	}
	return (NULL);
}
