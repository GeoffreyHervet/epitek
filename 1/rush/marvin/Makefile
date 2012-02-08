##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Sat Nov 27 14:06:56 2010 geoffrey hervet
##

NAME	=	marvin

SRC	=	./src/main.c		\
		./src/check.c		\
		./src/variable.c	\
		./src/repartition.c	\
		./src/my_put_var.c	\
		./src/write_type.c	

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I./lib -L./lib -lmy -I./include

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