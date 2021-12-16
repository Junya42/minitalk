# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 02:24:11 by anremiki          #+#    #+#              #
#    Updated: 2021/12/16 02:24:12 by anremiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= srcs/client.c

SERVER		= srcs/server.c

UTILS		= srcs/utils.c	\
			  srcs/utilsbis.c

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= client

NAME2 		= server

PRINTFLIB	= ./ft_printf/libftprintf.a

CC 			= gcc

all:		$(NAME)

$(NAME):
					make -C ./ft_printf
					${CC} ${CFLAGS} -g ${CLIENT} ${UTILS} ${PRINTFLIB} -o ${NAME}
					${CC} ${CFLAGS} -g ${SERVER} ${PRINTFLIB} -o ${NAME2}

clean:
			make clean -C ./ft_printf
					${RM} ${NAME}
					${RM} ${NAME2}

fclean:		clean
			make fclean -C ./ft_printf

re:			fclean all
					
.PHONY: all clean fclean re bonus
