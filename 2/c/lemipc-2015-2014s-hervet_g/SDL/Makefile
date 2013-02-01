NAME=		../display

SRC=		main.c display.c

CFLAGS=		-Wall -Wextra -ansi -pedantic
CFLAGS+=	-I../inc
CFLAGS+=	`sdl-config --cflags`

ifdef DEBUG
  CFLAGS+=	-g3 -DDEBUG -DSDL_DEBUG
else
  CFLAGS+=	-Werror
endif

LDFLAGS=	-lSDL_image -lSDL
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
