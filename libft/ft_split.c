/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:42:04 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/02 17:58:35 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0)
				words++;
			else if (s[i - 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

static char	*ft_n_word(int n, char const *s, char c)
{
	int		i;
	int		words;
	int		len;
	char	*word;

	i = -1;
	words = 0;
	while ((s[++i] && words < n + 1) || (s[i] == c && i == 0 && n == 0))
		if (s[i] != c && ((i != 0 && s[i - 1] == c) || i == 0))
			words++;
	i -= 1;
	len = i;
	while (s[len] != c && s[len])
		len++;
	len -= i;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	*word = 0;
	ft_strlcpy(word, s + i, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = ft_n_word(i, s, c);
		i++;
	}
	res[i] = 0;
	return (res);
}
