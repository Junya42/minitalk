/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:23:09 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/16 02:23:13 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/includes/ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
char	*ft_itoa(int n);

typedef struct s_bit
{
	int					size;
	wchar_t				c;
	int					n;
	int					c_pid;
	int					end;
}				t_bit;

#endif
