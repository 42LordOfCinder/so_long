/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:24:28 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/14 16:22:32 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr_count(va_arg(*args, unsigned long)));
	else if (c == 'd')
		return (ft_putnbr_count(va_arg(*args, int)));
	else if (c == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_pnbc(va_arg(*args, unsigned int), "0123456789", 10));
	else if (c == 'x')
		return (ft_pnbc(va_arg(*args, unsigned int), "0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_pnbc(va_arg(*args, unsigned int), "0123456789ABCDEF", 16));
	else
		return (ft_putchar_count('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars;
	int		i;

	if (format == NULL)
		return (0);
	chars = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			chars += ft_putchar_count(format[i]);
		else
			chars += ft_print_args(format[++i], &args);
		i++;
	}
	va_end(args);
	return (chars);
}
