##
## Makefile for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Wed Jan 04 12:34:44 2012 geoffrey hervet
## Last update Wed Jan 04 12:34:44 2012 geoffrey hervet
##

NAME	=	menger_face

SRC	=	menger.c	\
		main.c		\
		bitmap_header.c	\
		drawing.c

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-std=gnu99

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
RM	=	rm -f
FIND	=	find

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

%.o:		%.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(FIND) . -name "*#*#" -exec $(RM) {} \;
		$(FIND) . -name "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)


.PHONY:		all clean fclean re
