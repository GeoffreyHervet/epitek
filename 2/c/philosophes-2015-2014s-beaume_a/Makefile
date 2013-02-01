NAME=		philo

SRC=		src/main.c \
		src/philosophe.c \
		src/graphic.c \
		src/init_tgraphics.c

CFLAGS=		-Wall -Wextra -ansi -pedantic
CFLAGS+=	-I./include/
CFLAGS+=	`sdl-config --cflags`

ifdef DEBUG
  CFLAGS+=	-g3 -DDEBUG -DSDL_DEBUG
else
  CFLAGS+=	-Werror
endif

LDFLAGS=	-lpthread -lSDL_image
LDFLAGS+=	`sdl-config --libs`

CC=		gcc

OBJ=		$(SRC:.c=.o)

RM=		rm -vf
CP=		cp -vf

all:   		$(NAME)

$(NAME):  	$(OBJ)
		$(CC) $^ -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
