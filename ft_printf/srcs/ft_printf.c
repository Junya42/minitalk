/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:33:20 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/17 05:38:20 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_fmt(const char *format, va_list args)
{
	if (format[0] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format[0] == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format[0] == 'p')
		return (ft_returnaddress(va_arg(args, unsigned long int), 'x'));
	if (format[0] == 'd')
		return (ft_putnbrsize(va_arg(args, int)));
	if (format[0] == 'i')
		return (ft_putnbrsize(va_arg(args, int)));
	if (format[0] == 'u')
		return (ft_putunbrsize(va_arg(args, unsigned int)));
	if (format[0] == 'x' || format[0] == 'X')
		return (ft_returnputx(va_arg(args, unsigned int), format[0]));
	if (format[0] == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			j++;
		}
		else
			if (format[i + 1])
				j += do_fmt(&format[++i], args);
		i++;
	}
	if (format[i - 1] == '%' && format[i - 2] != '%')
		j += ft_putchar('%');
	va_end(args);
	return (j);
}
