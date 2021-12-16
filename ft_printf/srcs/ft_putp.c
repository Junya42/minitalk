/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:53:52 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/17 05:16:04 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_psize(unsigned long int n)
{
	int	i;

	i = 2;
	if (n == 0)
		return (5);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_printaddress(unsigned long int n, char x)
{
	if (n == 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	if (x-- == 'x')
		ft_putstr("0x");
	if (n > 15)
		ft_printaddress(n / 16, x);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + '0');
	else
		ft_putchar((n % 16) + 87);
}

int	ft_returnaddress(unsigned long int n, char x)
{
	ft_printaddress(n, x);
	return (ft_get_psize(n));
}
