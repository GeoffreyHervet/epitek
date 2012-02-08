##
## Makefile for minishell2 in /home/hervet_g/work/unix/minishell2
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Wed Feb 16 10:45:14 2011 geoffrey hervet
## Last update Sat Apr 23 18:31:44 2011 quentin rufin
##

NAME	=	lem-in

##
## For porta : don't use add prefix :(
##

SRC	=	./src/my_func/epurstr.c		\
		./src/my_func/my_getnbr.c	\
		./src/my_func/my_strcmp.c	\
		./src/my_func/my_strncmp.c	\
		./src/my_func/my_strlen.c	\
		./src/my_func/my_strdup.c	\
		./src/my_func/my_putstr.c	\
		./src/my_func/gnl.c		\
		./src/calc_ant_to_send.c	\
		./src/check_error.c		\
		./src/count_arrived_ants.c	\
		./src/create_matrice.c		\
		./src/fill_matrice.c		\
		./src/get_id.c			\
		./src/linetotab.c		\
		./src/main.c			\
		./src/next_line.c		\
		./src/save_item.c		\
		./src/search_ways.c		\
		./src/search_ways_init.c	\
		./src/set_way_list.c		\
		./src/split_ant.c		\
		./src/update_matrice.c		\
		./src/xmalloc.c

CFLAGS	+= 	-W -Wall -Wextra
CFLAGS	+= 	-ansi -pedantic
CFLAGS	+= 	-I./lib -I./inc
CFLAGS	+= 	$(DEBUG)

PRINTF_NAME=	my_printf_$(shell uname -m)-$(shell uname -s)
MY_PRINTF=	./src/my_func/my_printf/lib$(PRINTF_NAME).a

LDFLAGS	=	-L src/my_func/my_printf/ -l$(PRINTF_NAME)

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(MY_PRINTF) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\n\033[01;32mSuccess !\n\n\033[00m"

$(MY_PRINTF):
		@$(MAKE) -C ./src/my_func/my_printf/ PREFIX="./src/my_func/my_printf/"

all:		$(NAME)

%.o:		%.c
		@printf "$<\n"
		@$(CC) -o $@ -c $< $(CFLAGS)

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
		@/u/all/astek/public/norme -nocheat -return -libc `$(FIND) .`

commit:		fclean
		git status
		git add -A
		git commit

.PHONY:		all clean fclean re dolib norme commit