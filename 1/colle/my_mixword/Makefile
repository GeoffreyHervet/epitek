##
## Makefile for  in /u/all/hervet_g/public/KHOL
##
## Made by tracy nelcha
## Login   <nelcha_t@epitech.net>
##
## Started on  Wed May  4 19:22:06 2011 tracy nelcha
## Last update Wed May  4 22:47:25 2011 tracy nelcha
##

NAME	=	my_mixword

INCLUDE	=	inc

SRCS	=	main.c			\
		read_file.c		\
		putinlist.c		\
		check_arg.c		\
		gnl.c			\
		bbsort.c		\
		sortlist.c

MY	=	my_strlen.c		\
		my_putstr.c		\
		my_strcmp.c

CFLAGS	+=	-Iinc/ -Wall -Wextra -pedantic -ansi -g3

OBJ	=	$(SRC:.c=.o)
SRC	=	$(addprefix src/,$(SRCS))
SRC	+=	$(addprefix src/my/,$(MY))

CC	=	gcc
RM	=	rm -f
FIND	=	find

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(FIND) . \( -name "*~" -o -name ".*.sw*" -o -name "#*#" \) -delete

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

norme	:
		@/u/all/astek/public/norme `$(FIND) .` -nocheat

.PHONY	:	fclean clean all re
