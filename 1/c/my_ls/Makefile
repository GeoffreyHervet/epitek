##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Sat Dec 18 15:12:23 2010 geoffrey hervet
##

NAME	=	my_ls

SRC	=	main.c		\
		init_infos.c	\
		dir_gestion.c	\
		dir_list.c	\
		is_flag.c	\
		list_sort.c

LIB_MY	=	my_$(shell uname -m)-$(shell uname -s)

LIB	=	$(LIB_MY)

ifeq ($(shell ls ./lib/lib$(LIB_MY).a | grep -e "^./lib"),)
  EXEC	=	dolib
else
  EXEC	=
endif


CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I./lib -I./inc -L./lib

CFLAGS	+=	$(addprefix -l,$(LIB))
SRCS	=	$(addprefix $(PWD)/src/,$(SRC))

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(EXEC) $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all:		$(NAME)

dolib:
		@make -C ./lib/my/
		@printf "*** Lib is compiled ***\n"
clean:
		@printf "~> "
		$(RM) $(OBJ)
		@printf "~> "
		$(FIND) . -path "*#*#" -exec $(RM) {} \;
		@printf "~> "
		$(FIND) . -path "*~"   -exec $(RM) {} \;

fclean:		clean
		@printf "~> "
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re dolib