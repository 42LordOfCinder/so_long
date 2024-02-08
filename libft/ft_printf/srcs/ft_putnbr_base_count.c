/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:15:41 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/13 15:42:31 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_len(unsigned long int n, int size)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= (unsigned long)size)
	{
		len++;
		n /= size;
	}
	return (len + 1);
}

static void	ft_putnbr_base_r(unsigned int long n, unsigned int size, char *base)
{
	int	i;

	i = n % size;
	if (n >= size)
		ft_putnbr_base_r(n / size, size, base);
	write(1, &base[i], 1);
}

int	ft_pnbc(unsigned long int n, char *base, int base_len)
{
	int	len;

	len = ft_count_len(n, base_len);
	if (n < 0)
	{
		ft_putchar_count('-');
		n = -n;
	}
	ft_putnbr_base_r(n, base_len, base);
	return (len);
}
