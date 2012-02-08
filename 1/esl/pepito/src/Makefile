NAME		=	pepito
LAUNCHER	=	launcher
CC		=	gcc

#CFLAGS		+=	-Wextra -Wall -Werror
CFLAGS		+=	-Wextra -Wall -ggdb -fno-stack-protector
LDFLAGS		=	-z execstack

SRCS		=	main.c utils.c daemon.c network.c
SRCS_LAUNCHER	=	launcher.c

OBJS		=	${SRCS:.c=.o}
OBJS_LAUNCHER	=	${SRCS_LAUNCHER:.c=.o}

${NAME}:	${OBJS}
		${CC} ${OBJS} -o ${NAME} ${LDFLAGS}

${LAUNCHER}:	${OBJS_LAUNCHER}
		${CC} ${OBJS_LAUNCHER} -o ${LAUNCHER}

all:		${NAME} ${LAUNCHER}

clean:
		rm -f ${OBJS} ${OBJS_LAUNCHER}

fclean:		clean
		rm -f ${NAME}
		rm -f ${LAUNCHER}

re:		fclean all

.PHONY:		all clean fclean re
