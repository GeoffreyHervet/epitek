##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Sat Nov 13 14:35:25 2010 geoffrey hervet
##

NAME	=	bsq

SRC	=	./src/bsq.c		\
		./src/main.c		\
		./src/gnl.c		\
		./src/calculs.c		\
		./src/display.c

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I./lib -L./lib -lmy

# CFLAGS	+=	-W -Wall -Wchar-subscripts -Werror
# CFLAGS	+=	-W -implicit-function-declaration
# CFLAGS	+=	-Wmissing-prototypes -Wmissing-declarations
# CFLAGS	+=	-Wredundant-decls -Wparentheses -Wreturn-type
# CFLAGS	+=	-Wstrict-prototypes -Wpointer-arith
# CFLAGS	+=	-Wpacked -Waggregate-return -Wcast-qual -Wcast-align
# CFLAGS	+=	-Waggregate-return -Wmissing-noreturn
# CFLAGS	+=	-ansi -pedantic
# CFLAGS	+=	-g3


CC	=	gcc
RM	=	rm -f
FIND	=	find
DEBUG	=	-D DEBUG_STATUT

OBJ	=	$(SRC:.c=.o)

COMPIL	=	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)


all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMPIL)

debug:		$(SRC) $(OBJ)
		$(COMPIL) $(DEBUG)

clean:
		$(RM) $(OBJ)
		$(FIND) . -path "*#*#" -exec $(RM) {} \;
		$(FIND) . -path "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re