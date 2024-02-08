/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:45:39 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/13 15:34:34 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *str);
int	ft_putnbr_count(int n);
int	ft_pnbc(unsigned long int n, char *base, int base_len);
int	ft_putptr_count(unsigned long ptr);
#endif
