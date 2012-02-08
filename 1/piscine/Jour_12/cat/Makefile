##
## Makefile for Makefile in /home/hervet_g//work/piscine/Jour_10
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Tue Oct 19 15:49:32 2010 geoffrey hervet
## Last update Thu Oct 21 18:18:35 2010 geoffrey hervet
##

NAME=		cat

CC=		cc
RM=		rm -f
LS=		ls -al

SRC=		main.c \
		my_put_nbr.c \
		fonctions.c \
		cat.c
OBJ=		$(SRC:.c=.o)

#CFLAGS+=	-Wall -Wextra -ansi -pedantic -Wstrict-prototypes






$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)




.PHONY:		all clean fclean ls

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(LS)
