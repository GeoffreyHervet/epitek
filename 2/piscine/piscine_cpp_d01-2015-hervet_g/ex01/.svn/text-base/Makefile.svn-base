##
## Makefile for ex01 in /home/hervet_g/piscine/d01/piscine_cpp_d01-2015-hervet_g/ex01
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Wed Jan 04 12:34:44 2012 geoffrey hervet
## Last update Wed Jan 04 12:34:44 2012 geoffrey hervet
##

NAME	=	menger

SRC	=	menger.c	\
		main.c

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-std=gnu99

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
RM	=	rm -f
FIND	=	find

$(NAME):	$(OBJ)
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
		@printf "~> "
		$(RM) $(NAME)

re:		fclean $(NAME)


.PHONY:		all clean fclean re
