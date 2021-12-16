/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:23:31 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/16 02:23:32 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_bit g_bit;

void	binary_to_ascii(int bit)
{
	if (bit == 12)
		g_bit.c += g_bit.n;
	if (g_bit.n == 1)
		g_bit.n = 2;
	else
		g_bit.n *= 2;
}

void	get_client(int bit)
{
	binary_to_ascii(bit);
	g_bit.size++;
	if (g_bit.size == 31)
	{
		if (g_bit.c)
		{
			g_bit.c_pid *= 10; 
			g_bit.c_pid += (g_bit.c - 48);
		}
		if (!g_bit.c)
		{
			g_bit.end = 1;
		}
		g_bit.c = 0;
		g_bit.n = 1;
		g_bit.size = 0;
	}
}

void	decrypting(int bit)
{
	binary_to_ascii(bit);
	g_bit.size++;
	if (g_bit.size == 31)
	{
		write(1, &g_bit.c, 1);
		if (!g_bit.c)
		{
			write(1, "\n", 1);
			g_bit.end = 0;
			kill(g_bit.c_pid, SIGUSR2);
			g_bit.c_pid = 0;
		}
		g_bit.c = 0;
		g_bit.n = 1;
		g_bit.size = 0;
	}
}

int	main(void)
{
	int	pid;

	g_bit.c = 0;
	g_bit.n = 1;
	g_bit.size = 0;
	g_bit.c_pid = 0;
	g_bit.end = 0;
	pid = getpid();
	ft_printf("SERVER PID : %d\n", pid);
	while (1)
	{
		while (!g_bit.end)
		{
			signal(SIGUSR2, get_client);
			signal(SIGUSR1, get_client);
			pause();
		}
		while (g_bit.end)
		{
			signal(SIGUSR2, decrypting);
			signal(SIGUSR1, decrypting);
			pause();
		}
	}
}
