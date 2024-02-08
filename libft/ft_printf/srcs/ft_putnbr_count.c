/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:40:42 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/13 16:45:50 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

static void	ft_putnbr_rec(int n)
{
	char	i;

	i = n % 10 + 48;
	if (n >= 10)
		ft_putnbr_rec(n / 10);
	write(1, &i, 1);
}

int	ft_putnbr_count(int n)
{
	int	len;

	len = ft_count_len(n);
	if (n == -2147483648)
		return (ft_putstr_count("-2147483648"));
	if (n < 0)
	{
		ft_putchar_count('-');
		n = -n;
	}
	ft_putnbr_rec(n);
	return (len);
}
