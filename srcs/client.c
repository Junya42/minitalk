/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:23:23 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/16 02:23:24 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	pong(int bit)
{
	(void)bit;
}

void	encrypting(int pid, unsigned char *msg, int len)
{
	int			i;
	int	decalage;

	i = 0;
	while (i <= len)
	{
		decalage = 0;
		while (decalage < 31)
		{
			if ((msg[i] >> decalage) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			decalage++;
			usleep(50);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		s_pid;
	char	*pid;

	if (ac != 3)
		return (ft_printf("Error\nUsage : ./client [PID] \"string\"\n"));
	s_pid = ft_atoi(av[1]);
	if (s_pid > 4194304)
		return (ft_printf("Error\nInvalid PID\n"));
	pid = ft_itoa(getpid());
	encrypting(s_pid, (unsigned char *)pid, ft_strlen(pid));
	usleep(50);
	encrypting(s_pid, (unsigned char *)av[2], ft_strlen(av[2]));
	pause();
	free(pid);
	return (0);
}
