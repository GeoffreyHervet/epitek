##
## Makefile for  in /u/all/hervet_g/public/Pi
##
## Made by tracy nelcha
## Login   <nelcha_t@epitech.net>
##
## Started on  Wed Apr 27 19:12:23 2011 tracy nelcha
## Last update Wed Apr 27 22:40:15 2011 tracy nelcha
##

NAME	=	pi

SRC	=	function_pi/main.c		\
		function_pi/add.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-IInclude -Wall -Wextra -pedantic -ansi

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(SRC)

		@echo -e "Compilation ... [ \033[32mDONE\033[00m ]"

all	:	$(NAME)

clean	:
		@echo -e "*--------*"
		rm -f $(OBJ)
		@echo -e "*--------*"
		rm -f *~ *#
		@echo -e "*--------*"

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	re fclean all clean
