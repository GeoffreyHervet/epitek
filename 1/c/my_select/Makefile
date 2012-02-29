##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Wed Jan 26 16:02:26 2011 geoffrey hervet
##

NAME	=	my_select

SRC	=	action/action.c		\
		action/key.c		\
		action/key_spe.c	\
		clear_window.c		\
		display/display_list.c	\
		display/display_item.c	\
		init/init_fd.c		\
		init/init_keys.c	\
		init/init_list.c	\
		init/init_termios.c	\
		init/init_window.c	\
		main.c			\
		move_cursor.c		\
		put_cap.c

LIB	=	libmy_$(shell uname -m)-$(shell uname -s)

LDFLAGS	+=	-L./lib
LDFLAGS	+=	$(DEBUG)
LDFLAGS	+=	$(addprefix -l,$(LIB))

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-pedantic
CFLAGS	+=	-I./lib -I./inc
CFLAGS	+=	$(DEBUG)

SRCS	=	$(addprefix $(PWD)/src/,$(SRC))

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(EXEC) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \t\033[33m$(CFLAGS)\n"
		@printf "\033[00mLinkage with flags : \t\t\033[33m$(LDFLAGS) \033[31m\n"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\033[32mSucces !\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m$<\033[31m\n"
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[31m"

dolib:
		@make -C ./lib/my/ re
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
