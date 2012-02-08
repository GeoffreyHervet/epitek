##
## Makefile for ex_02 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_02
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Sat Jan 07 20:47:09 2012 geoffrey hervet
## Last update Sat Jan 07 20:47:09 2012 geoffrey hervet
##

NAME	=	ex_03

SRCS	=	ex_03.c			\
		new.c			\
		point.c			\
		vertex.c

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=gnu99
CFLAGS	+= -g3

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(DEP_MY) $(DEP_CWD) $(DEP_GNL) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\n\033[01;32mSucces !\n\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m%-73s\033[31m" "$<"
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[01;32m%7s\033[00m\n" "Succes!"



clean:
		@printf "~> "
		$(RM) $(OBJ)
		@printf "~> "
		$(FIND) . -name "*#*#" -exec $(RM) {} \;
		@printf "~> "
		$(FIND) . -name "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re dolib



