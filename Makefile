# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polpi <polpi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 11:39:00 by polpi             #+#    #+#              #
#    Updated: 2023/04/03 20:48:05 by polpi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= 	$(wildcard *.c) \
			$(wildcard */*.c)
OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc -g3 -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -D_GNU_SOURCE -I/opt/homebrew/opt/readline/include
LDFLAGS = -L/opt/homebrew/opt/readline/lib
RD_REPLACE = -L /opt/homebrew/Cellar/readline/8.2.1/lib -I /opt/homebrew/Cellar/readline/8.2.1/include
RM		= rm -f

NAME	= minishell

all:	libft ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJECTS}
		@${MAKE} -C libft all
		${CC} ${CFLAGS} -lreadline -o $@ $^ -L./libft -lft ${RD_REPLACE}

libft:
		make -C libft

clean:
		make clean -C libft
		${RM} ${OBJECTS}

fclean:		clean
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

.PHONY:	libft all bonus clean fclean re