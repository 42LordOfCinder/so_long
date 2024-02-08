/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:05:21 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/02 16:21:52 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;
	int		i;
	long	nb;

	nb = (long)n;
	len = ft_get_len(nb);
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		a[i] = '-';
		nb = -nb;
		i++;
		len--;
	}
	while (len-- > 0)
	{
		a[i++] = (nb / (ft_recursive_power(10, len))) + '0';
		nb = nb % ft_recursive_power(10, len);
	}
	a[i] = 0;
	return (a);
}
