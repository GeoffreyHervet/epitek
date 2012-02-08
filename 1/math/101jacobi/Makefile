##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Wed Nov 24 22:09:13 2010 geoffrey hervet
##

NAME	=	101jacobi

SRC	=	./src/main.c		\
		./src/inits.c		\
		./src/calculs.c		\
		./src/error.c		\
		./src/display.c

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-g3
CFLAGS	+=	-I./include

CFLAGS	+=	-I./lib -L./lib -lmy -lm

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRC:.c=.o)

COMPIL	=	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)


all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMPIL)

debug:		$(SRC) $(OBJ)
		$(COMPIL) $(DEBUG)

clean:
		$(RM) $(OBJ)
		$(FIND) . -name "*#*#" -exec $(RM) {} \;
		$(FIND) . -name "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re