##
## Makefile for lib in /home/hervet_g//work/projets/c/bsq/lib
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov 12 21:55:00 2010 geoffrey hervet
## Last update Sat Nov 27 15:43:09 2010 geoffrey hervet
##

NAME	=	libmy.a

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_cpystr_xtoy.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

RM	=	rm -f
AR	=	ar rc
RANLIB	=	ranlib


$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

all:		$(NAME)

clean:
		 $(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re fclean clean