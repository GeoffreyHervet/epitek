##
## Makefile for  in /u/all/hervet_g/public/ok
## 
## Made by tracy nelcha
## Login   <nelcha_t@epitech.net>
## 
## Started on  Tue May 17 19:21:15 2011 tracy nelcha
## Last update Tue May 17 22:47:03 2011 tracy nelcha
##

NAME	=	cut

CC	=	clang

RM	=	rm -f

SRC	=	option_c.c		\
		option_f.c		\
		my_strcmp.c		\
		apply_optionsdf.c	\
		apply_options.c		\
		main.c			\
		parse_opt_c.c		\
		my_putstr.c		\
		print_error.c		\
		my_strlen.c		\
		my_strdec.c		\
		sort_opt_f.c		\
		parse_opt_f.c		\
		sort_opt_c.c		\
		gnl.c


SRCS	=	$(addprefix src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinc -Wall -Wextra -pedantic -ansi -g3

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

norme	:
		@/u/all/astek/public/norme

all	:	$(NAME)

clean	:
		$(RM) $(OBJ) *~ *#

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	re all fclean clean
