##
## Makefile for lib in /home/hervet_g//work/projets/c/bsq/lib
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov 12 21:55:00 2010 geoffrey hervet
## Last update Fri Dec 17 11:17:42 2010 geoffrey hervet
##

NAME	=	libmy_$(shell uname -m)-$(shell uname -s).a

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_strcat.c

PWD_OK	=	$(shell printf $(PWD) | grep "/lib/my")

ifeq ($(PWD_OK),)
  PWD_OK=	$(PWD)/lib/my
endif

ifneq ($(shell ls -d $(PWD_OK) | grep -e "^$(PWD_OK)"), $(PWD_OK))
  $(error The new pwd $(PWD_OK) is bad... ***)
endif

SRCS    =       $(addprefix $(PWD_OK)/,$(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

FIND	=	find
RM	=	rm -f
AR	=	ar rc
RANLIB	=	ranlib

$(NAME):	$(OBJ)
		@printf "~> "
		$(AR) $(PWD_OK)/$(NAME) $(OBJ)
		@printf "~> "
		$(RANLIB) $(PWD_OK)/$(NAME)
		@printf "~> "
		cp $(PWD_OK)/libmy.h $(PWD_OK)/../
		@printf "~> "
		cp $(PWD_OK)/$(NAME) $(PWD_OK)/../

all:		$(NAME)

clean:
		@printf "~> "
		$(RM) $(OBJ)
		@printf "~> "
		$(FIND) . -path "*#*#" -exec $(RM) {} \;
		@printf "~> "
		$(FIND) . -path "*~"   -exec $(RM) {} \;

fclean:		clean
		@printf "~> "
		$(RM) $(PWD_OK)/../$(NAME) $(PWD_OK)/$(NAME)

re:		fclean all

.PHONY:		re fclean clean