##
## Makefile for Makefile in /home/poigna_s//tek0/malloc
##
## Made by sarah poignant
## Login   <poigna_s@epitech.net>
##
## Started on  Fri Jan 27 15:21:31 2012 sarah poignant
## Last update Fri Jan 27 15:21:33 2012 sarah poignant
##

NAME		=	lemipc

CC		=	gcc
RM		=	rm -f
FIND		=	find
STAT		=	stat
PERCENT		=	./.percent.sh

SRCDIR		=	src
INCDIR		=	inc

CFLAGS		+=	-Wall -W -Werror -pedantic -ansi -D_GNU_SOURCE $(LDINC)
CFLAGS		+=	-I $(INCDIR)
#CFLAGS		+=	-I $(INCDIR)/game
CFLAGS		+=	-g3

SRC		=	main.c	\
			sem.c

SRC_GAME	=	alive.c			\
			exit.c			\
			get_team.c		\
			init.c			\
			is_last.c 		\
			move.c			\
			run.c			\
			team_alone.c		\
			try_mv_adjacent.c	\
			try_mv_corner.c

SRC		+=	$(addprefix game/,$(SRC_GAME))
SRCS		=	$(addprefix $(SRCDIR)/,$(SRC))
OBJS		=	$(SRCS:.c=.o)

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ASCII_ART	= @cat .make_msg 2>/dev/null

all:		$(NAME) display

$(NAME):	$(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		@printf "\033[00m"
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
		$(ASCII_ART)

display:
		@printf "\033[00m"
		@make -C ./SDL

%.o:		%.c
		@printf "\033[00m[%02d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS) 2>/dev/null`
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@printf "\033[00m"
		@make -C ./SDL clean
		@$(RM) $(OBJS)
		@echo "Object directory cleaning !"

fclean:		clean
		@$(RM) $(NAME) libmy_malloc.so
		@printf "\033[00m"
		@make -C ./SDL fclean
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re 
