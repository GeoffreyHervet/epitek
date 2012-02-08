##
## Makefile for Makefile in /home/poigna_s//tek0/malloc
##
## Made by sarah poignant
## Login   <poigna_s@epitech.net>
##
## Started on  Fri Jan 27 15:21:31 2012 sarah poignant
## Last update Fri Jan 27 15:21:33 2012 sarah poignant
##

NAME		=	libmy_malloc_$(HOSTTYPE).so

CC		=	gcc
CC		=	clang
RM		=	rm -f
LN		=	ln -fs
FIND		=	find
STAT		=	stat
PERCENT		=	./.percent.sh

SRCDIR		=	src
INCDIR		=	inc

CFLAGS		+=	-Wall -W -Werror -pedantic -ansi -D_GNU_SOURCE $(LDINC)
CFLAGS		+=	-I $(INCDIR)
CFLAGS		+=	-fPIC
CFLAGS		+=	-g3
LDFLAGS		+=	-shared

SRC		=	malloc.c	\
			block_init.c	\
			free.c		\
			calloc.c	\
			realloc.c	\
			show_alloc_mem.c

SRCS		=	$(addprefix $(SRCDIR)/,$(SRC))

OBJS		=	$(SRCS:.c=.o)

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ASCII_ART	= @cat .make_msg 2>/dev/null

$(NAME):	$(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		@printf "\033[00m"
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
		@$(LN) $(NAME) libmy_malloc.so
		$(ASCII_ART)

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m[%02d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS) 2>/dev/null`
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object directory cleaning !"

fclean:		clean
		@$(RM) $(NAME) libmy_malloc.so
		@echo "$(NAME) deleted !"

re:		fclean all

norme:
		@echo "##### - Moulinorme is comming O_o - #####"
		@/u/all/hervet_g/public/.n -nocheat `find .`

.PHONY:		all clean fclean re ASCII_ART norme
