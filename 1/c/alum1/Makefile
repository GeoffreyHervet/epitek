##
## Makefile for  in /home/hervet_g//work/projets/alum1
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Mon Jan 31 13:41:44 2011 geoffrey hervet
## Last update Fri Feb 11 21:41:36 2011 geoffrey hervet
##


NAME	=	alum1

SRC     =       main.c          \
		action1.c	\
		action2.c	\
		aff_map.c	\
		init_game.c     \
		init_term.c     \
		force.c		\
		play.c          \
		play_player.c	\
		play_computer.c	\
		putcap.c

LIB_MY	=	my_$(shell uname -m)-$(shell uname -s)

LIB	=	$(LIB_MY) curses

ifeq ($(shell ls ./lib/lib$(LIB_MY).a | grep -e "^./lib"),)
  EXEC	=	dolib
else
  EXEC	=
endif

LDFLAGS	+= -L./lib
LDFLAGS	+= $(DEBUG)
LDFLAGS	+= $(addprefix -l,$(LIB))

CFLAGS	+= $(DEBUG)
CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -pedantic
CFLAGS	+= -I./lib -I./inc

SRCS	=	$(addprefix ./src/,$(SRC))

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(EXEC) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\n\033[01;32mSucces !\n\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m%-73s\033[31m" "$<"
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[01;32m%7s\033[31m\n" "Succes!"

dolib:
		@$(MAKE) -C ./lib/my/
		@printf "\t\t*** Lib is compiled ***\n"

clean:
		@printf "~> "
		$(RM) $(OBJ)
		@printf "~> "
		$(FIND) . -name "*#*#" -exec $(RM) {} \;
		@printf "~> "
		$(FIND) . -name "*~"   -exec $(RM) {} \;

fclean:		clean
		@printf "~> "
		$(RM) $(NAME)

re:		fclean $(NAME)

norme:
		@printf "\t\t*** O_o The moulinorme is comming ***\n"
		@/u/all/astek/public/norme `$(FIND) .`

.PHONY:		all clean fclean re dolib norme
