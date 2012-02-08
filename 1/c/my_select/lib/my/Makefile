##
## Makefile for lib in /home/hervet_g//work/lib/my
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov 12 21:55:00 2010 geoffrey hervet
## Last update Mon Jan 24 20:42:57 2011 geoffrey hervet
##

NAME	=	libmy_$(shell uname -m)-$(shell uname -s).a

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_strcat.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_errno_aff.c		\
		my_strdup.c		\
		my_memset.c		\
		my_explode.c		\
		my_strncpy.c		\
		my_free_wordtab.c

PWD_OK	=	.

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

FIND	=	find
RM	=	rm -f
AR	=	ar rc
RANLIB	=	ranlib

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)
		cp $(PWD_OK)/libmy.h $(PWD_OK)/../
		cp $(PWD_OK)/$(NAME) $(PWD_OK)/../

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(FIND) . -path "*#*#" -exec $(RM) {} \;
		$(FIND) . -path "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(PWD_OK)/../$(NAME) $(PWD_OK)/$(NAME)

re:		fclean all

.PHONY:		re fclean clean