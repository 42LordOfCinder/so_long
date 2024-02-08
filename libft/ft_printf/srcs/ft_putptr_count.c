/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:50:06 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/13 14:54:09 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_count(unsigned long ptr)
{
	int	chars;

	if (ptr)
	{
		chars = ft_putstr_count("0x");
		chars += ft_pnbc(ptr, "0123456789abcdef", 16);
		return (chars);
	}
	else
	{
		ft_putstr_count("(nil)");
		return (5);
	}
}
