/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:49:45 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/16 00:50:00 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_convert_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	else
		n = -n;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*ft_norm(long int nl, char *res, int i)
{
	res[i--] = '\0';
	if (nl == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nl < 0)
	{
		res[0] = '-';
		nl = -nl;
	}
	while (nl != 0)
	{
		res[i--] = nl % 10 + '0';
		nl = nl / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	nl;

	nl = (long int)n;
	i = ft_convert_size(n);
	res = (char *)malloc(sizeof(char) * ft_convert_size(n) + 1);
	if (!res)
		return (NULL);
	return (ft_norm(nl, res, i));
}
