##
## Makefile for Makefile in /home/caggia_v//rendu/c/project
##
## Made by vincent caggiari
## Login   <caggia_v@epitech.net>
##
## Started on  Thu Dec 23 15:37:50 2010 vincent caggiari
## Last update Sun May  8 16:05:19 2011 vincent caggiari
##

NAME		=	sudoki-bi

SRC		=	bruteforce.c		\
			change_map.c		\
			digit_in_col.c		\
			digit_in_row.c		\
			digit_in_square.c	\
			get_map.c		\
			is_alone.c		\
			main.c			\
			solve.c			\
			update_digit.c		\
			apply_mask.c		\
			show_map.c

CC		=	gcc
RM		=	rm -f
FIND		=	find

SRCS		=	$(addprefix src/,$(SRC))
OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -I./inc/ -g3

$(NAME):		$(OBJS)
			@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
			@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
			@$(CC) -o $(NAME) $^ $(LDFLAGS)
			@printf "\n\033[01;32mSuccess !\n\n\033[00m"

all:			$(NAME)

clean:
			$(RM) $(OBJS)
			$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

%.o:			%.c
			@printf "$<\n\033[031m"
			@$(CC) -o $@ -c $< $(CFLAGS)
			@printf "\033[00m"

norme:
		@/u/all/astek/public/norme `$(FIND) .` -nocheat
.PHONY:		all clean fclean re norme
